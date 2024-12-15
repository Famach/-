#include "lab4.h"
#include <iostream>

namespace lab04 {
    void runDemo() {
        setlocale(LC_ALL, "Rus");

        VECTOR2D v1(3); // ������� ������
        VECTOR3D v2; // ���������� ������

        // ���������� ��������
        std::cout << "������� �������� ������� v1: " << std::endl;
        for (int i = 0; i < 3; i++) {
            float value;
            std::cout << "a(" << i << ") = ";
            std::cin >> value;
            v1.SetValue(i, value);
        }

        std::cout << "������� �������� ������� v2 (3D): " << std::endl;
        for (int i = 0; i < 3; i++) {
            float value;
            std::cout << "a(" << i << ") = ";
            std::cin >> value;
            v2.SetValue(i, value);
        }

        // ����� ��������
        std::cout << "����� ������� v1: ";
        v1.Print();

        std::cout << "����� ������� v2: ";
        v2.Print();

        // �������� ��������
        VECTOR2D v3 = v1.Add(v2);
        std::cout << "# ��������� �������� (����� Add): " << std::endl;
        v3.Print();

        // ��������� ������������
        std::cout << "# ��������� ���������� ������������: " << std::endl;
        try {
            v1.Mul(v2);
        }
        catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

        // ������������ ��������
        std::cout << "# ��������� ������������ ������� v1: " << std::endl;
        try {
            v1.Normalize();
            v1.Print();
        }
        catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

        std::cout << "# ��������� ������������ ������� v2: " << std::endl;
        try {
            v2.Normalize();
            v2.Print();
        }
        catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
}
