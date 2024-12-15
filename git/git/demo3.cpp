#include "lab3.h"
#include <iostream>
#include <locale.h>  // ��� setlocale

namespace lab03 {
    void runDemo() {
        setlocale(LC_ALL, "");  // ������������� ������ ��� ����������� �����

        // �� Windows ������������� UTF-8 � �������
#ifdef _WIN32
        system("chcp 1251 > nul");
#endif

        char sequence1[100], sequence2[100];
        char choice;

        do {
            std::cout << "\n������� ������ ������������������ ��������: ";
            std::cin.ignore(); // ������� ������ ����� ������
            std::cin.getline(sequence1, 100);
            std::cout << "������� ������ ������������������ ��������: ";
            std::cin.getline(sequence2, 100);

            TextManager manager(sequence1, sequence2);

            std::cout << "����� �������: ";
            manager.findCommonCharacters();

            std::cout << "\n������ ����������? (y/n): ";
            std::cin >> choice;

        } while (choice == 'y' || choice == 'Y');
    }
}
