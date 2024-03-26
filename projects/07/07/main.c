#include"includes.h"

#include "parser.h"
#include "codewriter.h"

struct input vm_program_setup(int argc, char* argv[]);

char* to_output_filename(const char* input_name, const char* output_ext);

FILE* output_setup(const char* filename);

void translate(struct input* i, struct output* o);


int main(int argc, char* argv[])
{
    struct input vm_program = vm_program_setup(argc, argv);
    char* output_filename = to_output_filename(argv[1], ".asm");
    struct output asm_program = outputconstruct(output_filename);

    setfilename(&asm_program, argv[1]);
    translate(&vm_program, &asm_program);

    inputdestroy(&vm_program);
    outputdestroy(&asm_program);
    printf("Generazione di '%s' riuscita.\n", output_filename);
    free(output_filename);
}

struct input vm_program_setup(int argc, char* argv[])
{
    const int arg_min = 2;
    if (argc != arg_min)
    {
        fprintf(stderr,
            "Numero di parametri (%i) errato (diverso da %i).\n",
            argc, arg_min);
        exit(-1);
    }
    return inputconstruct(argv[1]);
}

char* to_output_filename(const char* input_name, const char* output_ext)
{
    const char delim = '.';
    size_t str_len = strlen(input_name), i = str_len;
    while (i > 0 && input_name[i] != delim)
        --i;
    if (!i)
        i = str_len;

    const size_t ext_len = strlen(output_ext);
    char* res = malloc(sizeof(char) * (i + ext_len + 1));
    strcpy(strncpy(res, input_name, i) + i, output_ext);
    return res;
}

void translate(struct input* i, struct output* o)
{
    while (hasmorecommands(*i))
    {
        advance(i);
        fprintf(o->stream, "// instruction: %c %s %i\n", i->commandtype, i->arg1, i->arg2);
        writecommand(o, i->commandtype, i->arg1, i->arg2);
    }
}