#include "lab6.h"
#include <limits>
#include <cmath>

// ���������� ������� ��� ������� �����
template <typename T>
ArrayProcessor<T>::ArrayProcessor() : array() {}

template <typename T>
ArrayProcessor<T>::ArrayProcessor(const std::vector<T>& arr) : array(arr) {}

template <typename T>
T ArrayProcessor<T>::findMin() const {
    T min = std::numeric_limits<T>::max();
    bool found = false;

    for (const auto& elem : array) {
        if (elem != 0 && elem < min) {
            min = elem;
            found = true;
        }
    }

    if (!found) {
        throw std::runtime_error("No non-zero elements to find minimum.");
    }

    return min;
}

template <typename T>
T ArrayProcessor<T>::findMax() const {
    T max = std::numeric_limits<T>::lowest();

    for (const auto& elem : array) {
        if (elem > max) {
            max = elem;
        }
    }

    return max;
}

template <typename T>
void ArrayProcessor<T>::processArray() {
    T min = findMin();
    T max = findMax();

    for (size_t i = 0; i < array.size(); ++i) {
        if (array[i] == 0) {
            array[i] = (i % 2 == 0) ? max : min;
        }
    }
}

template <typename T>
void ArrayProcessor<T>::printArray() const {
    for (const auto& elem : array) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

// ���������� ������������� ��� std::complex<T>
template <typename T>
ArrayProcessor<std::complex<T>>::ArrayProcessor() : array() {}

template <typename T>
ArrayProcessor<std::complex<T>>::ArrayProcessor(const std::vector<std::complex<T>>& arr) : array(arr) {}

template <typename T>
std::complex<T> ArrayProcessor<std::complex<T>>::findMin() const {
    std::complex<T> min;
    double minNorm = std::numeric_limits<double>::max();
    bool found = false;

    for (const auto& elem : array) {
        if (std::abs(elem) > 1e-9 && std::norm(elem) < minNorm) {
            min = elem;
            minNorm = std::norm(elem);
            found = true;
        }
    }

    if (!found) {
        throw std::runtime_error("No non-zero elements to find minimum.");
    }

    return min;
}

template <typename T>
std::complex<T> ArrayProcessor<std::complex<T>>::findMax() const {
    std::complex<T> max;
    double maxNorm = std::numeric_limits<double>::lowest();

    for (const auto& elem : array) {
        if (std::norm(elem) > maxNorm) {
            max = elem;
            maxNorm = std::norm(elem);
        }
    }

    return max;
}

template <typename T>
void ArrayProcessor<std::complex<T>>::processArray() {
    std::complex<T> min = findMin();
    std::complex<T> max = findMax();

    for (size_t i = 0; i < array.size(); ++i) {
        if (std::abs(array[i]) < 1e-9) { // ���������, �������� �� ������� �����
            array[i] = (i % 2 == 0) ? max : min;
        }
    }
}

template <typename T>
void ArrayProcessor<std::complex<T>>::printArray() const {
    for (const auto& elem : array) {
        std::cout << elem.real() << "+" << elem.imag() << "i ";
    }
    std::cout << std::endl;
}

// ����� ������������� �������
template class ArrayProcessor<int>;
template class ArrayProcessor<std::complex<double>>;

// ���������� ������� print � ���������� ������ ����������
template<typename... Args>
void print(Args... args) {
    (std::cout << ... << args) << std::endl;  // ������� ��������� ��� ������ ���� ����������
}

// ����� ������������� ��� const char*
template void print<const char*>(const char*);
