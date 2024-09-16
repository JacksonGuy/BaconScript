#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <stdbool.h>

#include "blib/array.h"

#include "expressions.h"

int main(int argc, char** argv) {
    // Check for command line arguments 
    if (argc < 2) {
        printf("Usage: bsc [filename]");
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
    char tokenBuffer[128] = {0};
    int tokenBufferIndex = 0;
    char** tokens = (char**)create_array(char*);
    while (!feof(fptr)) {
        char ch = fgetc(fptr);
        // printf("Current Char: %c\n", ch);

        if (ch != ' ' && ch != '\n' && ch != EOF) {
            tokenBuffer[tokenBufferIndex++] = ch;
        }
        else {
            // Add token to array
            char* tok = malloc(128);
            strcpy(tok, tokenBuffer);
            array_push(tokens, tok);
            free(tok);
            // printf("Token: %s\n", tokens[array_length(tokens)-1]);

            // Reset token buffer
            strcpy(tokenBuffer, "");
            tokenBufferIndex = 0;
        }
    }
    free(tokenBuffer);

    for (int i = 0; i < array_length(tokens); i++) {
        printf("Token %d: %s\n", i, tokens[i]);
    }
    free_array(tokens);

    fclose(fptr);
    return 0;
}