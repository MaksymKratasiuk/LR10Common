#pragma once
#include <iostream>
#include <fstream>
#include "sturcture.h"
using namespace std;

void printStudentData(const Student& student) {
    ofstream textFile("main.txt", ios::app);
    
    cout << setw(5) << left << "|" << setw(10) << student.surname << setw(5) << "|" << setw(10) << student.name << " |" << setw(10) << student.group << setw(5) << "|" << setw(15) << student.math <<
        setw(5) << "|" << setw(15) << student.physics << setw(5) << "|" << setw(15) << student.english << setw(5) << "|" << setw(15) << student.ukrainian << setw(5) << "|" << endl;

    cout << setw(123) << setfill('-') << "-" << setfill(' ') << endl;




    textFile << setw(5) << left << "|" << setw(10) << student.surname << setw(5) << "|" << setw(10) << student.name << " |" << setw(10) << student.group << setw(5) << "|" << setw(15) << student.math <<
        setw(5) << "|" << setw(15) << student.physics << setw(5) << "|" << setw(15) << student.english << setw(5) << "|" << setw(15) << student.ukrainian << setw(5) << "|" << endl;

    textFile << setw(123) << setfill('-') << "-" << setfill(' ') << endl;
}

void readAndPrintBinaryFile(const  string& filename) {
    ifstream file(filename,  ios::binary);
    ofstream textFile("main.txt", ios::app);
    if (!file.is_open()) {
         cerr << "Error opening file" <<  endl;
        return;
    }

    Student student;
    cout << setw(123) << setfill('-') << "-" << setfill(' ') << endl;
    cout << setw(5) << left << "|" << setw(10) << "Прізвище" << setw(5) << "|" << setw(10) << "Ім'я" << " |" << setw(10) << "Група" << setw(5) << "|" << setw(15) << "Математика" <<
        setw(5) << "|" << setw(15) << "Фізика" << setw(5) << "|" << setw(15) << "Англійська" << setw(5) << "|" << setw(15) << "Українська" << setw(5) << "|" << endl;
    textFile << setw(123) << setfill('-') << "-" << setfill(' ') << endl;
    textFile << setw(5) << left << "|" << setw(10) << "Прізвище" << setw(5) << "|" << setw(10) << "Ім'я" << " |" << setw(10) << "Група" << setw(5) << "|" << setw(15) << "Математика" <<
        setw(5) << "|" << setw(15) << "Фізика" << setw(5) << "|" << setw(15) << "Англійська" << setw(5) << "|" << setw(15) << "Українська" << setw(5) << "|" << endl;
    cout << setw(123) << setfill('-') << "-" << setfill(' ') << endl;
    textFile << setw(123) << setfill('-') << "-" << setfill(' ') << endl;
    while (file.read((char*)(&student), sizeof(Student))) {
        printStudentData(student);
         cout <<  endl;
    }

    file.close();
}