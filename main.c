#include "lexer.h"

int main(int argc, char *argv[])
{
    print_banner();

    if(argc == 2 &&
       strcmp(argv[1], "-help") == 0)
    {
        print_help();
        return SUCCESS;
    }

    if(argc != 2)
    {
        printf(CLR_RED
               "Usage: ./lexer <source_file.c>\n"
               CLR_RESET);

        return FAILURE;
    }

    FILE *fp = fopen(argv[1], "r");

    if(fp == NULL)
    {
        perror("File");

        return FAILURE;
    }

    analyze_file(fp);

    fclose(fp);

    return SUCCESS;
}