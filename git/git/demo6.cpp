#include "lab6.h"
#include <iostream>
#include <complex>
#include <locale>

namespace lab06 {
    void runDemo() {
        setlocale(LC_ALL, "Rus");

        while (true) {
            std::cout << "\n�������� ��������:\n";
            std::cout << "1. ������ ������ ����� �����\n";
            std::cout << "2. ������ ������ ����������� �����\n";
            std::cout << "3. �����\n";
            std::cout << "��� �����: ";

            int choice;
            std::cin >> choice;

            if (choice == 1) {
                ArrayProcessor<int> intProcessor;
                std::cin >> intProcessor;
                intProcessor.processArray();
                print("������������ ������ ����� �����: ");  // ���������� print ��� ������ ��������������� ������
                intProcessor.printArray();  // ������������ ����������� ����� ��� ������ ������� ����� �����
            }
            else if (choice == 2) {
                ArrayProcessor<std::complex<double>> complexProcessor;
                std::cin >> complexProcessor;
                complexProcessor.processArray();
                print("������������ ������ ����������� �����: ");  // ����������, ������� ���������� ��� ����������� �����
                complexProcessor.printArray();  // ����� ��� ������ ������� ����������� �����
            }
            else if (choice == 3) {
                break;
            }
            else {
                std::cout << "�������� ����. ���������� �����.\n";
            }
        }


    }
}
