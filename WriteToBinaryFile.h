#pragma once
#include <iostream>
#include <fstream>
#include "sturcture.h"
using namespace std;



void writeStudentToFile(const Student& student) {
    ofstream file("students.bin", ios::binary | ios::app);
    if (file.is_open()) {
        file.write((char*)(&student), sizeof(Student));
        file.close();
        cout << "������� ��������� � ����." << endl;
    }
    else {
        cout << "������� ��� ������� �����." << endl;
    }
}



void readStudent() {
    Student student;
    cout << "�������: ";
    cin.get();
    cin.getline(student.surname, STUDENT_NAME_LENGTH);
    cout << "��'�: ";
    cin.getline(student.name, STUDENT_NAME_LENGTH);
    cout << "�����: ";
    cin.getline(student.group, GROUP_NAME_LENGTH);
    strcpy_s(student.english.name, "english");
    strcpy_s(student.math.name, "math");
    strcpy_s(student.ukrainian.name, "ukrainian");
    strcpy_s(student.physics.name, "physics");
    cout << "������ � ����������: ";
    cin >> student.math.grade;
    cout << "������ � ������: ";
    cin >> student.physics.grade;
    cout << "������ � ���������: ";
    cin >> student.english.grade;
    cout << "������ � ���������: ";
    cin >> student.ukrainian.grade;


    writeStudentToFile(student);
}

