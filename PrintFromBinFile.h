#pragma once
#include <iostream>
#include <fstream>
#include "sturcture.h"
using namespace std;

void printStudentData(const Student& student) {
    cout << "Surname: " << student.surname <<  endl;
    cout << "Name: " << student.name <<  endl;
    cout << "Group: " << student.group <<  endl;

    cout << "Math:" << endl;
    cout << "  Grade: " << student.math <<  endl;

    cout << "Physics:" <<  endl;

    cout << "  Grade: " << student.physics <<  endl;

    cout << "English:" <<  endl;

    cout << "  Grade: " << student.english <<  endl;

    cout << "Ukrainian:" <<  endl;

    cout << "  Grade: " << student.ukrainian <<  endl;
}

void readAndPrintBinaryFile(const  string& filename) {
    ifstream file(filename,  ios::binary);

    if (!file.is_open()) {
         cerr << "Error opening file" <<  endl;
        return;
    }

    Student student;

    while (file.read((char*)(&student), sizeof(Student))) {
        printStudentData(student);
         cout <<  endl;
    }

    file.close();
}