#pragma once
#include <iostream>
#include <fstream>
#include "sturcture.h"
using namespace std;
void by_group() {
    ofstream textFile("main.txt", ios::app);
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
        while (index < groupList.length()) {
            groupName = "";
            for (int i = index; i < space; i++) {
                groupName += groupList[i];
            }
            textFile << groupName <<" : " << endl;
            cout << groupName << " : " << endl;
            cout << setw(123) << setfill('-') << "-" << setfill(' ') << endl;
            cout << setw(5) << left << "|" << setw(10) << "Прізвище" << setw(5) << "|" << setw(10) << "Ім'я" << " |" << setw(10) << "Група" << setw(5) << "|" << setw(15) << "Математика" <<
                setw(5) << "|" << setw(15) << "Фізика" << setw(5) << "|" << setw(15) << "Англійська" << setw(5) << "|" << setw(15) << "Українська" << setw(5) << "|" << endl;
            textFile << setw(123) << setfill('-') << "-" << setfill(' ') << endl;
            textFile << setw(5) << left << "|" << setw(10) << "Прізвище" << setw(5) << "|" << setw(10) << "Ім'я" << " |" << setw(10) << "Група" << setw(5) << "|" << setw(15) << "Математика" <<
                setw(5) << "|" << setw(15) << "Фізика" << setw(5) << "|" << setw(15) << "Англійська" << setw(5) << "|" << setw(15) << "Українська" << setw(5) << "|" << endl;
            cout << setw(123) << setfill('-') << "-" << setfill(' ') << endl;
            textFile << setw(123) << setfill('-') << "-" << setfill(' ') << endl;
            index = space + 1;
            space = groupList.find(' ', index);
            file.open("students.bin", ios::binary);
            while (file.read((char*)&student, sizeof(Student))) {
                string studentGroup = student.group;
                if (studentGroup == groupName) {
                    cout << setw(5) << left << "|" << setw(10) << student.surname << setw(5) << "|" << setw(10) << student.name << " |" << setw(10) << student.group << setw(5) << "|" << setw(15) << student.math <<
                        setw(5) << "|" << setw(15) << student.physics << setw(5) << "|" << setw(15) << student.english << setw(5) << "|" << setw(15) << student.ukrainian << setw(5) << "|" << endl;

                    cout << setw(123) << setfill('-') << "-" << setfill(' ') << endl;

                    textFile << setw(5) << left << "|" << setw(10) << student.surname << setw(5) << "|" << setw(10) << student.name << " |" << setw(10) << student.group << setw(5) << "|" << setw(15) << student.math <<
                        setw(5) << "|" << setw(15) << student.physics << setw(5) << "|" << setw(15) << student.english << setw(5) << "|" << setw(15) << student.ukrainian << setw(5) << "|" << endl;

                    textFile << setw(123) << setfill('-') << "-" << setfill(' ') << endl;
                }
            }
            file.close();
        }
        file.close();
    }
    else {
        cout << "Помилка при відкритті файлу." << endl;
        textFile << "Помилка при відкритті файлу." << endl;

    }
}