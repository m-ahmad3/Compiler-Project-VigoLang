Here is the text formatted as a `README.md` file for GitHub.

````markdown:readme.md
# VigoLang - A Satirical Programming Language
---

## Project Overview

This repository contains the lexical analyzer (Phase 1) for VigoLang, a custom-designed satirical programming language that uses Pakistani political terminology as programming constructs. The scanner is built using **Flex** and identifies all unique keywords, operators, punctuation, and literals of the language.

---

## How to Run

### 1. Prerequisites
```bash
# Install Flex and a C compiler
sudo apt-get install flex gcc
````

### 2\. Compile

```bash
# Generate the scanner's C code
flex scanner.l

# Compile the C code
gcc lex.yy.c -o Output -lfl
```

### 3\. Execute

```bash
# Run the scanner on the main test program
./Output test_program.vigo

# Run the scanner on the error test program
./Output test_errors.vigo
```

After running, check `tokens.txt` for the recognized tokens and `errors.txt` for any lexical errors.

-----
