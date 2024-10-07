#include <stdio.h>

#include <iostream>
#include <vector>
#include <string>
#include <cstring>

#include "../include/expressions.h"
#include "../include/parse.h"
#include "../include/compiler.h"

void CleanTokens(std::vector<std::string>& tokens) {
    size_t size = tokens.size();
    for (size_t i = 0; i < size; i++) {
        if (tokens[i] == " " || tokens[i] == "" || tokens[i] == "\0") {
            tokens.erase(tokens.begin() + i);
            i--;
            size--;
        }
    }
}

/**
 * @brief Checks if the given character is in the list 
 * 
 * @param ch the character to check
 * @return true 
 * @return false 
 */
bool CheckChar(const char ch, std::vector<char> list) {
    for (char bchar : list) {
        if (ch == bchar) {
            return true;
        }
    }
    return false;
} 

int main(int argc, char** argv) {
    // Check for command line arguments 
    if (argc < 2) {
        printf("Usage: bsc [filename]\n");
        exit(1);
    }
    
    printf("Compiling: %s\n", argv[1]);

    // Open file
    FILE* fptr;
    fptr = fopen(argv[1], "r");
    if (fptr == NULL) {
        printf("[ERROR] Failed to open file %s", argv[1]);
        exit(1);
    }

    printf("Opened File Successfully\n");

    // Read file
    std::string tokenBuff;
    std::vector<std::string> tokens;
    while (!feof(fptr)) {
        char ch = fgetc(fptr);
        // printf("Current Char: %c\n", ch);

        if (CheckChar(ch, Compiler::BreakChars)) {
            // Add token to array
            tokens.push_back(tokenBuff);

            // Reset token buffer
            tokenBuff = "";
        }
        else if (CheckChar(ch, Compiler::SeparatorChars)) {
            // Add current buffer to tokens
            tokens.push_back(tokenBuff);
            tokenBuff = "";
            
            // Add single character as token
            std::string temp;
            temp.push_back(ch);
            tokens.push_back(temp);
        }
        else {
            tokenBuff.push_back(ch);
        }
    }

    // Remove Unnecessary tokens
    CleanTokens(tokens);

    parseTokens(tokens);
    fclose(fptr);
    return 0;
}