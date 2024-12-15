#include "lab1.h"
#include <stdexcept>

namespace lab01 {

    VECTOR::VECTOR(int n) {
        if (n > 200) {
            std::cerr << "err: Размер вектора превышает допустимый лимит [200]" << std::endl;
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

    void VECTOR::SetValue(int index, float value) {
        if (index >= 0 && index < n) {
            A[index] = value;
        }
    }

    VECTOR VECTOR::Add(const VECTOR& what) {
        VECTOR result(this->n);
        for (int i = 0; i < this->n; ++i) {
            result.A[i] = this->A[i] + what.A[i];
        }
        return result;
    }

    float VECTOR::Mul(const VECTOR& what) {
        if (n != what.n) {
            throw std::invalid_argument("Размерности векторов должны совпадать для умножения.");
        }
        float result = 0.0f;
        for (int i = 0; i < n; ++i) {
            result += A[i] * what.A[i];
        }
        std::cout << "Результат умножения векторов: " << result << std::endl;
        return result;
    }

    void VECTOR::Normalize() {
        float length = 0.0f;
        for (int i = 0; i < n; ++i) {
            length += A[i] * A[i];
        }
        if (length == 0) {
            throw std::runtime_error("Невозможно нормализовать нулевой вектор.");
        }
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

} // namespace lab01
