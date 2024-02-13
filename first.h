#pragma once
#include "iostream"
#include "sturcture.h"
#include "fstream"
using namespace std;

double calculateAverage(const Student& student) {
    return (student.math + student.physics + student.english + student.ukrainian) / 4.0;
}


void smallestAvarage() {

    ifstream file("students.bin", ios::binary);

    if (file.is_open()) {
        Student student, smallStudent;
        double avarage = 0, smallestAverage = 0;
        int count = 0;
        while (file.read((char*)(&student), sizeof(Student))) {

            avarage = calculateAverage(student);
            if (count == 0)
                smallestAverage = avarage;

            else if (smallestAverage > avarage)
            {
                smallestAverage = avarage;
                smallStudent = student;
            }
            count++;
        }
        file.close();

        fstream textFile("1.txt", ios::out);

        textFile << "�������: " << smallStudent.surname << endl
            << "��'�: " << smallStudent.name << endl
            << "�����: " << smallStudent.group << endl
            << "����������: " << smallStudent.math << endl
            << "Գ����: " << smallStudent.physics << endl
            << "���������: " << smallStudent.english << endl
            << "���������: " << smallStudent.ukrainian << endl << endl;
        textFile.close();
    }
    else {
        cout << "������� ��� ������� �����." << endl;
    }
}