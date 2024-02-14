#pragma once
#include <iostream>
#include <fstream>
#include "sturcture.h"
using namespace std;
void five() {
    ofstream textFile("main.txt",ios :: app);
    ifstream file("students.bin", ios::binary);
    if (file.is_open()) {
        Student student;
        cout << setw(123) << setfill('-') << "-" << setfill(' ') << endl;
        cout << setw(5) << left << "|" << setw(10) << "Прізвище" << setw(5) << "|" << setw(10) << "Ім'я" << " |" << setw(10) << "Група" << setw(5) << "|" << setw(15) << "Математика" <<
            setw(5) << "|" << setw(15) << "Фізика" << setw(5) << "|" << setw(15) << "Англійська" << setw(5) << "|" << setw(15) << "Українська" << setw(5) << "|" << endl;
        textFile << setw(123) << setfill('-') << "-" << setfill(' ') << endl;
        textFile << setw(5) << left << "|" << setw(10) << "Прізвище" << setw(5) << "|" << setw(10) << "Ім'я" << " |" << setw(10) << "Група" << setw(5) << "|" << setw(15) << "Математика" <<
            setw(5) << "|" << setw(15) << "Фізика" << setw(5) << "|" << setw(15) << "Англійська" << setw(5) << "|" << setw(15) << "Українська" << setw(5) << "|" << endl;
        cout << setw(123) << setfill('-') << "-" << setfill(' ') << endl;
        textFile << setw(123) << setfill('-') << "-" << setfill(' ') << endl;

        while (file.read((char*)&student, sizeof(Student))) {
            string studentGroup = student.group;
            bool I = (student.english >= 10 && student.physics >= 10 && student.math >= 6 && student.math < 8);
            bool II = (student.ukrainian >= 6 && student.ukrainian < 8 && student.english >= 6 && student.english < 8 && student.physics >= 8 && student.math < 10);
            bool III = (student.math  >=10 && student.english >=8 &&student.english<10  && student.physics  >= 6 && student.physics<8);
            if (I || II || III) {
                cout << setw(5) << left << "|" << setw(10) << student.surname << setw(5) << "|" << setw(10) << student.name << " |" << setw(10) << student.group << setw(5) << "|" << setw(15) << student.math <<
                    setw(5) << "|" << setw(15) << student.physics << setw(5) << "|" << setw(15) << student.english << setw(5) << "|" << setw(15) << student.ukrainian << setw(5) << "|" << endl;

                cout << setw(123) << setfill('-') << "-" << setfill(' ') << endl;




                textFile << setw(5) << left << "|" << setw(10) << student.surname << setw(5) << "|" << setw(10) << student.name << " |" << setw(10) << student.group << setw(5) << "|" << setw(15) << student.math <<
                    setw(5) << "|" << setw(15) << student.physics << setw(5) << "|" << setw(15) << student.english << setw(5) << "|" << setw(15) << student.ukrainian << setw(5) << "|" << endl;

                textFile << setw(123) << setfill('-') << "-" << setfill(' ') << endl;
            }
        }
    }
    else {
        cout << "Помилка при відкритті файлу." << endl;
        textFile << "Помилка при відкритті файлу." << endl;

    }
    file.close();
}