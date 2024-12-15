#include "lab3.h"
#include <iostream>
#include <locale.h>  // Для setlocale

namespace lab03 {
    void runDemo() {
        setlocale(LC_ALL, "");  // Устанавливаем локаль для корректного ввода

        // На Windows устанавливаем UTF-8 в консоли
#ifdef _WIN32
        system("chcp 1251 > nul");
#endif

        char sequence1[100], sequence2[100];
        char choice;

        do {
            std::cout << "\nВведите первую последовательность символов: ";
            std::cin.ignore(); // Очистка буфера перед вводом
            std::cin.getline(sequence1, 100);
            std::cout << "Введите вторую последовательность символов: ";
            std::cin.getline(sequence2, 100);

            TextManager manager(sequence1, sequence2);

            std::cout << "Общие символы: ";
            manager.findCommonCharacters();

            std::cout << "\nХотите продолжить? (y/n): ";
            std::cin >> choice;

        } while (choice == 'y' || choice == 'Y');
    }
}
