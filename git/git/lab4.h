#pragma once
#include <iostream>

class VECTOR2D {
protected:
    int n{ 0 };
    float A[200]; // ������������ ������ �������
public:
    VECTOR2D(int n);
    VECTOR2D(const VECTOR2D& other);
    virtual ~VECTOR2D() {}

    void SetValue(int index, float value);
    VECTOR2D Add(VECTOR2D what);

    virtual void Print(); // ������� �����������
    virtual float Mul(VECTOR2D what); // ������� �����������
    virtual void Normalize();

    int GetSize() const { return n; }
};

class VECTOR3D : public VECTOR2D {
public:
    VECTOR3D() : VECTOR2D(3) {}

    void Print() override; // ����� ������ ������� 3D
    float Mul(VECTOR2D what) override; // ��������� ������������ ��� 3D
};
