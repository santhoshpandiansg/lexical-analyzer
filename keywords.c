#include "lexer.h"

char *keywords[] =
{
    "int",
    "char",
    "float",
    "double",
    "if",
    "else",
    "while",
    "for",
    "return",
    "void",
    "break",
    "continue",
    "switch",
    "case",
    "struct",
    "typedef",
    "const",
    "static",
    "do",
    "long",
    "short",
    NULL
};

int is_keyword(char *str)
{
    for(int i = 0; keywords[i] != NULL; i++)
    {
        if(strcmp(str, keywords[i]) == 0)
        {
            return 1;
        }
    }

    return 0;
}