#pragma once
#include "iostream"
#include "sturcture.h"
#include "fstream"
#include "iomanip"
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
        int subjectStats[4] = {0};
        
        //1-матем
        //2 - фізика
        //3 - англ
        //4-укр
       
        while (file.read((char*)(&student), sizeof(Student))) {

            avarage = calculateAverage(student);
            if (count == 0)
                smallestAverage = avarage;

            else if (smallestAverage > avarage)
            {
                smallestAverage = avarage;
                smallStudent = student;
            }
            subjectStats[0] += student.math;
            subjectStats[1] += student.physics;
            subjectStats[2] += student.english;
            subjectStats[3] += student.ukrainian;
            count++;
        }
        file.close();
        
        if (count > 0) {
            double mathAverage = (double)(subjectStats[0]) / count;
            double physicsAverage = (double)(subjectStats[1]) / count;
            double englishAverage = (double)(subjectStats[2]) / count;
            double ukrainianAverage = (double)(subjectStats[3]) / count;

           

            fstream textFile("main.txt", ios::out,ios::app);
            

            cout << "\nСтудент з найменшим середнім балом:\n";
            cout << setw(140) << setfill('-') << "-" << setfill(' ') << endl;
            cout << setw(5) << left << "|" << setw(10) << "Прізвище" << setw(5) << "|" << setw(10) << "Ім'я" << " |" << setw(10) << "Група" << setw(5) << "|" << setw(15) << "Математика" <<
                setw(5) << "|" << setw(15) << "Фізика" << setw(5) << "|" << setw(15) << "Англійська" << setw(5) << "|" << setw(15) << "Українська" << setw(5) << "|" << setw(15) << "Середній бал" << setw(5) << "|"<<endl;
            cout << setw(140) << setfill('-') << "-" << setfill(' ') << endl;


            cout << setw(5) << left << "|" << setw(10) << smallStudent.surname << setw(5) << "|" << setw(10) << smallStudent.name << " |" << setw(10) << smallStudent.group << setw(5) << "|" << setw(15) << smallStudent.math <<
                setw(5) << "|" << setw(15) << smallStudent.physics << setw(5) << "|" << setw(15) << smallStudent.english << setw(5) << "|" << setw(15) << smallStudent.ukrainian << setw(5) << "|" << setw(15);
            ((int)smallestAverage) / 10 == 0 ? cout << setprecision(2) << smallestAverage : cout << setprecision(3) << smallestAverage;
            cout<< setw(5) << "|" << endl;

            cout << setw(140) << setfill('-') << "-" << setfill(' ') << endl;


            textFile << "\nСтудент з найменшим середнім балом:\n";
            textFile << setw(140) << setfill('-') << "-" << setfill(' ') << endl;
            textFile << setw(5) << left << "|" << setw(10) << "Прізвище" << setw(5) << "|" << setw(10) << "Ім'я" << " |" << setw(10) << "Група" << setw(5) << "|" << setw(15) << "Математика" <<
                setw(5) << "|" << setw(15) << "Фізика" << setw(5) << "|" << setw(15) << "Англійська" << setw(5) << "|" << setw(15) << "Українська" << setw(5) << "|" << setw(15) << "Середній бал" << setw(5) << "|" << endl;
            textFile << setw(140) << setfill('-') << "-" << setfill(' ') << endl;


            textFile << setw(5) << left << "|" << setw(10) << smallStudent.surname << setw(5) << "|" << setw(10) << smallStudent.name << " |" << setw(10) << smallStudent.group << setw(5) << "|" << setw(15) << smallStudent.math <<
                setw(5) << "|" << setw(15) << smallStudent.physics << setw(5) << "|" << setw(15) << smallStudent.english << setw(5) << "|" << setw(15) << smallStudent.ukrainian << setw(5) << "|" << setw(15);
            ((int)smallestAverage) / 10 == 0 ? textFile << setprecision(2) << smallestAverage : textFile << setprecision(3) << smallestAverage;
            textFile << setw(5) << "|" << endl;

            textFile << setw(140) << setfill('-') << "-" << setfill(' ') << endl;


            //--------------------------------------------------------------------------------------------
            cout << "\nСередні бали кожного предмета:\n";

            cout << setw(81) << setfill('-') << "-" << setfill(' ') << endl;

            cout << setw(5) << left << "|" <<  setw(15) << "Математика" <<
                setw(5) << "|" << setw(15) << "Фізика" << setw(5) << "|" << setw(15) << "Англійська" << setw(5) << "|" << setw(15) << "Українська" << setw(5) << "|" << endl;
            cout << setw(81) << setfill('-') << "-" << setfill(' ') << endl;

            cout << setw(5) << left << "|" << setw(15); 
            ((int)mathAverage) / 10 == 0 ? cout << setprecision(2) << mathAverage : cout << setprecision(3) << mathAverage;
            cout << setw(5) << "|" << setw(15);
            ((int)physicsAverage) / 10 == 0 ? cout << setprecision(2) << physicsAverage:cout<< setprecision(3) << physicsAverage;
            cout << setw(5) << "|" << setw(15);  
            ((int)englishAverage) / 10 == 0 ? cout << setprecision(2) << englishAverage : cout << setprecision(3) << englishAverage;
            cout << setw(5) << "|" << setw(15);
            ((int)ukrainianAverage) / 10 == 0 ? cout << setprecision(2) << ukrainianAverage : cout << setprecision(3) << ukrainianAverage;
            cout<< setw(5) << "|" << endl;

            cout << setw(81) << setfill('-') << "-" << setfill(' ') << endl;

            textFile << "\nСередні бали кожного предмета:\n";

            textFile << setw(81) << setfill('-') << "-" << setfill(' ') << endl;

            textFile << setw(5) << left << "|" << setw(15) << "Математика" <<
                setw(5) << "|" << setw(15) << "Фізика" << setw(5) << "|" << setw(15) << "Англійська" << setw(5) << "|" << setw(15) << "Українська" << setw(5) << "|" << endl;
            textFile << setw(81) << setfill('-') << "-" << setfill(' ') << endl;

            textFile << setw(5) << left << "|" << setw(15);
            ((int)mathAverage) / 10 == 0 ? textFile << setprecision(2) << mathAverage : textFile << setprecision(3) << mathAverage;
            textFile << setw(5) << "|" << setw(15);
            ((int)physicsAverage) / 10 == 0 ? textFile << setprecision(2) << physicsAverage : textFile << setprecision(3) << physicsAverage;
            textFile << setw(5) << "|" << setw(15);
            ((int)englishAverage) / 10 == 0 ? textFile << setprecision(2) << englishAverage : textFile << setprecision(3) << englishAverage;
            textFile << setw(5) << "|" << setw(15);
            ((int)ukrainianAverage) / 10 == 0 ? textFile << setprecision(2) << ukrainianAverage : textFile << setprecision(3) << ukrainianAverage;
            textFile << setw(5) << "|" << endl;

            textFile << setw(81) << setfill('-') << "-" << setfill(' ') << endl;



            

           

            textFile.close();
        }
    }
    else {
        cout << "Помилка при відкритті файлу." << endl;
    }
}