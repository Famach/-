#include "lab7.h"
#include <iomanip>
#include <cmath>
#include <sstream>

// --- VECTOR ---
VECTOR::VECTOR(int n) : components(n, 0.0f) {}

VECTOR VECTOR::Add(const VECTOR& v) {
    int size = std::min(components.size(), v.components.size());
    VECTOR result(size);
    for (int i = 0; i < size; ++i) {
        result.components[i] = components[i] + v.components[i];
    }
    return result;
}

float VECTOR::Mul(const VECTOR& v) {
    int size = std::min(components.size(), v.components.size());
    float result = 0.0f;
    for (int i = 0; i < size; ++i) {
        result += components[i] * v.components[i];
    }
    return result;
}

void VECTOR::Normalize() {
    float magnitude = 0.0f;
    for (float comp : components) {
        magnitude += comp * comp;
    }
    magnitude = std::sqrt(magnitude);
    if (magnitude > 0) {
        for (float& comp : components) {
            comp /= magnitude;
        }
    }
}

std::ostream& operator<<(std::ostream& os, const VECTOR& v) {
    for (float comp : v.components) {
        os << comp << " ";
    }
    return os;
}

std::istream& operator>>(std::istream& is, VECTOR& v) {
    for (float& comp : v.components) {
        is >> comp;
    }
    return is;
}

// --- Chisla ---
void Chisla::Input() {
    std::cout << "Введите c1 (char), f (float), c2 (char), i1 (int), i2 (int): ";
    std::cin >> c1 >> f >> c2 >> i1 >> i2;
}

std::string Chisla::convertFloatToOctal(float f) const {
    int integerPart = static_cast<int>(f);
    float fractionalPart = f - integerPart;

    std::stringstream result;
    result << std::oct << integerPart;

    if (fractionalPart > 0) {
        result << ".";
        for (int i = 0; i < 10; ++i) {
            fractionalPart *= 8;
            int digit = static_cast<int>(fractionalPart);
            result << digit;
            fractionalPart -= digit;
            if (fractionalPart == 0) break;
        }
    }

    return result.str();
}

void Chisla::outputOctalWithPrecision(std::ostream& os, std::ofstream& file, const std::string& octal, int precision) const {
    std::string rounded;
    size_t dotPos = octal.find('.');

    if (dotPos != std::string::npos && precision > 0) {
        rounded = octal.substr(0, dotPos + 1 + precision);
    }
    else {
        rounded = octal.substr(0, dotPos); // Только целая часть
    }

    os << rounded << "\n";
    file << rounded << "\n";
}

void Chisla::Output(std::ostream& os, std::ofstream& file) const {
    Manip manip(7, 8, 4, ' ');

    os << manip << i1 << "\n";
    file << i1 << "\n";

    os << manip << i2 << "\n";
    file << i2 << "\n";

    std::string octal = convertFloatToOctal(f);

    outputOctalWithPrecision(os, file, octal, 1);
    outputOctalWithPrecision(os, file, octal, 0);
    outputOctalWithPrecision(os, file, octal, 2);

    os << manip << c1 << "\n";
    file << c1 << "\n";

    os << manip << c2 << "\n";
    file << c2 << "\n";
}

// --- Manip ---
Manip::Manip(int width, int base, int precision, char fill_char)
    : width(width), base(base), precision(precision), fill_char(fill_char) {}

std::ostream& operator<<(std::ostream& os, const Manip& manip) {
    os << std::setw(manip.width)
        << std::setbase(manip.base)
        << std::setprecision(manip.precision)
        << std::setfill(manip.fill_char);
    return os;
}


