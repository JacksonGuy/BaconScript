#pragma once

#include <string>
#include <vector>

namespace Compiler {
    std::vector<char> BreakChars = {
        ' ', '\n', '\0', EOF,
    };
    std::vector<char> SeparatorChars = {
        ';',
        '(', ')', '[', ']',
        '"', '\'',
    };

    std::vector<std::string> statementKeywords = {
        "print",
        "function", "return",
        "if", "else if", "else"
    };
}