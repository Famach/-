#pragma once
#include <iostream>

namespace lab01 {

    class VECTOR {
    private:
        int n{ 0 };
        float A[200];
    public:
        VECTOR(int n);
        VECTOR(const VECTOR& other);
        void SetValue(int index, float value);
        VECTOR Add(const VECTOR& what);
        inline VECTOR AddInline(const VECTOR& other) {
            VECTOR result(n);
            for (int i = 0; i < n; ++i) {
                result.A[i] = this->A[i] + other.A[i];
            }
            return result;
        }
        float Mul(const VECTOR& what);
        void Normalize();
        void Print();
        friend void Priint(const VECTOR& vector);
    };

} // namespace lab01
