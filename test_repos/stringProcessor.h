#pragma once
#include <string>

// Проста функція для тестування (наприклад, перевертає рядок)
class StringProcessor {
public:
    std::string Process(std::string input) {
        if (input.empty()) return "";
        std::string result = "";
        for (int i = input.length() - 1; i >= 0; i--) {
            result += input[i];
        }
        return result;
    }
};