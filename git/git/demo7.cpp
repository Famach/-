#include "lab7.h"
#include <iostream>
#include <fstream>
namespace lab07 {
    void runDemo() {
        setlocale(LC_ALL, "Rus");

        while (true) {
            std::cout << "�������� ��������:\n";
            std::cout << "1. ������ � �������\n";
            std::cout << "2. ������ � ���������\n";
            std::cout << "0. �����\n";

            int choice;
            std::cin >> choice;

            if (choice == 0) {
                break;
            }
            else if (choice == 1) {
                Chisla chisla;
                chisla.Input();

                // ��������� ���� ��� ������ �����
                std::ofstream file("chisla_output.txt", std::ios::app);
                if (!file) {
                    std::cerr << "������ ��� �������� �����!" << std::endl;
                    continue;
                }

                chisla.Output(std::cout, file);

                file.close();
                std::cout << "���������� ��������� � ���� chisla_output.txt\n";
            }
            else if (choice == 2) {
                std::cout << "������� ������ �������: ";
                int size;
                std::cin >> size;

                VECTOR v1(size), v2(size);
                std::cout << "������� ������ ������:\n";
                std::cin >> v1;
                std::cout << "������� ������ ������:\n";
                std::cin >> v2;

                VECTOR sum = v1.Add(v2);
                float scalarMul = v1.Mul(v2);

                // ��������� ���� ��� ������ ��������
                std::ofstream file("vector_output.txt", std::ios::app);
                if (!file) {
                    std::cerr << "������ ��� �������� �����!" << std::endl;
                    continue;
                }

                std::cout << "����� ��������: " << sum << "\n";
                file << "����� ��������: " << sum << "\n";

                std::cout << "��������� ������������: " << scalarMul << "\n";
                file << "��������� ������������: " << scalarMul << "\n";

                std::cout << "������������ ������� �������:\n";
                v1.Normalize();
                std::cout << v1 << "\n";
                file << "������������ ������� �������: " << v1 << "\n";

                file.close();
                std::cout << "���������� ��������� � ���� vector_output.txt\n";
            }
            else {
                std::cout << "�������� �����!\n";
            }
        }
    }
}
