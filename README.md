# VigoLang

<!-- Title Banner -->
<div style="background-color:#000;color:#fff;padding:25px;border-radius:10px;text-align:center;">
  <h1 style="margin:0;font-size:45px;font-family:'Segoe UI',Roboto,Arial,sans-serif;">VigoLang</h1>
  <p style="margin:8px 0 0;font-size:18px;">A Satirical Urdu-Inspired Programming Language</p>
</div>

---

## Overview

**VigoLang** is a satirical, Urdu-inspired programming language designed as part of a compiler construction project.  
It blends humor with structured programming ideas — featuring its own syntax, keywords, and operators.

---

## Keywords

| Keyword | Meaning |
|:--|:--|
| `ghq` | main function |
| `safehouse` | class definition |
| `nro` | return |
| `order hai` | if |
| `doosra order` | else if |
| `warna vigo` | else |
| `long march` | for loop |
| `jab tak missing` | while loop |
| `deal ho gai` | break |
| `chaltay raho` | continue |
| `farmaan` | print/output |
| `taftish` | input |
| `qaidi no` | integer type |
| `bayania` | string type |
| `float sarkar` | float type |
| `ishara` | character type |
| `namaloom` | void type |
| `ain` | constant |
| `neutral` | true |
| `janwar` | false |

---

## Operators

| Type | Symbol | Description |
|:--|:--|:--|
| Arithmetic | `+:` | Addition |
| Arithmetic | `-:` | Subtraction |
| Arithmetic | `*:` | Multiplication |
| Assignment | `:=` | Assignment |
| Comparison | `=?` | Equal to |
| Comparison | `>?` | Greater than |
| Comparison | `<?` | Less than |

---

## Punctuation

| Symbol | Purpose |
|:--|:--|
| `@` | Statement terminator |
| `{{ }}` | Block start/end |
| `[[ ]]` | Expression start/end |
| `,` | Argument separator |
| `#* *#` | Multi-line comment |
| `###` | Single-line comment |

---

## Example Code

Here’s a small example written in **VigoLang** syntax:

```text
#* Sample VigoLang Program *#

ghq[[ ]] {{
  qaidi no ^count := 5@
  farmaan << "Counting Down"@
  
  jab tak missing(^count >? 0) {{
    farmaan << "Current: " << ^count@
    ^count -: 1@
  }}@
  
  farmaan << "Deal Done!"@
  nro 0@
}}@
