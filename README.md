<div align="center">

# 🏛️ VigoLang

### A Satirical Pakistani Political Programming Language

[![Phase 1](https://img.shields.io/badge/Phase%201-Lexical%20Analyzer-green?style=for-the-badge)](./Phase_1/)
[![Phase 2](https://img.shields.io/badge/Phase%202-Syntax%20Analyzer-blue?style=for-the-badge)](./Phase_2/)
[![License](https://img.shields.io/badge/License-MIT-yellow?style=for-the-badge)](./LICENSE)

*A satirical, Urdu-inspired programming language that uses Pakistani political terminology as programming constructs.*

---

**Compiler Construction Project**  
University of Central Punjab | Fall 2025

</div>

## 📖 Overview

VigoLang is an educational programming language designed for learning compiler construction principles. It features a unique syntax inspired by contemporary Pakistani political discourse, transforming political terminology into programming constructs.

> ⚠️ **Disclaimer:** This language is purely satirical and academic. The creator has no political affiliation or association with any political party or organization.

## ✨ Features

| Feature                  | Description                                                    |
| ------------------------ | -------------------------------------------------------------- |
| 🎭 **Satirical Keywords** | 20 unique keywords from Pakistani political terminology        |
| 🔧 **Custom Operators**   | Unique operators like `+:`, `-:`, `*:`, `:=`, `=?`, `>?`, `<?` |
| 📝 **Distinctive Syntax** | Double braces `{{ }}`, double brackets `[[ ]]`, `@` terminator |
| 🎯 **Identifier Prefix**  | All variables start with `^` for zero keyword conflicts        |
| 🔍 **Complete Compiler**  | Lexical analyzer (Phase 1) + Syntax analyzer (Phase 2)         |

## 🗂️ Project Structure

```
Compiler_Project/
├── 📁 Phase_2/                    # Syntax Analyzer (Phase 2)
│   ├── parser.y                   # YACC parser specification
│   ├── scanner.l                  # Modified scanner for parser
│   ├── valid_program.vigo         # Valid test program
│   ├── invalid_program.vigo       # Invalid test program (error demo)
│   ├── Phase_2_Report.tex         # LaTeX documentation
│   └── Phase_2_Report.pdf         # Compiled report
│
├── 📁 Test_With_Explicit_Errors/  # Error testing
│
├── scanner.l                      # Phase 1: Flex scanner specification
├── test_program.vigo              # Phase 1: Sample VigoLang program
├── tokens.txt                     # Phase 1: Tokenization output
├── errors.txt                     # Phase 1: Error log
├── PHASE_1_REPORT.pdf             # Phase 1: Compiled report
├── DEMO_VigoLang.mp4              # Demo video
├── LICENSE                        # MIT License
└── README.md                      # This file
```

## 🚀 Quick Start

### Prerequisites

- GCC Compiler
- Flex (Lexical Analyzer Generator)
- Bison (Parser Generator)

### Phase 1: Lexical Analysis

```bash
# Compile the scanner (from root directory)
flex scanner.l
gcc lex.yy.c -o vigo_scanner -lfl

# Run the scanner
./vigo_scanner test_program.vigo
```

### Phase 2: Syntax Analysis

```bash
cd Phase_2

# Generate parser and scanner
flex scanner.l
yacc -d parser.y

# Compile
gcc lex.yy.c y.tab.c -o vigolang_parser -lfl

# Test with valid program
./vigolang_parser valid_program.vigo

# Test with invalid program (see error handling)
./vigolang_parser invalid_program.vigo
```

## 📚 Language Reference

### Keywords (20 Total)

| Keyword           | Purpose          | Standard Equivalent |
| ----------------- | ---------------- | ------------------- |
| `ghq`             | Main function    | `main`              |
| `safehouse`       | Class definition | `class`             |
| `nro`             | Return statement | `return`            |
| `order_hai`       | If condition     | `if`                |
| `doosra_order`    | Else-if          | `else if`           |
| `warna_vigo`      | Else             | `else`              |
| `long_march`      | For loop         | `for`               |
| `jab_tak_missing` | While loop       | `while`             |
| `deal_ho_gai`     | Break            | `break`             |
| `chaltay_raho`    | Continue         | `continue`          |
| `farmaan`         | Print/Output     | `print`             |
| `taftish`         | Input            | `input`             |
| `qaidi_no`        | Integer type     | `int`               |
| `bayania`         | String type      | `string`            |
| `float_sarkar`    | Float type       | `float`             |
| `ishara`          | Character type   | `char`              |
| `namaloom`        | Void type        | `void`              |
| `ain`             | Constant         | `const`             |
| `neutral`         | Boolean true     | `true`              |
| `janwar`          | Boolean false    | `false`             |

### Operators

| Operator | Description    | Example           |
| -------- | -------------- | ----------------- |
| `+:`     | Addition       | `^a +: ^b`        |
| `-:`     | Subtraction    | `^x -: 5`         |
| `*:`     | Multiplication | `^p *: ^q`        |
| `:=`     | Assignment     | `^x := 10`        |
| `=?`     | Equality       | `^x =? ^y`        |
| `>?`     | Greater than   | `^a >? ^b`        |
| `<?`     | Less than      | `^x <? 10`        |
| `<<`     | Output stream  | `farmaan << ^msg` |
| `>>`     | Input stream   | `taftish >> ^val` |

### Punctuation

| Symbol  | Description           |
| ------- | --------------------- |
| `@`     | Statement terminator  |
| `{{ }}` | Block delimiters      |
| `[[ ]]` | Expression delimiters |
| `,`     | Separator             |
| `#* *#` | Multi-line comment    |
| `###`   | Single-line comment   |

## 💻 Sample Program

```
#* VigoLang Factorial Calculator *#

ghq[[ ]] {{
    qaidi_no ^num := 5@
    qaidi_no ^fact := 1@
    qaidi_no ^i := 1@
    
    farmaan << "Calculating factorial"@
    
    order_hai [[ ^num <? 0 ]] {{
        farmaan << "Error: Negative"@
    }}
    warna_vigo {{
        long_march [[ ^i := 1@ ^i <? ^num +: 1@ ^i := ^i +: 1 ]] {{
            ^fact := ^fact *: ^i@
        }}
    }}
    
    farmaan << ^fact@
    nro 0@
}}
```

## 📊 Parser Output

### Successful Parse
```
╔════════════════════════════════════════════════════════╗
║         VigoLang Syntax Analyzer v2.0                  ║
╚════════════════════════════════════════════════════════╝

   ✓ Variable declaration parsed
   ✓ Conditional statement (order_hai) parsed
   ✓ For loop (long_march) parsed
   ✓ Program structure validated

╔════════════════════════════════════════════════════════╗
║         SYNTAX ANALYSIS SUCCESSFUL!                    ║
╚════════════════════════════════════════════════════════╝
```

### Syntax Error
```
╔════════════════════════════════════════════════════════╗
║              SYNTAX ERROR DETECTED                     ║
╚════════════════════════════════════════════════════════╝
  Line Number:    5
  Error Type:     syntax error
  Found Token:    'farmaan'
```

## 📝 Documentation

- [Phase 1 Report](./PHASE_1_REPORT.pdf) - Lexical Analyzer Documentation
- [Phase 2 Report](./Phase_2/Phase_2_Report.pdf) - Syntax Analyzer Documentation

## 🎥 Demo

See the [demo video](./DEMO_VigoLang.mp4) for a complete walkthrough of the lexical analyzer.

## 👨‍💻 Author

**Muhammad Ahmad**  
Registration: L1F22BSCS0634  
University of Central Punjab  
Compiler Construction - Fall 2025

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](./LICENSE) file for details.

---

<div align="center">

Made with ❤️ for Compiler Construction

*"Where politics meets programming"*

</div>
