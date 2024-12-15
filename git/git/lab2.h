#pragma once
#include <iostream>

namespace lab02 {

    class TextProcessor {
    public:
        TextProcessor(char* text);
        void replaceIBMWithIntel();
        void printText();

    private:
        char* text;
    };

} // namespace lab02
