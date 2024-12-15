#include "lab6.h"
#include <iostream>
#include <complex>
#include <locale>

namespace lab06 {
    void runDemo() {
        setlocale(LC_ALL, "Rus");

        while (true) {
            std::cout << "\nВыберите действие:\n";
            std::cout << "1. Ввести массив целых чисел\n";
            std::cout << "2. Ввести массив комплексных чисел\n";
            std::cout << "3. Выход\n";
            std::cout << "Ваш выбор: ";

            int choice;
            std::cin >> choice;

            if (choice == 1) {
                ArrayProcessor<int> intProcessor;
                std::cin >> intProcessor;
                intProcessor.processArray();
                print("Обработанный массив целых чисел: ");  // Используем print для вывода дополнительного текста
                intProcessor.printArray();  // Используется стандартный метод для вывода массива целых чисел
            }
            else if (choice == 2) {
                ArrayProcessor<std::complex<double>> complexProcessor;
                std::cin >> complexProcessor;
                complexProcessor.processArray();
                print("Обработанный массив комплексных чисел: ");  // Аналогично, выводим информацию для комплексных чисел
                complexProcessor.printArray();  // Метод для вывода массива комплексных чисел
            }
            else if (choice == 3) {
                break;
            }
            else {
                std::cout << "Неверный ввод. Попробуйте снова.\n";
            }
        }


    }
}
