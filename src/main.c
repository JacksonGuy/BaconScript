#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <stdbool.h>

typedef enum {
    // NULL expression
    NONE,

    // Assignment
    EQUALS,

    // Comparison
    ISEQUAL, NOTEQUAL, LESSTHAN, GREATERTHAN,
    LESSTHANEQU, GREATERTHANEQU,

    // Math
    PLUS, MINUS, MULTIPLY, DIVIDE,   
} BinaryOperator;

typedef enum {
    NUMBER,
    STRING
} var_t;

typedef union {
    int intVal;
    float floatVal;
} data_t;

typedef struct {
    var_t type;
    data_t data;
} Variable;

typedef struct {
    Variable val1;
    Variable val2;
    BinaryOperator op;
} BinaryExpr;

typedef enum {
    BINARY,
    STATEMENT,
    FORLOOP,
    WHILELOOP
} ExprType;

typedef struct { 
    ExprType type;      // Type of expression
    void* expr;         // The expression
    ExprNode* next;     // Next node
} ExprNode;

int main(int argc, char** argv) {
    // Check for command line arguments 
    if (argc < 2) {
        printf("Usage: bsc [filename]");
        exit(1);
    }
    
    // Open file
    FILE* fptr;
    fptr = fopen(argv[1], "r");
    if (fptr == NULL) {
        printf("[ERROR] Failed to open file %s", argv[1]);
        exit(1);
    }

    // Read file
    while (!feof(fptr)) {

    }

    fclose(fptr);
    return 0;
}