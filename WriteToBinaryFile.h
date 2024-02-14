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
        cout << "Студент записаний в файл." << endl;
        textFile << "Студент записаний в файл." << endl;

    }
    else {
        cout << "Помилка при відкритті файлу." << endl;
        textFile<< "Помилка при відкритті файлу." << endl;
    }
    textFile.close();
}



void readStudent() {
    ofstream textFile("main.txt", ios::app);

    Student student;
    cout << "Прізвище: ";
    cin.get();
    cin.getline(student.surname, STUDENT_NAME_LENGTH);
    cout << "Ім'я: ";
    cin.getline(student.name, STUDENT_NAME_LENGTH);
    cout << "Група: ";
    cin.getline(student.group, GROUP_NAME_LENGTH);
    
    cout << "Оцінка з математики: ";
    cin >> student.math;
    cout << "Оцінка з фізики: ";
    cin >> student.physics;
    cout << "Оцінка з англійської: ";
    cin >> student.english;
    cout << "Оцінка з української: ";
    cin >> student.ukrainian;
    
    
    textFile << "Прізвище: ";
    textFile << endl << student.surname << endl;
    textFile << "Ім'я: ";
    textFile << endl << student.name << endl;

    textFile << "Група: ";
    textFile << endl << student.group << endl;

    textFile << "Оцінка з математики: ";
    textFile << endl << student.math << endl;

    textFile << "Оцінка з фізики: ";
    textFile << endl << student.physics << endl;

    textFile << "Оцінка з англійської: ";
    textFile << endl << student.english << endl;

    textFile << "Оцінка з української: ";
    textFile << endl << student.ukrainian << endl;


    writeStudentToFile(student);
}

