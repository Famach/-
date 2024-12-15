#include "lab2.h"

namespace lab02 {

    TextProcessor::TextProcessor(char* inputText) : text(inputText) {}

    void TextProcessor::replaceIBMWithIntel() {
        char* pos = text;
        const char* oldWord = "IBM";
        const char* newWord = "Intel";
        int oldLen = 3;
        int newLen = 5;

        while (*pos != '\0') {
            char* found = pos;
            bool match = true;
            for (int i = 0; i < oldLen; i++) {
                if (*(found + i) != oldWord[i]) {
                    match = false;
                    break;
                }
            }

            if (match) {
                for (char* movePtr = pos + newLen; movePtr >= pos + oldLen; movePtr--) {
                    *movePtr = *(movePtr - (newLen - oldLen));
                }
                for (int i = 0; i < newLen; i++) {
                    *(pos + i) = newWord[i];
                }
                pos += newLen;
            }
            else {
                pos++;
            }
        }
    }

    void TextProcessor::printText() {
        std::cout << text << std::endl;
    }

} // namespace lab02
