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
    cout << "  Name: " << student.math.name <<  endl;
    cout << "  Grade: " << student.math.grade <<  endl;

    cout << "Physics:" <<  endl;
    cout << "  Name: " << student.physics.name <<  endl;
    cout << "  Grade: " << student.physics.grade <<  endl;

    cout << "English:" <<  endl;
    cout << "  Name: " << student.english.name <<  endl;
    cout << "  Grade: " << student.english.grade <<  endl;

    cout << "Ukrainian:" <<  endl;
    cout << "  Name: " << student.ukrainian.name <<  endl;
    cout << "  Grade: " << student.ukrainian.grade <<  endl;
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