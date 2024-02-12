#pragma once
#include <iostream>
#include <fstream>
#include "sturcture.h"
using namespace std;
void by_group() {
    ofstream output("6.txt", ios::out);
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
            output << groupName << endl;
            index = space + 1;
            space = groupList.find(' ', index);
            file.open("students.bin", ios::binary);
            while (file.read((char*)&student, sizeof(Student))) {
                string studentGroup = student.group;
                if (studentGroup == groupName) {
                    output << "�������: " << student.surname << endl
                        << "��'�: " << student.name << endl
                        << "����������: " << student.math.grade << endl
                        << "Գ����: " << student.physics.grade << endl
                        << "���������: " << student.english.grade << endl
                        << "���������: " << student.ukrainian.grade << endl << endl;
                }
            }
            file.close();
        }
        file.close();
    }
    else {
        cout << "������� ��� ������� �����." << endl;
    }
}