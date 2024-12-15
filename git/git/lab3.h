#ifndef LAB3_H
#define LAB3_H

class TextManager {
public:
    TextManager(const char* sequence1, const char* sequence2);  // �����������
    ~TextManager();  // ����������
    void findCommonCharacters() const;  // ����� ��� ������ ����� ��������

private:
    char* seq1;
    char* seq2;

    int getStringLength(const char* str) const;  // ����������� ����� ������
    void copyString(char* dest, const char* src) const;  // ����������� ������
    char toLower(char ch) const;  // ���������� � ������� ��������
    bool isUpperCaseRussian(char ch) const;  // �������� �� ��������� ������� �����
};

#endif