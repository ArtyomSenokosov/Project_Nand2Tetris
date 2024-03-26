#include <stdio.h>
#include <stdlib.h>

#include "Parser.h"
#include "Code.h"
#include "SymbolTable.h"

int main(int argc, char **argv) {

    if (argc > 1) {
        Parser parser;
        initializeParser(&parser, argv[1]);

        SymbolTable symbolTable;
        initializeTable(&symbolTable);

        int rom = 0;
        while (hasMoreCommands(&parser)) {
            switch (commandType(&parser)) {
                case A_COMMAND:
                case C_COMMAND:
                    rom++;
                    break;
                case L_COMMAND:;
                    char *symbolString = symbol(&parser);
                    addEntry(&symbolTable, ++symbolString, rom);
                    break;
                case COMMENT:
                    break;
                case SKIP:
                    break;
            }
            advance(&parser);
        }

        restartReading(&parser, argv[1]);
        while (hasMoreCommands(&parser)) {
            switch (commandType(&parser)) {
                case A_COMMAND:;
                    char *symbolString = symbol(&parser);
                    char *symbolB;
                    if (symbolString[0] == '1')
                        symbolB = intToBin(atoi(++symbolString));
                    else
                        symbolB = intToBin(getAddress(&symbolTable, ++symbolString));

                    writeAInstruction(&parser, symbolB);

                    break;
                case C_COMMAND:;
                    char *destString = dest(&parser);
                    char *destB = destBinary(destString);

                    char *compString = comp(&parser);
                    char *compB = compBinary(compString);

                    char *jumpString = jump(&parser);
                    char *jumpB = jumpBinary(jumpString);

                    writeCInstruction(&parser, compB, destB, jumpB);

                    break;
                case L_COMMAND:
                    break;
                case COMMENT:
                    break;
                case SKIP:
                    break;
            }
            advance(&parser);
        }
    } else {
        printf("No .asm file was specified\n");
        return EXIT_FAILURE;
    }
}