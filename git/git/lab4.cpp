#include "lab4.h"
#include <iostream>
#include <stdexcept>

// ���������� ������������ VECTOR2D
VECTOR2D::VECTOR2D(int n) {
    if (n > 200) {
        std::cerr << "err: ������ ������� ��������� ���������� ����� [200]" << std::endl;
        exit(2);
    }
    this->n = n;
    for (int i = 0; i < this->n; i++) {
        this->A[i] = 0.f;
    }
}

// ���������� ������������ ����������� VECTOR2D
VECTOR2D::VECTOR2D(const VECTOR2D& other) {
    this->n = other.n;
    for (int i = 0; i < this->n; ++i) {
        this->A[i] = other.A[i];
    }
}

// ���������� ������ SetValue
void VECTOR2D::SetValue(int index, float value) {
    if (index >= 0 && index < n) {
        A[index] = value;
    }
}

// ���������� ������ Add ��� �������� ��������
VECTOR2D VECTOR2D::Add(VECTOR2D what) {
    if (this->n != what.n) {
        throw std::invalid_argument("����������� �������� ������ ��������� ��� ��������.");
    }
    VECTOR2D result(this->n);
    for (int i = 0; i < this->n; ++i) {
        result.A[i] = this->A[i] + what.A[i];
    }
    return result;
}

// ���������� ������ Mul ��� ���������� ������������
float VECTOR2D::Mul(VECTOR2D what) {
    if (this->n != what.n) {
        throw std::invalid_argument("����������� �������� ������ ��������� ��� ���������.");
    }
    float result = 0.0f;
    for (int i = 0; i < this->n; ++i) {
        result += this->A[i] * what.A[i];
    }
    return result;
}

// ���������� ������ Normalize ��� ������������ �������
void VECTOR2D::Normalize() {
    float length = 0.0f;
    for (int i = 0; i < n; ++i) {
        length += A[i] * A[i];
    }
    if (length == 0) {
        throw std::runtime_error("���������� ������������� ������� ������.");
    }
    length = sqrt(length);
    for (int i = 0; i < n; ++i) {
        A[i] /= length;
    }
}

// ���������� ������ Print ��� ������ �������
void VECTOR2D::Print() {
    for (int i = 0; i < n; ++i) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}

// ���������� ������ Print ��� VECTOR3D
void VECTOR3D::Print() {
    std::cout << "3D Vector: ";
    VECTOR2D::Print();
}

// ���������� ������ Mul ��� ���������� ������������ ��� VECTOR3D
float VECTOR3D::Mul(VECTOR2D what) {
    if (what.GetSize() != 3) {
        throw std::invalid_argument("�������� Mul �������������� ������ ��� 3D ��������.");
    }
    return VECTOR2D::Mul(what);
}
