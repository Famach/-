#include "lab2.h"
#include <iostream>

namespace lab02 {
    void runDemo() {
        setlocale(LC_ALL, "Rus");

        while (true) {
            // Пример текста
            char text[256];
            std::cout << "Введите текст (максимум 255 символов): ";
            std::cin.ignore(); // Убираем остатки ввода
            std::cin.getline(text, 256);

            // Создаем объект TextProcessor
            TextProcessor processor(text);

            // Выполняем замену слов
            processor.replaceIBMWithIntel();

            // Печатаем результат
            std::cout << "Результат обработки текста: " << std::endl;
            processor.printText();

            // Повторить или выйти
            char choice;
            std::cout << "Хотите повторить? (y/n): ";
            std::cin >> choice;
            if (choice != 'y' && choice != 'Y') {
                break;
            }
        }
    }
}
