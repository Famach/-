#ifndef LAB3_H
#define LAB3_H

class TextManager {
public:
    TextManager(const char* sequence1, const char* sequence2);  // Конструктор
    ~TextManager();  // Деструктор
    void findCommonCharacters() const;  // Метод для поиска общих символов

private:
    char* seq1;
    char* seq2;

    int getStringLength(const char* str) const;  // Определение длины строки
    void copyString(char* dest, const char* src) const;  // Копирование строки
    char toLower(char ch) const;  // Приведение к нижнему регистру
    bool isUpperCaseRussian(char ch) const;  // Проверка на заглавные русские буквы
};

#endif