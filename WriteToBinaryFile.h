#pragma once
#include <iostream>
#include <fstream>
#include "sturcture.h"
using namespace std;



void writeStudentToFile(const Student& student) {
    ofstream file("students.bin", ios::binary | ios::app);
    ofstream textFile("main.txt", ios::app);
    if (file.is_open()) {
        file.write((char*)(&student), sizeof(Student));
        file.close();
        cout << "������� ��������� � ����." << endl;
        textFile << "������� ��������� � ����." << endl;

    }
    else {
        cout << "������� ��� ������� �����." << endl;
        textFile<< "������� ��� ������� �����." << endl;
    }
    textFile.close();
}



void readStudent() {
    ofstream textFile("main.txt", ios::app);

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
    
    
    textFile << "�������: ";
    textFile << endl << student.surname << endl;
    textFile << "��'�: ";
    textFile << endl << student.name << endl;

    textFile << "�����: ";
    textFile << endl << student.group << endl;

    textFile << "������ � ����������: ";
    textFile << endl << student.math << endl;

    textFile << "������ � ������: ";
    textFile << endl << student.physics << endl;

    textFile << "������ � ���������: ";
    textFile << endl << student.english << endl;

    textFile << "������ � ���������: ";
    textFile << endl << student.ukrainian << endl;


    writeStudentToFile(student);
}

