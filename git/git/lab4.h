#pragma once
#include <iostream>

class VECTOR2D {
protected:
    int n{ 0 };
    float A[200]; // Максимальный размер вектора
public:
    VECTOR2D(int n);
    VECTOR2D(const VECTOR2D& other);
    virtual ~VECTOR2D() {}

    void SetValue(int index, float value);
    VECTOR2D Add(VECTOR2D what);

    virtual void Print(); // Сделано виртуальным
    virtual float Mul(VECTOR2D what); // Сделано виртуальным
    virtual void Normalize();

    int GetSize() const { return n; }
};

class VECTOR3D : public VECTOR2D {
public:
    VECTOR3D() : VECTOR2D(3) {}

    void Print() override; // Метод вывода вектора 3D
    float Mul(VECTOR2D what) override; // Скалярное произведение для 3D
};
