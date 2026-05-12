#include "lexer.h"

void classify_token(char *token, int line)
{
    if(strlen(token) == 0)
        return;

    if(is_keyword(token))
    {
        printf("%-25s %-25s %d\n",
               token,
               "Keyword",
               line);
    }
    else if(isdigit(token[0]))
    {
        printf("%-25s %-25s %d\n",
               token,
               "Numeric Constant",
               line);
    }
    else
    {
        printf("%-25s %-25s %d\n",
               token,
               "Identifier",
               line);
    }
}

void analyze_file(FILE *fp)
{
    char ch;
    char token[100];

    int i = 0;
    int line = 1;

    int brace_count = 0;
    int paren_count = 0;

    printf(CLR_GREEN);
    printf("\n============================================================\n");
    printf("%-25s %-25s %s\n",
           "TOKEN",
           "TYPE",
           "LINE");
    printf("============================================================\n");
    printf(CLR_RESET);

    while((ch = fgetc(fp)) != EOF)
    {
        if(ch == '\n')
        {
            line++;
        }

        // preprocessors
        if(ch == '#')
        {
            fgets(token, sizeof(token), fp);

            printf("%-25s %-25s %d\n",
                   "#",
                   "Preprocessor Directive",
                   line);

            continue;
        }

        // identifiers / keywords
        if(isalpha(ch) || ch == '_')
        {
            i = 0;

            token[i++] = ch;

            while((ch = fgetc(fp)) != EOF &&
                  (isalnum(ch) || ch == '_'))
            {
                token[i++] = ch;
            }

            token[i] = '\0';

            classify_token(token, line);

            ungetc(ch, fp);
        }

        // numeric constants
        else if(isdigit(ch))
        {
            i = 0;

            token[i++] = ch;

            while((ch = fgetc(fp)) != EOF &&
                  isdigit(ch))
            {
                token[i++] = ch;
            }

            token[i] = '\0';

            printf("%-25s %-25s %d\n",
                   token,
                   "Numeric Constant",
                   line);

            ungetc(ch, fp);
        }

        // string constants
        else if(ch == '"')
        {
            i = 0;

            token[i++] = ch;

            while((ch = fgetc(fp)) != EOF)
            {
                token[i++] = ch;

                if(ch == '"')
                    break;
            }

            token[i] = '\0';

            printf("%-25s %-25s %d\n",
                   token,
                   "String Constant",
                   line);
        }

        // operators
        else if(is_operator(ch))
        {
            token[0] = ch;
            token[1] = '\0';

            printf("%-25s %-25s %d\n",
                   token,
                   "Operator",
                   line);
        }

        // delimiters
        else if(is_delimiter(ch))
        {
            token[0] = ch;
            token[1] = '\0';

            printf("%-25s %-25s %d\n",
                   token,
                   "Delimiter",
                   line);
        }

        // brackets
        else if(is_bracket(ch))
        {
            token[0] = ch;
            token[1] = '\0';

            if(ch == '{')
                brace_count++;

            else if(ch == '}')
                brace_count--;

            else if(ch == '(')
                paren_count++;

            else if(ch == ')')
                paren_count--;

            printf("%-25s %-25s %d\n",
                   token,
                   "Bracket",
                   line);
        }
    }

    printf(CLR_CYAN);
    printf("============================================================\n");
    printf(CLR_RESET);

    // error checking
    if(brace_count != 0)
    {
        printf(CLR_RED
               "ERROR: Unmatched braces detected\n"
               CLR_RESET);
    }

    if(paren_count != 0)
    {
        printf(CLR_RED
               "ERROR: Unmatched parentheses detected\n"
               CLR_RESET);
    }
}