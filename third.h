#pragma once
#include "iostream"
#include "sturcture.h"
#include "fstream"
using namespace std;



void same_surname(string surname) {
    ofstream output("3.txt", ios::out);
    ifstream file("students.bin", ios::binary);
    if (file.is_open()) {
        Student student;
        int groups = 0;
        string groupList = "";
        while (file.read((char*)&student, sizeof(Student))) {
            if (!(groupList.find(student.group) != string::npos)) {
                groupList += student.group;
                groupList += " ";
                groups++;
            }
        }
        file.close();
        int index = 0;
        int space = groupList.find(' ', index);
        string groupName;
        bool found = false;
        while (index < groupList.length()) {
            groupName = "";
            for (int i = index; i < space; i++) {
                groupName += groupList[i];
            }
            //groupName = groupList.substr(index, space - index);
            output << groupName << endl;
            index = space + 1;
            space = groupList.find(' ', index);
            file.open("students.bin", ios::binary);
            while (file.read((char*)&student, sizeof(Student))) {
                string surname2 = student.surname;
                string studentGroup = student.group;
                if (surname == surname2 && studentGroup == groupName) {
                    found = true;
                    output << "Прізвище: " << student.surname << endl
                        << "Ім'я: " << student.name << endl
                        << "Математика: " << student.math.grade << endl
                        << "Фізика: " << student.physics.grade << endl
                        << "Англійська: " << student.english.grade << endl
                        << "Українська: " << student.ukrainian.grade << endl << endl;
                }
            }
            if (!found) output << "Немає\n";
            file.close();
        }
            file.close();
        
    }
    else {
        cout << "Помилка при відкритті файлу." << endl;
    }
}

