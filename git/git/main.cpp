#include "lab1.h"
#include "lab2.h"
#include "lab3.h"
#include "lab4.h"
#include "lab5.h"
#include "lab6.h"
#include "lab7.h"
#include <iostream>

// ��������� ������� ��� ������ ����-��������
namespace lab01 {
    void runDemo();
}
namespace lab02 {
    void runDemo();
}
namespace lab03 {
    void runDemo();
}
namespace lab04 {
    void runDemo();
}
namespace lab05 {
    void runDemo();
}
namespace lab06 {
    void runDemo();
}
namespace lab07 {
    void runDemo();
}

int main() {
    setlocale(LC_ALL, "Rus");

    while (true) {
        std::cout << "�������� ������������ ������:\n";
        std::cout << "1. ������������ ������ 1\n";
        std::cout << "2. ������������ ������ 2\n";
        std::cout << "3. ������������ ������ 3\n";
        std::cout << "4. ������������ ������ 4\n";
        std::cout << "5. ������������ ������ 5\n";
        std::cout << "6. ������������ ������ 6\n";
        std::cout << "7. ������������ ������ 7\n";
        std::cout << "0. �����\n";
        std::cout << "��� �����: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1:
            lab01::runDemo(); // ����� ���� ������ ������������ ������
            break;
        case 2:
            lab02::runDemo(); // ����� ���� ������ ������������ ������
            break;
        case 3:
            lab03::runDemo(); // ����� ���� ������ ������������ ������
            break;
        case 4:
            lab04::runDemo(); // ����� ���� ������ ������������ ������
            break;
        case 5:
            lab05::runDemo(); // ����� ���� ������ ������������ ������
            break;
        case 6:
            lab06::runDemo(); // ����� ���� ������ ������������ ������
            break;
        case 7:
            lab07::runDemo(); // ����� ���� ������ ������������ ������
            break;
        case 0:
            std::cout << "����� �� ���������...\n";
            return 0;
        default:
            std::cout << "������������ �����. ���������� �����.\n";
            break;
        }
    }

    return 0;
}
