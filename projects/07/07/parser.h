#ifndef PARSER
#define PARSER

#include "includes.h"

enum instructiontype {
    C_ARITHMETIC = 'A',
    C_PUSH = 'u', 
    C_POP = 'o', 
    C_LABEL = 'L', 
    C_GOTO = 'G', 
    C_IF = 'I', 
    C_FUNCTION = 'F', 
    C_RETURN = 'R', 
    C_CALL = 'C',
    NO_COMMAND = '\0'
};

struct input {
    FILE* stream;
    enum instructiontype commandtype;
    char arg1[SYMBOL_DIM + 1];
    int arg2;
};

struct input inputconstruct(const char* filename);

bool hasmorecommands(const struct input);

void advance(struct input*);

void inputdestroy(struct input*);

enum instructiontype toinstructiontype(const char*);

void cleancommand(struct input*);

void parserignore(FILE*);

void parseerror(FILE*, const int code, const char* desc);

#endif