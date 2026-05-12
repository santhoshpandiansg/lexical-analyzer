#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SUCCESS 1
#define FAILURE 0

// ANSI COLORS
#define CLR_RESET   "\033[0m"
#define CLR_RED     "\033[31m"
#define CLR_GREEN   "\033[32m"
#define CLR_YELLOW  "\033[33m"
#define CLR_BLUE    "\033[34m"
#define CLR_CYAN    "\033[36m"
#define CLR_BOLD    "\033[1m"

typedef struct
{
    char token[100];
    char type[50];
    int line;

} Token;

// keyword functions
int is_keyword(char *str);

// lexer functions
void analyze_file(FILE *fp);
void classify_token(char *token, int line);

// utility functions
int is_operator(char ch);
int is_delimiter(char ch);
int is_bracket(char ch);

void print_banner(void);
void print_help(void);

#endif