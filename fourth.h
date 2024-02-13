#include "iostream"
#include "sturcture.h"
#include "fstream"
#include"string"
using namespace std;

bool five(int num){return num >= 10;}
bool four(int num) {return num >= 8 && num < 10;}
bool three(int num) {return num >= 6 && num < 8;}

void outputStudentInfo(const Student& student,fstream& outputFile) {
    outputFile << "Прізвище: " << student.surname << endl
        << "Ім'я: " << student.name << endl
        << "Група: " << student.group << endl
        << "Математика: " << student.math << endl
        << "Фізика: " << student.physics << endl
        << "Англійська: " << student.english << endl
        << "Українська: " << student.ukrainian << endl << endl;
}





void fourth() {
    int k;
    
    char subject1[SUBJECT_NAME_LENGTH], subject2[SUBJECT_NAME_LENGTH], subject3[SUBJECT_NAME_LENGTH], subject4[SUBJECT_NAME_LENGTH];
    cout << "Виберіть дію:" << endl;
    cout << "1: Вивести студентів, які мають 5 та 4 з двох вибраних предметів" << endl;
    cout << "2: Вивести студентів, які мають 4 та 3 з трьох вибраних предметів" << endl;
    cout << "3: Вивести студентів, які мають 5 та 3 з чотирьох вибраних предметів" << endl;
    cin >> k;
    
    ifstream file;
    fstream textFile;
   
    switch (k) {
    case 1:
        cout << "Введіть назву першого предмета-> ";
        cin.get();
        cin.getline(subject1, SUBJECT_NAME_LENGTH);
        cout << "Введіть назву другого предмета-> ";
        cin.getline(subject2, SUBJECT_NAME_LENGTH);

        file.open("students.bin", ios::binary);
        textFile.open("4.txt", ios::out);

        if (file.is_open() && textFile.is_open()) {
            Student student;
            bool subject1Bool = false, subject2Bool = false;


            while (file.read((char*)(&student), sizeof(Student))) {
                subject1Bool = false;
                subject2Bool = false;
                if (strcmp(subject1, "math")==0) {
                    if (five(student.math) || four(student.math)) {
                        subject1Bool = true;
                    }
                }
                else if (strcmp(subject1, "physics") == 0) {
                    if (five(student.physics) || four(student.physics)) {
                        subject1Bool = true;
                    }
                }
                else if (strcmp(subject1, "english") == 0) {
                    if (five(student.english) || four(student.english)) {
                        subject1Bool = true;
                    }
                }
                else if (strcmp(subject1, "ukrainian") == 0) {
                    if (five(student.ukrainian) || four(student.ukrainian)) {
                        subject1Bool = true;
                    }
                }
                //-----------------------
                if (strcmp(subject2, "math") == 0) {
                    if (five(student.math) || four(student.math)) {
                        subject2Bool = true;
                    }
                }
                else if (strcmp(subject2, "physics") == 0) {
                    if (five(student.physics) || four(student.physics)) {
                        subject2Bool = true;
                    }
                }
                else if (strcmp(subject2, "english") == 0) {
                    if (five(student.english ) || four(student.english )) {
                        subject2Bool = true;
                    }
                }
                else if (strcmp(subject2, "ukrainian") == 0) {
                    if (five(student.ukrainian ) || four(student.ukrainian )) {
                        subject2Bool = true;
                    }
                }

                if (subject1Bool && subject2Bool) {
                    
                    outputStudentInfo(student, textFile);
                    
                }

            }
            file.close();
            textFile.close();

         
        }
        else {
            cout << "Помилка при відкритті файлу." << endl;
        }
        break;
    case 2:
        cout << "Введіть назву першого предмета-> ";
        cin.get();
        cin.getline(subject1, SUBJECT_NAME_LENGTH);
        cout << "Введіть назву другого предмета-> ";
        cin.getline(subject2, SUBJECT_NAME_LENGTH);
        cout << "Введіть назву третього предмета-> ";
        cin.getline(subject3, SUBJECT_NAME_LENGTH);


        file.open("students.bin", ios::binary);
        textFile.open("4.txt", ios::out);

        if (file.is_open() && textFile.is_open()) {
            Student student;
         
            bool subject1Bool = false, subject2Bool = false,subject3Bool = false;
        

            while (file.read((char*)(&student), sizeof(Student))) {
                subject1Bool = false;
                subject2Bool = false;
                subject3Bool = false;
                if (strcmp(subject1, "math") == 0) {
                    if (three(student.math ) || four(student.math )) {
                        subject1Bool = true;
                    }
                }
                else if (strcmp(subject1, "physics") == 0) {
                    if (three(student.physics ) || four(student.physics )) {
                        subject1Bool = true;
                    }
                }
                else if (strcmp(subject1, "english") == 0) {
                    if (three(student.english ) || four(student.english )) {
                        subject1Bool = true;
                    }
                }
                else if (strcmp(subject1, "ukrainian") == 0) {
                    if (three(student.ukrainian ) || four(student.ukrainian )) {
                        subject1Bool = true;
                    }
                }
                //-----------------------
                if (strcmp(subject2, "math") == 0) {
                    if (three(student.math ) || four(student.math )) {
                        subject2Bool = true;
                    }
                }
                else if (strcmp(subject2, "physics") == 0) {
                    if (three(student.physics ) || four(student.physics )) {
                        subject2Bool = true;
                    }
                }
                else if (strcmp(subject2, "english") == 0) {
                    if (three(student.english ) || four(student.english )) {
                        subject2Bool = true;
                    }
                }
                else if (strcmp(subject2, "ukrainian") == 0) {
                    if (three(student.ukrainian ) || four(student.ukrainian )) {
                        subject2Bool = true;
                    }
                }

                //-----------------------
                if (strcmp(subject3, "math") == 0) {
                    if (three(student.math ) || four(student.math )) {
                        subject3Bool = true;
                    }
                }
                else if (strcmp(subject3, "physics") == 0) {
                    if (three(student.physics ) || four(student.physics )) {
                        subject3Bool = true;
                    }
                }
                else if (strcmp(subject3, "english") == 0) {
                    if (three(student.english ) || four(student.english )) {
                        subject3Bool = true;
                    }
                }
                else if (strcmp(subject3, "ukrainian") == 0) {
                    if (three(student.ukrainian ) || four(student.ukrainian )) {
                        subject3Bool = true;
                    }
                }



                if (subject1Bool && subject2Bool && subject3Bool) {


                    outputStudentInfo(student, textFile);

                }

            }
            file.close();
            textFile.close();


        }
        else {
            cout << "Помилка при відкритті файлу." << endl;
        }

        break;
    

        case 3:
            cout << "Введіть назву першого предмета-> ";
            cin.get();
            cin.getline(subject1, SUBJECT_NAME_LENGTH);
            cout << "Введіть назву другого предмета-> ";
            cin.getline(subject2, SUBJECT_NAME_LENGTH);
            cout << "Введіть назву третього предмета-> ";
            cin.getline(subject3, SUBJECT_NAME_LENGTH);
            cout << "Введіть назву четвертого предмета-> ";
            cin.getline(subject4, SUBJECT_NAME_LENGTH);


            file.open("students.bin", ios::binary);
            textFile.open("4.txt", ios::out);

            if (file.is_open() && textFile.is_open()) {
                Student student;

                bool subject1Bool = false, subject2Bool = false, subject3Bool = false,subject4Bool=false;


                while (file.read((char*)(&student), sizeof(Student))) {
                    subject1Bool = false;
                    subject2Bool = false;
                    subject3Bool = false;
                    if (strcmp(subject1, "math") == 0) {
                        if (three(student.math ) || five(student.math )) {
                            subject1Bool = true;
                        }
                    }
                    else if (strcmp(subject1, "physics") == 0) {
                        if (three(student.physics ) || five(student.physics )) {
                            subject1Bool = true;
                        }
                    }
                    else if (strcmp(subject1, "english") == 0) {
                        if (three(student.english ) || five(student.english )) {
                            subject1Bool = true;
                        }
                    }
                    else if (strcmp(subject1, "ukrainian") == 0) {
                        if (three(student.ukrainian ) || five(student.ukrainian )) {
                            subject1Bool = true;
                        }
                    }
                    //-----------------------
                    if (strcmp(subject2, "math") == 0) {
                        if (three(student.math ) || five(student.math )) {
                            subject2Bool = true;
                        }
                    }
                    else if (strcmp(subject2, "physics") == 0) {
                        if (three(student.physics ) || five(student.physics )) {
                            subject2Bool = true;
                        }
                    }
                    else if (strcmp(subject2, "english") == 0) {
                        if (three(student.english ) || five(student.english )) {
                            subject2Bool = true;
                        }
                    }
                    else if (strcmp(subject2, "ukrainian") == 0) {
                        if (three(student.ukrainian ) || five(student.ukrainian )) {
                            subject2Bool = true;
                        }
                    }

                    //-----------------------
                    if (strcmp(subject3, "math") == 0) {
                        if (three(student.math ) || five(student.math )) {
                            subject3Bool = true;
                        }
                    }
                    else if (strcmp(subject3, "physics") == 0) {
                        if (three(student.physics ) || five(student.physics )) {
                            subject3Bool = true;
                        }
                    }
                    else if (strcmp(subject3, "english") == 0) {
                        if (three(student.english ) || five(student.english )) {
                            subject3Bool = true;
                        }
                    }
                    else if (strcmp(subject3, "ukrainian") == 0) {
                        if (three(student.ukrainian ) || five(student.ukrainian )) {
                            subject3Bool = true;
                        }
                    }

                    //-----------------------
                    if (strcmp(subject4, "math") == 0) {
                        if (three(student.math ) || five(student.math )) {
                            subject4Bool = true;
                        }
                    }
                    else if (strcmp(subject4, "physics") == 0) {
                        if (three(student.physics ) || five(student.physics )) {
                            subject4Bool = true;
                        }
                    }
                    else if (strcmp(subject4, "english") == 0) {
                        if (three(student.english ) || five(student.english )) {
                            subject4Bool = true;
                        }
                    }
                    else if (strcmp(subject4, "ukrainian") == 0) {
                        if (three(student.ukrainian ) || five(student.ukrainian )) {
                            subject4Bool = true;
                        }
                    }

                    if (subject1Bool && subject2Bool && subject3Bool&& subject4Bool) {
                        outputStudentInfo(student, textFile);
                    }

                }
                file.close();
                textFile.close();


            }
            else {
                cout << "Помилка при відкритті файлу." << endl;
            }
    }

    

}