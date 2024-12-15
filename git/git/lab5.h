#pragma once
#include <iostream>
#include <stdexcept>

namespace lab05 {
    class VECTOR {
    private:
        int n{ 0 };
        float A[200]; // Максимальный размер вектора
    public:
        VECTOR(int n);
        VECTOR(const VECTOR& other);

        VECTOR& operator=(const VECTOR& other);
        VECTOR& operator=(VECTOR&& other) noexcept;

        float& operator[](int index);
        const float& operator[](int index) const;

        float operator()(int index) const;

        VECTOR operator+(const VECTOR& other) const;
        float operator*(const VECTOR& other) const;

        friend std::ostream& operator<<(std::ostream& os, const VECTOR& vec);
        friend std::istream& operator>>(std::istream& is, VECTOR& vec);

        VECTOR Add(float scalar);
        void SetValue(int index, float value);
        VECTOR Add(VECTOR what);
        inline VECTOR AddInline(const VECTOR& other) {
            VECTOR result(n);
            for (int i = 0; i < n; ++i) {
                result.A[i] = this->A[i] + other.A[i];
            }
            return result;
        }
        float Mul(VECTOR what);
        void Normalize();
        void Print();
        friend void Priint(const VECTOR& vector);
    };
}
