#pragma once
#include "iostream"
#include "sturcture.h"
#include "fstream"
#include "first.h"
#include "iomanip"
using namespace std;

struct Group {
    char groupName[GROUP_NAME_LENGTH];
    double averageGrade;
};

void bubbleSortByAverageGrade(Group students[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (students[j].averageGrade < students[j + 1].averageGrade) {
                swap(students[j], students[j + 1]);
            }
        }
    }
}


void sort_write() {
    const int maxGroups = 50;
    Group groups[maxGroups];
    int numGroups = 0;
    double avarage = 0;
    ofstream output("main.txt", ios::app);
    ifstream file("temp.bin", ios::binary);
    if (file.is_open()) {
        Group student;
        while (file.read((char*)&student, sizeof(Group))) {

            groups[numGroups++] = student;
        }
        file.close();
    }
    else {
        cout << "error" << endl;
        output << "error" << endl;
        output.close();
        return;
    }

    bubbleSortByAverageGrade(groups, numGroups);

   // ofstream output("main.txt", ios::app);
    if (output.is_open()) {
        output << setw(31) << setfill('-') << "-" << setfill(' ') << endl;
        output << setw(5) << left << "|" << setw(7) << "Група" << setw(5) << "|" << setw(7) << "Середнiй бал" << " |" << endl;
        output << setw(31) << setfill('-') << "-" << setfill(' ') << endl;
        for (int i = 0; i < numGroups; i++) {
            output << setw(5) << left << "|" << setw(7) << groups[i].groupName << setw(7) << "|" << setw(10);
            ((int)groups[i].averageGrade) / 10 == 0 ? output << setprecision(2) << groups[i].averageGrade : output << setprecision(3) << groups[i].averageGrade;
            output<< " |" << endl;
        }
        output << setw(31) << setfill('-') << "-" << setfill(' ') << endl;
    }
    else {
        cout << "error" << endl;
        output << "error" << endl;
        output.close();
        return;
    }
    cout << setw(31) << setfill('-') << "-" << setfill(' ') << endl;
    cout << setw(5) << left << "|" << setw(7) << "Група" << setw(5) << "|" << setw(7) << "Середнiй бал" << " |" << endl;
    cout << setw(31) << setfill('-') << "-" << setfill(' ') << endl;
    for (int i = 0; i < numGroups; i++) {
        cout << setw(5) << left << "|" << setw(7) << groups[i].groupName << setw(7) << "|" << setw(10);
        ((int)groups[i].averageGrade) / 10 == 0 ? cout << setprecision(2) << groups[i].averageGrade : cout << setprecision(3) << groups[i].averageGrade;
        cout << " |" << endl;
    }
    cout << setw(31) << setfill('-') << "-" << setfill(' ') << endl;
    output.close();
    return;
}


void second() {
    ifstream file("students.bin", ios::binary);
    ofstream tempBin("temp.bin", ios::binary);
    ofstream output("main.txt", ios::app);
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
        double avarage = 0, sum = 0;
        Group group;
        int count;
        while (index < groupList.length()) {
            groupName = "";
            count = 0;
            sum = 0;
            groupName = groupList.substr(index, space - index);
           
            index = space + 1;
            space = groupList.find(' ', index);
            file.open("students.bin", ios::binary);
            while (file.read((char*)&student, sizeof(Student))) {
                if (!strcmp(student.group, groupName.c_str())) {
                    count++;
                    sum += calculateAverage(student);
                }

            }
            avarage = sum / count;

            strcpy_s(group.groupName, groupName.c_str());
            group.averageGrade = avarage;
            tempBin.write((char*)(&group), sizeof(Group));
      
            file.close();
        }
        file.close();
        tempBin.close();
        sort_write();

    }
    else {
        cout << "error" << endl;
        output << "error" << endl;
    }
    output.close();

}
