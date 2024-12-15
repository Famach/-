#include "lab3.h"
#include <iostream>
#include <set>  // ��� std::set


    // ����� ��� ���������� ������� � ������� ��������
    char TextManager::toLower(char ch) const {
        if (ch >= 'A' && ch <= 'Z') {
            return ch + ('a' - 'A');  // ���������� ���������� ���� � ������� ��������
        }
        if (isUpperCaseRussian(ch)) {
            return ch + ('�' - '�');  // ���������� ������� ���� � ������� ��������
        }
        return ch;  // ��������� ������� �������� ��� ���������
    }

    // ����� ��� ��������, �������� �� ������ ��������� ������� ������
    bool TextManager::isUpperCaseRussian(char ch) const {
        return (ch >= '�' && ch <= '�') || ch == '�';  // �������� ����� �
    }

    // ����� ��� ����������� ����� ������
    int TextManager::getStringLength(const char* str) const {
        int length = 0;
        while (str[length] != '\0') {
            length++;
        }
        return length;
    }

    // ����� ��� ����������� ������
    void TextManager::copyString(char* dest, const char* src) const {
        int i = 0;
        while (src[i] != '\0') {
            dest[i] = src[i];
            i++;
        }
        dest[i] = '\0';  // ���������� ������
    }

    // ����������� � ������������ ���������� ������
    TextManager::TextManager(const char* sequence1, const char* sequence2) {
        int len1 = getStringLength(sequence1);
        int len2 = getStringLength(sequence2);

        seq1 = new char[len1 + 1];
        seq2 = new char[len2 + 1];

        copyString(seq1, sequence1);
        copyString(seq2, sequence2);
    }

    // ���������� ��� ������������ ������
    TextManager::~TextManager() {
        delete[] seq1;
        delete[] seq2;
    }

    // ����� ��� ������ � ������ ����� ��������
    void TextManager::findCommonCharacters() const {
        std::set<char> found;  // ��������� ��� ������������ ��� ���������� ��������

        for (int i = 0; seq1[i] != '\0'; i++) {
            char ch1 = toLower(seq1[i]);  // ���������� � ������� ��������
            for (int j = 0; seq2[j] != '\0'; j++) {
                char ch2 = toLower(seq2[j]);  // ���������� � ������� ��������
                if (ch1 == ch2 && found.find(ch1) == found.end()) {
                    std::cout << seq1[i] << ' ';  // ����� ������������� �������
                    found.insert(ch1);  // ��������� ������ � ���������
                    break;
                }
            }
        }
        std::cout << std::endl;
    }

