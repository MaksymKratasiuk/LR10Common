#pragma once
#include "iostream"
#include "sturcture.h"
#include "fstream"
using namespace std;



void same_surname(string surname) {
    ofstream output("main.txt", ios::out, ios::app);
    ifstream file("students.bin", ios::binary);
    if (file.is_open()) {
        Student student;
        int groups = 0;
        string groupList = "";
        while (file.read((char*)&student, sizeof(Student))) {
            if (!(groupList.find(student.group) != string::npos)) {
                groupList += student.group;
                groupList += " ";
                groups++;
            }
        }
        file.close();
        int index = 0;
        int space = groupList.find(' ', index);
        string groupName;
        bool found = false;
        
        
        cout << "\n�������� � ��������� ��������:\n";
        output << "\n�������� � ��������� ��������:\n";
        cout << setw(123) << setfill('-') << "-" << setfill(' ') << endl;
        cout << setw(5) << left << "|" << setw(10) << "�������" << setw(5) << "|" << setw(10) << "��'�" << " |" << setw(10) << "�����" << setw(5) << "|" << setw(15) << "����������" <<
            setw(5) << "|" << setw(15) << "Գ����" << setw(5) << "|" << setw(15) << "���������" << setw(5) << "|" << setw(15) << "���������" << setw(5) << "|" << endl;
        output << setw(140) << setfill('-') << "-" << setfill(' ') << endl;
        output << setw(5) << left << "|" << setw(10) << "�������" << setw(5) << "|" << setw(10) << "��'�" << " |" << setw(10) << "�����" << setw(5) << "|" << setw(15) << "����������" <<
            setw(5) << "|" << setw(15) << "Գ����" << setw(5) << "|" << setw(15) << "���������" << setw(5) << "|" << setw(15) << "���������" << setw(5) << "|" << endl;
        cout << setw(123) << setfill('-') << "-" << setfill(' ') << endl;
        output << setw(123) << setfill('-') << "-" << setfill(' ') << endl;
        while (index < groupList.length()) {
            groupName = "";
            for (int i = index; i < space; i++) {
                groupName += groupList[i];
            }
            //groupName = groupList.substr(index, space - index);
            output << groupName << endl;
            index = space + 1;
            space = groupList.find(' ', index);
            file.open("students.bin", ios::binary);
            while (file.read((char*)&student, sizeof(Student))) {
                string surname2 = student.surname;
                string studentGroup = student.group;
                

                if (surname == surname2 && studentGroup == groupName) {
                    found = true;
                    /*output << "�������: " << student.surname << endl
                        << "��'�: " << student.name << endl
                        << "����������: " << student.math << endl
                        << "Գ����: " << student.physics << endl
                        << "���������: " << student.english << endl
                        << "���������: " << student.ukrainian << endl << endl;*/

                   
                    
                   


                    cout << setw(5) << left << "|" << setw(10) << student.surname << setw(5) << "|" << setw(10) << student.name << " |" << setw(10) << student.group << setw(5) << "|" << setw(15) << student.math <<
                        setw(5) << "|" << setw(15) << student.physics << setw(5) << "|" << setw(15) << student.english << setw(5) << "|" << setw(15) << student.ukrainian << setw(5) << "|" << endl;

                    cout << setw(123) << setfill('-') << "-" << setfill(' ') << endl;
                   
                    


                    output << setw(5) << left << "|" << setw(10) << student.surname << setw(5) << "|" << setw(10) << student.name << " |" << setw(10) << student.group << setw(5) << "|" << setw(15) << student.math <<
                        setw(5) << "|" << setw(15) << student.physics << setw(5) << "|" << setw(15) << student.english << setw(5) << "|" << setw(15) << student.ukrainian << setw(5) << "|"  << endl;

                    output << setw(123) << setfill('-') << "-" << setfill(' ') << endl;


                }
            }
            if (!found) output << "����\n";
            file.close();
        }
            file.close();
        
    }
    else {
        cout << "������� ��� ������� �����." << endl;
    }
}

