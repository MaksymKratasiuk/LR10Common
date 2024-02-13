#pragma once
#include <iostream>
#include <fstream>
#include "sturcture.h"
using namespace std;
void five() {
    ofstream output("5.txt", ios::out);
    ifstream file("students.bin", ios::binary);
    if (file.is_open()) {
        Student student;
        while (file.read((char*)&student, sizeof(Student))) {
            string studentGroup = student.group;
            bool I = (student.english  == 5 && student.physics  == 5 && student.math  == 3);
            bool II = (student.ukrainian  == 3 && student.english  == 3 && student.physics  == 4);
            bool III = (student.math  == 5 && student.english  == 4 && student.physics  == 3);
            if (I || II || III) {
                output << "Прізвище: " << student.surname << endl
                    << "Ім'я: " << student.name << endl
                    << "Математика: " << student.math  << endl
                    << "Фізика: " << student.physics  << endl
                    << "Англійська: " << student.english  << endl
                    << "Українська: " << student.ukrainian  << endl << endl;
            }
        }
    }
    else {
        cout << "Помилка при відкритті файлу." << endl;
    }
    file.close();
}