#include "lab3.h"
#include <iostream>
#include <set>  // Для std::set


    // Метод для приведения символа к нижнему регистру
    char TextManager::toLower(char ch) const {
        if (ch >= 'A' && ch <= 'Z') {
            return ch + ('a' - 'A');  // Приведение английских букв к нижнему регистру
        }
        if (isUpperCaseRussian(ch)) {
            return ch + ('а' - 'А');  // Приведение русских букв к нижнему регистру
        }
        return ch;  // Остальные символы остаются без изменений
    }

    // Метод для проверки, является ли символ заглавной русской буквой
    bool TextManager::isUpperCaseRussian(char ch) const {
        return (ch >= 'А' && ch <= 'Я') || ch == 'Ё';  // Включаем букву Ё
    }

    // Метод для определения длины строки
    int TextManager::getStringLength(const char* str) const {
        int length = 0;
        while (str[length] != '\0') {
            length++;
        }
        return length;
    }

    // Метод для копирования строки
    void TextManager::copyString(char* dest, const char* src) const {
        int i = 0;
        while (src[i] != '\0') {
            dest[i] = src[i];
            i++;
        }
        dest[i] = '\0';  // Завершение строки
    }

    // Конструктор с динамическим выделением памяти
    TextManager::TextManager(const char* sequence1, const char* sequence2) {
        int len1 = getStringLength(sequence1);
        int len2 = getStringLength(sequence2);

        seq1 = new char[len1 + 1];
        seq2 = new char[len2 + 1];

        copyString(seq1, sequence1);
        copyString(seq2, sequence2);
    }

    // Деструктор для освобождения памяти
    TextManager::~TextManager() {
        delete[] seq1;
        delete[] seq2;
    }

    // Метод для поиска и вывода общих символов
    void TextManager::findCommonCharacters() const {
        std::set<char> found;  // Множество для отслеживания уже выведенных символов

        for (int i = 0; seq1[i] != '\0'; i++) {
            char ch1 = toLower(seq1[i]);  // Приведение к нижнему регистру
            for (int j = 0; seq2[j] != '\0'; j++) {
                char ch2 = toLower(seq2[j]);  // Приведение к нижнему регистру
                if (ch1 == ch2 && found.find(ch1) == found.end()) {
                    std::cout << seq1[i] << ' ';  // Вывод оригинального символа
                    found.insert(ch1);  // Добавляем символ в множество
                    break;
                }
            }
        }
        std::cout << std::endl;
    }

