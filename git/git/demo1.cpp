#include "lab1.h"
#include <iostream>

namespace lab01 {
    void runDemo() {
        setlocale(LC_ALL, "Rus");

        while (true) {
            int iSize1{ 0 };
            int iSize2{ 0 };

            // Ввод размеров векторов
            std::cout << "Введите размер первого вектора: ";
            std::cin >> iSize1;
            std::cout << "Введите размер второго вектора: ";
            std::cin >> iSize2;

            // Проверка на одинаковый размер векторов
            if (iSize1 != iSize2) {
                std::cerr << "Размеры векторов должны быть одинаковыми для выполнения операций." << std::endl;
                continue;
            }

            // Создание экземпляров класса VECTOR
            VECTOR v1(iSize1);
            VECTOR v2(iSize2);

            std::cout << "# Вывод двух нулевых векторов" << std::endl;
            v1.Print();
            v2.Print();

            // Заполнение первого вектора
            std::cout << "Введите элементы первого вектора: " << std::endl;
            for (int i = 0; i < iSize1; i++) {
                float value;
                std::cout << "a(" << i << ") = ";
                std::cin >> value;
                v1.SetValue(i, value);
            }

            // Заполнение второго вектора
            std::cout << "Введите элементы второго вектора: " << std::endl;
            for (int i = 0; i < iSize2; i++) {
                float value;
                std::cout << "a(" << i << ") = ";
                std::cin >> value;
                v2.SetValue(i, value);
            }

            // Производим действия
            std::cout << "# Производим действия: " << std::endl;
            VECTOR v5(v2);
            v5.Print();

            // Сложение векторов (метод Add)
            VECTOR v3 = v1.Add(v2);
            std::cout << "# Результат сложения (метод Add): " << std::endl;
            v3.Print();

            // Скалярное произведение
            std::cout << "# Результат скалярного произведения: " << std::endl;
            v1.Mul(v2);

            // Нормализация векторов
            std::cout << "# Результат нормализации: " << std::endl;
            v1.Normalize();
            v1.Print();
            v2.Normalize();
            v2.Print();

            // Используем friend функцию для печати
            std::cout << "# Печать первого вектора с помощью friend Print: " << std::endl;
            Priint(v1);

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
