# 🔤 Lexical Analyzer

> A compiler-style Lexical Analyzer written in pure C that scans source code and classifies tokens such as keywords, identifiers, operators, delimiters, constants, and brackets.

![Language](https://img.shields.io/badge/Language-C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Platform](https://img.shields.io/badge/Platform-Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black)
![Build](https://img.shields.io/badge/Build-GCC-A42E2B?style=for-the-badge&logo=gnu&logoColor=white)
![Compiler](https://img.shields.io/badge/Concept-Compiler_Design-blue?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)

---

# 📌 What is a Lexical Analyzer?

A **Lexical Analyzer** (Lexer) is the first phase of a compiler.

It reads source code character-by-character and converts it into meaningful tokens that later compiler stages can process.

Example:

## Input Source Code

```c
int sum = 10 + 20;
```

## Tokenized Output

```text
int      → Keyword
sum      → Identifier
=        → Operator
10       → Numeric Constant
+        → Operator
20       → Numeric Constant
;        → Delimiter
```

This process is called **Lexical Analysis** or **Tokenization**.

---

# 🧠 How It Works

```text
Source File
     ↓
Character-by-Character Scanning
     ↓
Token Extraction
     ↓
Token Classification
     ↓
Formatted Token Table Output
```

The analyzer uses:

- `fgetc()`
- character classification
- token buffering
- keyword matching
- operator recognition
- delimiter parsing

to simulate compiler front-end behavior.

---

# 🗂️ Project Structure

```text
lexical-analyzer/
├── main.c          # Main driver and CLI handling
├── lexer.c         # Core lexical analysis logic
├── utils.c         # Utility/helper functions
├── keywords.c      # Keyword detection
├── lexer.h         # Structures, declarations, macros
├── Makefile        # Build automation
├── sample.c        # Sample C program for testing
├── .gitignore
├── README.md
└── screenshots/
```

---

# ⚙️ Features

## Token Detection

The lexer detects:

| Token Type | Example |
|---|---|
| Keywords | `int`, `return`, `while` |
| Identifiers | `sum`, `main` |
| Numeric Constants | `100`, `25` |
| String Constants | `"Hello"` |
| Operators | `+`, `-`, `=` |
| Delimiters | `;`, `,` |
| Brackets | `()`, `{}` |
| Preprocessor Directives | `#include` |

---

# 🚀 Getting Started

## Prerequisites

- GCC Compiler
- Linux / Unix Environment

---

# ⚒️ Build Project

## Using Makefile

```bash
make
```

---

## Manual Compilation

```bash
gcc main.c lexer.c utils.c keywords.c -Wall -Wextra -Werror -std=c11 -o lexer
```

---

# ▶️ Run the Analyzer

```bash
./lexer sample.c
```

---

# 📖 Help Menu

```bash
./lexer -help
```

### Output

```text
Usage:
./lexer <source_file.c>

Features:
- Keyword Detection
- Identifier Detection
- Numeric Constant Detection
- Operator Detection
- Delimiter Detection
- Preprocessor Detection
```

---

# 💻 Sample Input

## `sample.c`

```c
#include <stdio.h>

int main()
{
    int sum = 3 + 2;

    printf("Hello World");

    return 0;
}
```

---

# 📤 Sample Output

```text
============================================================
TOKEN                     TYPE                      LINE
============================================================

#                         Preprocessor Directive    1
int                       Keyword                  3
main                      Identifier               3
(                         Bracket                  3
)                         Bracket                  3
{                         Bracket                  4
int                       Keyword                  5
sum                       Identifier               5
=                         Operator                 5
3                         Numeric Constant         5
+                         Operator                 5
2                         Numeric Constant         5
;                         Delimiter                5
printf                    Identifier               7
"Hello World"             String Constant          7
return                    Keyword                  9
0                         Numeric Constant         9
}                         Bracket                  10
```

---

# 🔍 Token Classification Logic

## Keywords

Stored in an internal keyword table:

```c
char *keywords[] =
{
    "int",
    "char",
    "float",
    "if",
    "else",
    ...
};
```

---

## Identifier Detection

Rules:

- Starts with alphabet or `_`
- Can contain:
  - alphabets
  - digits
  - underscores

Example:

```text
valid_name
sum1
_temp
```

---

## Numeric Constant Detection

Example:

```text
123
4567
99999
```

---

## Operator Detection

Detected operators:

```text
+  -  *  /  =  <  >  %  &  |
```

---

# ⚠️ Error Detection

The analyzer performs basic syntax validation:

## Unmatched Braces

Example:

```c
int main(
{
```

Output:

```text
ERROR: Unmatched parentheses detected
```

---

## Unterminated Structures

Detects:
- missing `)`
- missing `}`
- incomplete token structures

---

# 📋 Core Concepts Demonstrated

| Concept | Usage |
|---|---|
| Compiler Design | Lexical analysis |
| File Handling | Source code scanning |
| Character Processing | Token parsing |
| Tokenization | Compiler frontend |
| String Manipulation | Token classification |
| CLI Design | Command-line utility |
| Parsing Logic | Token extraction |
| Error Detection | Syntax validation |

---

# 📊 Internal Workflow

```text
Read Character
      ↓
Classify Character Type
      ↓
Build Token
      ↓
Identify Token Category
      ↓
Print Token Information
```

---

# ⚡ Time Complexity

| Operation | Complexity |
|---|---|
| File Scan | O(n) |
| Token Classification | O(k) |
| Keyword Search | O(number_of_keywords) |

Where:
- `n` = source file size
- `k` = token length

---

# ⚠️ Limitations

- Basic compiler implementation only
- No syntax tree generation
- No semantic analysis
- Limited operator combinations
- No floating-point token parsing yet

---

# 🚀 Future Improvements

- Symbol table generation
- Syntax analyzer (Parser)
- AST generation
- Multi-character operator handling
- Floating-point constants
- Comment parsing
- Escape sequence handling
- HTML token reports
- Syntax highlighting
- Mini compiler frontend

---

# 👨‍💻 Author

**Santhosh Pandian SG**  
Embedded Systems Engineer | Emertxe ECEP Trainee

[![LinkedIn](https://img.shields.io/badge/LinkedIn-Connect-0077B5?style=flat&logo=linkedin)](https://linkedin.com/in/santhoshpandian06)
[![GitHub](https://img.shields.io/badge/GitHub-Follow-181717?style=flat&logo=github)](https://github.com/santhoshpandiansg)

---

# 📄 License

This project is licensed under the MIT License.
