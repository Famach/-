#ifndef LAB6_H
#define LAB6_H

#include <vector>
#include <complex>
#include <iostream>

// ќбъ€вление шаблона ArrayProcessor
template <typename T>
class ArrayProcessor {
public:
    ArrayProcessor();
    ArrayProcessor(const std::vector<T>& arr);
    void processArray();
    void printArray() const;

    friend std::ostream& operator<<(std::ostream& os, const ArrayProcessor<T>& processor) {
        processor.printArray();
        return os;
    }

    friend std::istream& operator>>(std::istream& is, ArrayProcessor<T>& processor) {
        size_t n;
        std::cout << "¬ведите размер массива: ";
        is >> n;
        processor.array.resize(n);

        std::cout << "¬ведите элементы массива: ";
        for (size_t i = 0; i < n; ++i) {
            is >> processor.array[i];
        }
        return is;
    }

private:
    std::vector<T> array;
    T findMin() const;
    T findMax() const;
};

// —пециализаци€ дл€ std::complex<T>
template <typename T>
class ArrayProcessor<std::complex<T>> {
public:
    ArrayProcessor();
    ArrayProcessor(const std::vector<std::complex<T>>& arr);
    void processArray();
    void printArray() const;

    friend std::ostream& operator<<(std::ostream& os, const ArrayProcessor<std::complex<T>>& processor) {
        processor.printArray();
        return os;
    }

    friend std::istream& operator>>(std::istream& is, ArrayProcessor<std::complex<T>>& processor) {
        size_t n;
        std::cout << "¬ведите размер массива комплексных чисел: ";
        is >> n;
        processor.array.resize(n);

        std::cout << "¬ведите элементы массива (реальна€ и мнима€ часть через пробел): ";
        for (size_t i = 0; i < n; ++i) {
            T real, imag;
            is >> real >> imag;
            processor.array[i] = std::complex<T>(real, imag);
        }
        return is;
    }

private:
    std::vector<std::complex<T>> array;
    std::complex<T> findMin() const;
    std::complex<T> findMax() const;
};

// ќбъ€вление функции print с переменным числом аргументов
template<typename... Args>
void print(Args... args);

#endif // LAB6_H
