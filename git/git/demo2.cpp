#include "lab2.h"
#include <iostream>

namespace lab02 {
    void runDemo() {
        setlocale(LC_ALL, "Rus");

        while (true) {
            // ������ ������
            char text[256];
            std::cout << "������� ����� (�������� 255 ��������): ";
            std::cin.ignore(); // ������� ������� �����
            std::cin.getline(text, 256);

            // ������� ������ TextProcessor
            TextProcessor processor(text);

            // ��������� ������ ����
            processor.replaceIBMWithIntel();

            // �������� ���������
            std::cout << "��������� ��������� ������: " << std::endl;
            processor.printText();

            // ��������� ��� �����
            char choice;
            std::cout << "������ ���������? (y/n): ";
            std::cin >> choice;
            if (choice != 'y' && choice != 'Y') {
                break;
            }
        }
    }
}
