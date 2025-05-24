#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool isNumber(const string& str) {
    for (char c : str) {
        if (!isdigit(c)) return false;
    }
    return !str.empty();
}

int inputNumber() {
    string input;
    cout << "Введите натуральное число: ";
    cin >> input;

    while (!isNumber(input)) {
        cout << "Ошибка! Введите натуральное число: ";
        cin >> input;
    }

    return stoi(input);
}

void showMenu() {
    cout << "\nМеню операций:\n";
    cout << "1. Ввести новое число\n";
    cout << "2. Проверить первую и последнюю цифру\n";
    cout << "3. Проверить нечетность последней цифры\n";
    cout << "4. Выход\n";
    cout << "Выберите операцию: ";
}

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