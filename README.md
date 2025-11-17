<!-- Title Banner -->
<div align="center" style="background-color:#000;color:#fff;padding:40px;border-radius:12px;margin:20px 0;">
  <h1 style="font-size:60px;margin:0;font-family:'Segoe UI',Roboto,Arial,sans-serif;">
    VigoLang
  </h1>
  <p style="font-size:22px;margin:10px 0 0;">
    A Satirical Urdu-Inspired Programming Language
  </p>
</div>

---

## Overview

**VigoLang** is a satirical, Urdu-inspired programming language designed as part of a compiler construction project.  
It blends humor with structured programming concepts — featuring its own syntax, keywords, and operators.

---

## Keywords

| Keyword | Meaning |
|:--|:--|
| `ghq` | main function |
| `safehouse` | class definition |
| `nro` | return |
| `order_hai` | if |
| `doosra_order` | else if |
| `warna_vigo` | else |
| `long_march` | for loop |
| `jab_tak_missing` | while loop |
| `deal_ho_gai` | break |
| `chaltay_raho` | continue |
| `farmaan` | print/output |
| `taftish` | input |
| `qaidi_no` | integer type |
| `bayania` | string type |
| `float_sarkar` | float type |
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
  qaidi_no ^count := 5@
  farmaan << "Counting Down"@
  
  jab_tak_missing(^count >? 0) {{
    farmaan << "Current: " << ^count@
    ^count -: 1@
  }}@
  
  farmaan << "Deal Done!"@
  nro 0@
}}@
