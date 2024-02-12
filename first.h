#pragma once
#include "iostream"
#include "sturcture.h"
#include "fstream"
using namespace std;

double calculateAverage(const Student& student) {
    return (student.math.grade + student.physics.grade + student.english.grade + student.ukrainian.grade) / 4.0;
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

        textFile << "Прізвище: " << smallStudent.surname << endl
            << "Ім'я: " << smallStudent.name << endl
            << "Група: " << smallStudent.group << endl
            << "Математика: " << smallStudent.math.grade << endl
            << "Фізика: " << smallStudent.physics.grade << endl
            << "Англійська: " << smallStudent.english.grade << endl
            << "Українська: " << smallStudent.ukrainian.grade << endl << endl;
        textFile.close();
    }
    else {
        cout << "Помилка при відкритті файлу." << endl;
    }
}