#ifndef CODEWRITER
#define CODEWRITER

#include "includes.h"

#include "parser.h"

struct output {
    FILE* stream;
    char currentinputfile[SYMBOL_DIM + 1],
        currentfunction[SYMBOL_DIM + 1];
    int anonlabels;
};

struct output outputconstruct(const char* filename);

void setfilename(struct output*, const char* inputfilename);

void writecommand(struct output*, const enum instructiontype,
    const char* arg1, const int arg2);

void outputdestroy(struct output*);

void writecomparison(struct output*, const char* cmp);

void writearithmetic(struct output*, const char* arg1);

void writepush(struct output*, const char* arg1, const int arg2);

void writepop(struct output*, const char* arg1, const int arg2);

void writelabel(struct output*, const char* arg1);

void writegoto(struct output*, const char* arg1);

void writeif(struct output*, const char* arg1);

void writecall(struct output*, const char* arg1, const int arg2);

void writereturn(struct output*);

void writefunction(struct output*, const char* arg1, const int arg2);

#endif