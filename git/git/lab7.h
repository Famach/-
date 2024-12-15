#ifndef LAB7_H
#define LAB7_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

// --- Класс VECTOR ---
class VECTOR {
public:
    VECTOR(int n);
    VECTOR Add(const VECTOR& v);
    float Mul(const VECTOR& v);
    void Normalize();

    friend std::ostream& operator<<(std::ostream& os, const VECTOR& v);
    friend std::istream& operator>>(std::istream& is, VECTOR& v);

private:
    std::vector<float> components;
};

// --- Класс Chisla ---
class Chisla {
public:
    void Input();
    void Output(std::ostream& os, std::ofstream& file) const;

private:
    char c1, c2;
    float f;
    int i1, i2;

    std::string convertFloatToOctal(float f) const;
    void outputOctalWithPrecision(std::ostream& os, std::ofstream& file, const std::string& octal, int precision) const;
};

// --- Класс Manip ---
class Manip {
public:
    Manip(int width, int base, int precision, char fill_char);

    friend std::ostream& operator<<(std::ostream& os, const Manip& manip);

private:
    int width;
    int base;
    int precision;
    char fill_char;
};

// Функция для запуска демонстрации
namespace lab07 {
    void runDemo();  // Прототип функции
}

#endif // LAB7_H
