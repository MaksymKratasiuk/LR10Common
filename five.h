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
            bool I = (student.english.grade == 5 && student.physics.grade == 5 && student.math.grade == 3);
            bool II = (student.ukrainian.grade == 3 && student.english.grade == 3 && student.physics.grade == 4);
            bool III = (student.math.grade == 5 && student.english.grade == 4 && student.physics.grade == 3);
            if (I || II || III) {
                output << "Прізвище: " << student.surname << endl
                    << "Ім'я: " << student.name << endl
                    << "Математика: " << student.math.grade << endl
                    << "Фізика: " << student.physics.grade << endl
                    << "Англійська: " << student.english.grade << endl
                    << "Українська: " << student.ukrainian.grade << endl << endl;
            }
        }
    }
    else {
        cout << "Помилка при відкритті файлу." << endl;
    }
    file.close();
}