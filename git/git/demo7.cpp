#include "lab7.h"
#include <iostream>
#include <fstream>
namespace lab07 {
    void runDemo() {
        setlocale(LC_ALL, "Rus");

        while (true) {
            std::cout << "Выберите действие:\n";
            std::cout << "1. Работа с числами\n";
            std::cout << "2. Работа с векторами\n";
            std::cout << "0. Выход\n";

            int choice;
            std::cin >> choice;

            if (choice == 0) {
                break;
            }
            else if (choice == 1) {
                Chisla chisla;
                chisla.Input();

                // Открываем файл для записи чисел
                std::ofstream file("chisla_output.txt", std::ios::app);
                if (!file) {
                    std::cerr << "Ошибка при открытии файла!" << std::endl;
                    continue;
                }

                chisla.Output(std::cout, file);

                file.close();
                std::cout << "Результаты сохранены в файл chisla_output.txt\n";
            }
            else if (choice == 2) {
                std::cout << "Введите размер вектора: ";
                int size;
                std::cin >> size;

                VECTOR v1(size), v2(size);
                std::cout << "Введите первый вектор:\n";
                std::cin >> v1;
                std::cout << "Введите второй вектор:\n";
                std::cin >> v2;

                VECTOR sum = v1.Add(v2);
                float scalarMul = v1.Mul(v2);

                // Открываем файл для записи векторов
                std::ofstream file("vector_output.txt", std::ios::app);
                if (!file) {
                    std::cerr << "Ошибка при открытии файла!" << std::endl;
                    continue;
                }

                std::cout << "Сумма векторов: " << sum << "\n";
                file << "Сумма векторов: " << sum << "\n";

                std::cout << "Скалярное произведение: " << scalarMul << "\n";
                file << "Скалярное произведение: " << scalarMul << "\n";

                std::cout << "Нормализация первого вектора:\n";
                v1.Normalize();
                std::cout << v1 << "\n";
                file << "Нормализация первого вектора: " << v1 << "\n";

                file.close();
                std::cout << "Результаты сохранены в файл vector_output.txt\n";
            }
            else {
                std::cout << "Неверный выбор!\n";
            }
        }
    }
}
