#pragma once

typedef enum {
    // NULL expression
    NONE,

    // Assignment
    EQUALS,

    // Comparison
    ISEQUAL, NOTEQUAL, LESSTHAN, GREATERTHAN,   // ==, !=, <, >
    LESSTHANEQU, GREATERTHANEQU,                // <=, >=

    // Math
    PLUS, MINUS, MULTIPLY, DIVIDE,              // +, -, *, =
    PLUSEQU, MINUSEQU, MULTIEEQU, DIVIDEEQU     // +=, -=, *=, /=
} BinaryOperator;

typedef enum {
    NUMBER,
    STRING
} var_t;

typedef union {
    int intVal;
    float floatVal;
    char* strVal;
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
    STATEMENT,
    BINARY,
    FORLOOP,
    WHILELOOP
} ExprType;

typedef struct ExprNode { 
    ExprType type;              // Type of expression
    void* expr;                 // The expression
    struct ExprNode* next;      // Next node
} ExprNode;