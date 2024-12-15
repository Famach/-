#include "lab4.h"
#include <iostream>
#include <stdexcept>

// Реализация конструктора VECTOR2D
VECTOR2D::VECTOR2D(int n) {
    if (n > 200) {
        std::cerr << "err: Размер вектора превышает допустимый лимит [200]" << std::endl;
        exit(2);
    }
    this->n = n;
    for (int i = 0; i < this->n; i++) {
        this->A[i] = 0.f;
    }
}

// Реализация конструктора копирования VECTOR2D
VECTOR2D::VECTOR2D(const VECTOR2D& other) {
    this->n = other.n;
    for (int i = 0; i < this->n; ++i) {
        this->A[i] = other.A[i];
    }
}

// Реализация метода SetValue
void VECTOR2D::SetValue(int index, float value) {
    if (index >= 0 && index < n) {
        A[index] = value;
    }
}

// Реализация метода Add для сложения векторов
VECTOR2D VECTOR2D::Add(VECTOR2D what) {
    if (this->n != what.n) {
        throw std::invalid_argument("Размерности векторов должны совпадать для сложения.");
    }
    VECTOR2D result(this->n);
    for (int i = 0; i < this->n; ++i) {
        result.A[i] = this->A[i] + what.A[i];
    }
    return result;
}

// Реализация метода Mul для скалярного произведения
float VECTOR2D::Mul(VECTOR2D what) {
    if (this->n != what.n) {
        throw std::invalid_argument("Размерности векторов должны совпадать для умножения.");
    }
    float result = 0.0f;
    for (int i = 0; i < this->n; ++i) {
        result += this->A[i] * what.A[i];
    }
    return result;
}

// Реализация метода Normalize для нормализации вектора
void VECTOR2D::Normalize() {
    float length = 0.0f;
    for (int i = 0; i < n; ++i) {
        length += A[i] * A[i];
    }
    if (length == 0) {
        throw std::runtime_error("Невозможно нормализовать нулевой вектор.");
    }
    length = sqrt(length);
    for (int i = 0; i < n; ++i) {
        A[i] /= length;
    }
}

// Реализация метода Print для вывода вектора
void VECTOR2D::Print() {
    for (int i = 0; i < n; ++i) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}

// Реализация метода Print для VECTOR3D
void VECTOR3D::Print() {
    std::cout << "3D Vector: ";
    VECTOR2D::Print();
}

// Реализация метода Mul для скалярного произведения для VECTOR3D
float VECTOR3D::Mul(VECTOR2D what) {
    if (what.GetSize() != 3) {
        throw std::invalid_argument("Операция Mul поддерживается только для 3D векторов.");
    }
    return VECTOR2D::Mul(what);
}
