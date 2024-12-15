#include "lab1.h"
#include <iostream>

namespace lab01 {
    void runDemo() {
        setlocale(LC_ALL, "Rus");

        while (true) {
            int iSize1{ 0 };
            int iSize2{ 0 };

            // ���� �������� ��������
            std::cout << "������� ������ ������� �������: ";
            std::cin >> iSize1;
            std::cout << "������� ������ ������� �������: ";
            std::cin >> iSize2;

            // �������� �� ���������� ������ ��������
            if (iSize1 != iSize2) {
                std::cerr << "������� �������� ������ ���� ����������� ��� ���������� ��������." << std::endl;
                continue;
            }

            // �������� ����������� ������ VECTOR
            VECTOR v1(iSize1);
            VECTOR v2(iSize2);

            std::cout << "# ����� ���� ������� ��������" << std::endl;
            v1.Print();
            v2.Print();

            // ���������� ������� �������
            std::cout << "������� �������� ������� �������: " << std::endl;
            for (int i = 0; i < iSize1; i++) {
                float value;
                std::cout << "a(" << i << ") = ";
                std::cin >> value;
                v1.SetValue(i, value);
            }

            // ���������� ������� �������
            std::cout << "������� �������� ������� �������: " << std::endl;
            for (int i = 0; i < iSize2; i++) {
                float value;
                std::cout << "a(" << i << ") = ";
                std::cin >> value;
                v2.SetValue(i, value);
            }

            // ���������� ��������
            std::cout << "# ���������� ��������: " << std::endl;
            VECTOR v5(v2);
            v5.Print();

            // �������� �������� (����� Add)
            VECTOR v3 = v1.Add(v2);
            std::cout << "# ��������� �������� (����� Add): " << std::endl;
            v3.Print();

            // ��������� ������������
            std::cout << "# ��������� ���������� ������������: " << std::endl;
            v1.Mul(v2);

            // ������������ ��������
            std::cout << "# ��������� ������������: " << std::endl;
            v1.Normalize();
            v1.Print();
            v2.Normalize();
            v2.Print();

            // ���������� friend ������� ��� ������
            std::cout << "# ������ ������� ������� � ������� friend Print: " << std::endl;
            Priint(v1);

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
