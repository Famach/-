#include "lab5.h"
#include <cmath>
#include <iostream>

namespace lab05 {
    VECTOR::VECTOR(int n) {
        if (n > 200) {
            std::cerr << "err: –азмер вектора превышает допустимый лимит [200]" << std::endl;
            exit(2);
        }
        this->n = n;
        for (int i = 0; i < this->n; i++) {
            this->A[i] = 0.f;
        }
    }

    VECTOR::VECTOR(const VECTOR& other) {
        this->n = other.n;
        for (int i = 0; i < this->n; ++i) {
            this->A[i] = other.A[i];
        }
    }

    VECTOR& VECTOR::operator=(const VECTOR& other) {
        if (this != &other) {
            this->n = other.n;
            for (int i = 0; i < n; ++i) {
                this->A[i] = other.A[i];
            }
        }
        return *this;
    }

    VECTOR& VECTOR::operator=(VECTOR&& other) noexcept {
        if (this != &other) {
            this->n = other.n;
            for (int i = 0; i < n; ++i) {
                this->A[i] = other.A[i];
            }
            other.n = 0;
        }
        return *this;
    }

    float& VECTOR::operator[](int index) {
        if (index < 0 || index >= n) {
            throw std::out_of_range("»ндекс за пределами диапазона.");
        }
        return A[index];
    }

    const float& VECTOR::operator[](int index) const {
        if (index < 0 || index >= n) {
            throw std::out_of_range("»ндекс за пределами диапазона.");
        }
        return A[index];
    }

    float VECTOR::operator()(int index) const {
        if (index < 0 || index >= n) {
            throw std::out_of_range("»ндекс за пределами диапазона.");
        }
        return A[index];
    }

    VECTOR VECTOR::operator+(const VECTOR& other) const {
        if (n != other.n) {
            throw std::invalid_argument("–азмерности векторов должны совпадать дл€ сложени€.");
        }
        VECTOR result(n);
        for (int i = 0; i < n; ++i) {
            result.A[i] = this->A[i] + other.A[i];
        }
        return result;
    }

    float VECTOR::operator*(const VECTOR& other) const {
        if (n != other.n) {
            throw std::invalid_argument("–азмерности векторов должны совпадать дл€ умножени€.");
        }
        float result = 0.0f;
        for (int i = 0; i < n; ++i) {
            result += A[i] * other.A[i];
        }
        return result;
    }

    std::ostream& operator<<(std::ostream& os, const VECTOR& vec) {
        for (int i = 0; i < vec.n; ++i) {
            os << vec.A[i] << " ";
        }
        return os;
    }

    std::istream& operator>>(std::istream& is, VECTOR& vec) {
        for (int i = 0; i < vec.n; ++i) {
            is >> vec.A[i];
        }
        return is;
    }

    void VECTOR::SetValue(int index, float value) {
        if (index >= 0 && index < n) {
            A[index] = value;
        }
        else {
            std::cerr << "ќшибка: индекс за пределами диапазона" << std::endl;
        }
    }

    VECTOR VECTOR::Add(float scalar) {
        VECTOR result(n);
        for (int i = 0; i < n; ++i) {
            result.A[i] = this->A[i] + scalar;
        }
        return result;
    }

    void VECTOR::Normalize() {
        float length = 0.0f;
        for (int i = 0; i < n; ++i) {
            length += A[i] * A[i];
        }
        if (length == 0) {
            throw std::runtime_error("Ќевозможно нормализовать нулевой вектор.");
        }
        length = std::sqrt(length);
        for (int i = 0; i < n; ++i) {
            A[i] /= length;
        }
    }

    void VECTOR::Print() {
        for (int i = 0; i < n; ++i) {
            std::cout << A[i] << " ";
        }
        std::cout << std::endl;
    }

    void Priint(const VECTOR& vector) {
        for (int i = 0; i < vector.n; ++i) {
            std::cout << vector.A[i] << " ";
        }
        std::cout << std::endl;
    }
}
