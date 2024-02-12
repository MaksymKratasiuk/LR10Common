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
        cout << "Студент записаний в файл." << endl;
    }
    else {
        cout << "Помилка при відкритті файлу." << endl;
    }
}



void readStudent() {
    Student student;
    cout << "Прізвище: ";
    cin.get();
    cin.getline(student.surname, STUDENT_NAME_LENGTH);
    cout << "Ім'я: ";
    cin.getline(student.name, STUDENT_NAME_LENGTH);
    cout << "Група: ";
    cin.getline(student.group, GROUP_NAME_LENGTH);
    strcpy_s(student.english.name, "english");
    strcpy_s(student.math.name, "math");
    strcpy_s(student.ukrainian.name, "ukrainian");
    strcpy_s(student.physics.name, "physics");
    cout << "Оцінка з математики: ";
    cin >> student.math.grade;
    cout << "Оцінка з фізики: ";
    cin >> student.physics.grade;
    cout << "Оцінка з англійської: ";
    cin >> student.english.grade;
    cout << "Оцінка з української: ";
    cin >> student.ukrainian.grade;


    writeStudentToFile(student);
}

