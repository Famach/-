#include "lab1.h"
#include "lab2.h"
#include "lab3.h"
#include "lab4.h"
#include "lab5.h"
#include "lab6.h"
#include "lab7.h"
#include <iostream>

// Прототипы функций для вызова демо-программ
namespace lab01 {
    void runDemo();
}
namespace lab02 {
    void runDemo();
}
namespace lab03 {
    void runDemo();
}
namespace lab04 {
    void runDemo();
}
namespace lab05 {
    void runDemo();
}
namespace lab06 {
    void runDemo();
}
namespace lab07 {
    void runDemo();
}

int main() {
    setlocale(LC_ALL, "Rus");

    while (true) {
        std::cout << "Выберите лабораторную работу:\n";
        std::cout << "1. Лабораторная работа 1\n";
        std::cout << "2. Лабораторная работа 2\n";
        std::cout << "3. Лабораторная работа 3\n";
        std::cout << "4. Лабораторная работа 4\n";
        std::cout << "5. Лабораторная работа 5\n";
        std::cout << "6. Лабораторная работа 6\n";
        std::cout << "7. Лабораторная работа 7\n";
        std::cout << "0. Выход\n";
        std::cout << "Ваш выбор: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1:
            lab01::runDemo(); // Вызов демо первой лабораторной работы
            break;
        case 2:
            lab02::runDemo(); // Вызов демо второй лабораторной работы
            break;
        case 3:
            lab03::runDemo(); // Вызов демо второй лабораторной работы
            break;
        case 4:
            lab04::runDemo(); // Вызов демо второй лабораторной работы
            break;
        case 5:
            lab05::runDemo(); // Вызов демо второй лабораторной работы
            break;
        case 6:
            lab06::runDemo(); // Вызов демо второй лабораторной работы
            break;
        case 7:
            lab07::runDemo(); // Вызов демо второй лабораторной работы
            break;
        case 0:
            std::cout << "Выход из программы...\n";
            return 0;
        default:
            std::cout << "Некорректный выбор. Попробуйте снова.\n";
            break;
        }
    }

    return 0;
}
