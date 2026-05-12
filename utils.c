#include "lexer.h"

int is_operator(char ch)
{
    return (ch == '+' ||
            ch == '-' ||
            ch == '*' ||
            ch == '/' ||
            ch == '=' ||
            ch == '<' ||
            ch == '>' ||
            ch == '%' ||
            ch == '&' ||
            ch == '|');
}

int is_delimiter(char ch)
{
    return (ch == ';' ||
            ch == ',' ||
            ch == ':');
}

int is_bracket(char ch)
{
    return (ch == '(' ||
            ch == ')' ||
            ch == '{' ||
            ch == '}' ||
            ch == '[' ||
            ch == ']');
}

void print_banner(void)
{
    printf(CLR_CYAN CLR_BOLD);

    printf("====================================================\n");
    printf("              LEXICAL ANALYZER\n");
    printf("====================================================\n");

    printf(CLR_RESET);
}

void print_help(void)
{
    printf(CLR_YELLOW);

    printf("\nUsage:\n");
    printf("./lexer <source_file.c>\n");

    printf("\nFeatures:\n");

    printf("- Keyword Detection\n");
    printf("- Identifier Detection\n");
    printf("- Numeric Constant Detection\n");
    printf("- Operator Detection\n");
    printf("- Delimiter Detection\n");
    printf("- Preprocessor Detection\n");
    printf("- Basic Error Checking\n");

    printf("\nExample:\n");

    printf("./lexer sample.c\n");

    printf(CLR_RESET);
}