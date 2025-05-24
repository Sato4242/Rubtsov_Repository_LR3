#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    int currentNum = 0;
    string choice;

    while (true) {
        showMenu();
        cin >> choice;

        if (choice == "1") {
            currentNum = inputNumber();
        }
        else if (choice == "2") {
            if (currentNum == 0) {
                cout << "Сначала введите число!\n";
            }
            else {
                checkFirstLastDigit(currentNum);
            }
        }
        else if (choice == "3") {
            if (currentNum == 0) {
                cout << "Сначала введите число!\n";
            }
            else {
                checkLastDigitOdd(currentNum);
            }
        }
        else if (choice == "4") {
            break;
        }
        else {
            cout << "Неверный выбор! Попробуйте снова.\n";
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Программа завершена.\n";
    return 0;
}