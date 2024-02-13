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
    
    cout << "������ � ����������: ";
    cin >> student.math;
    cout << "������ � ������: ";
    cin >> student.physics;
    cout << "������ � ���������: ";
    cin >> student.english;
    cout << "������ � ���������: ";
    cin >> student.ukrainian;


    writeStudentToFile(student);
}

