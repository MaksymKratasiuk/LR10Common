#include "iostream"
#include"first.h"
#include"second.h"
#include "third.h"
#include"fourth.h"
#include"five.h"
#include "sixth.h"
#include"string"
#include "PrintFromBinFile.h"
#include "WriteToBinaryFile.h"
#include "Windows.h"

using namespace std;



void main() {
    //setlocale(0, "ukr");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int choice = 0;
    do {
        cout << "Меню з режимами роботи:" << endl;
        cout << "1 - Порахувати середній бал за кожною дисципліною і вивести студентів з найменшим середнім балом." << endl;
        cout << "2 - Порахувати рейтинг груп по всіх 4-х предметах та впорядкувати записи за рейтингом у порядку спадання відомим алгоритмом." << endl;
        cout << "3 - Вивести дані з дисциплін для студентів із заданими однаковими прізвищем та згрупувати по групах." << endl;
        cout << "4 - Вивести студентів, що мають 5 і 4 з двох заданих предметів; 4 і 3 - з трьох заданих предметів; 5 і 3 - з чотирьох предметів." << endl;
        cout << "5 - Вивести студентів, що мають 5 і 4 з двох заданих предметів; 4 і 3 - з трьох заданих предметів; 5 і 3 - з чотирьох предметів." << endl;
        cout << "6 - Впорядкувати записи в файлі за групою" << endl;
        cout << "7 - Вийти" << endl;
        cout << "8 - Зчитати з файлу" << endl;
        cout << "9 - Запис в файл" << endl;
        cout << "Виберіть режим (1-6): " << endl;
        cin >> choice;

        switch (choice) {
        case 1: {
            smallestAvarage();
            break;
        }
        case 2: {
            second();
            break;
        }
        case 3: {
            string surname;
            cout << "Введіть прізвище за яким робити пошук-> ";
            cin.get();
            getline(cin, surname);
            same_surname(surname);
            break;
        }
        case 4: {
            fourth();
            break;
        }
        case 5: {
            five();
            break;
        }
        case 6:
            by_group();
            break;
        case 7:
            cout << "До побачення!" << endl;
            break;
        case 8 :

            readAndPrintBinaryFile("students.bin");
            break;
        case 9:
            readStudent();
            break;
        default:
            cout << "Невiрний вибiр. Спробуйте ще раз." << endl;
        }
    } while (choice != 7);

    


}