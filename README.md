# APC — Arbitrary Precision Calculator

**Table of Contents**  
- [About](#about)  
- [Features](#features)  
- [Motivation & Use Cases](#motivation--use-cases)  
- [Architecture & Design](#architecture--design)  
- [Getting Started](#getting-started)  
  - [Prerequisites](#prerequisites)  
  - [Building](#building)  
  - [Running](#running)  
- [Usage & Examples](#usage--examples)  
- [Limitations & Future Work](#limitations--future-work)  
- [Contributing](#contributing)  
- [License](#license)

---

## About

APC (Arbitrary Precision Calculator) is a C-based tool that allows arithmetic operations on numbers of **any size or precision**, surpassing the limits of built-in types like `int`, `float`, or `double`.  
It uses dynamic data structures (e.g. linked lists) to represent big numbers internally.

The repository contains modules for addition, subtraction, multiplication, division, and the necessary scaffolding (headers, makefile, etc.).  
Main source files: `apc.c`, `apc.h`, `addition.c`, `division.c`, `multiplication.c`, `subtraction.c`, plus glue code like `main.c` & `makefile`.  
It also includes intermediate object files (though you might remove them) and possibly a simple demonstration file named `addition.c` (check what exactly that is). :contentReference[oaicite:0]{index=0}

---

## Features

- Operates on integers (and possibly decimal / fractional parts, depending on implementation).  
- Supports basic operations:  
  - Addition (`+`)  
  - Subtraction (`-`)  
  - Multiplication (`*`)  
  - Division (`/`)  
- Internally handles big numbers by slicing them into manageable chunks stored in nodes (e.g. via linked list).  
- Edge-case handling (e.g. zero operands, different lengths) is expected.  
- Simple CLI interface to accept user input with operator embedded (e.g. “12345 + 67890”).  

From background reading: similar APC projects also handle modulus (%) and exponentiation (power ^). :contentReference[oaicite:1]{index=1}  

---

## Motivation & Use Cases

Why build APC?

- Standard data types (in C) overflow beyond certain limits. This tool bypasses that.  
- Useful in cryptography, big-integer math, arbitrary-precision calculations (e.g. large factorials, high-precision constants).  
- Great learning project combining data structures + algorithmic handling of carries, borrowing, etc.  
- Educational tool for mastering “big-num arithmetic.”  

---

## Architecture & Design

Here’s how APC is (or should be) structured conceptually:

- **Data Representation**  
  - Big numbers are broken (sliced) into units (e.g. chunks fitting in `int`).  
  - Each unit is stored in a node of a doubly-linked list (or similar).  
  - Nodes track segments of the full big number.  

- **Modules / Components**  
  - `addition.c`, `subtraction.c`, `multiplication.c`, `division.c` — each handles one arithmetic operation.  
  - `apc.h` — declarations, shared data types, utilities.  
  - `apc.c` / `main.c` — parsing input, dispatching operations, handling I/O, error checking.  
  - `makefile` — build orchestration.

- **Algorithmic Notes**  
  - Propagate carry / borrow across nodes.  
  - Manage unequal lengths (one number longer than the other).  
  - Handling zeros (if one operand is “0”, return the other directly).  
  - Possibly normalization / trimming nodes with leading zeros.

From project descriptions elsewhere (e.g. Emertxe), operations may also consider decimal input, modulus, power, etc. :contentReference[oaicite:2]{index=2}  

---

## Getting Started

### Prerequisites

- GCC (or another C compiler)  
- `make`  
- Basic familiarity with terminal / command line  
- (Optional) valgrind or memory-checking tool to verify correctness  

### Building

```bash
git clone https://github.com/manirul13/APC.git
cd APC
make
The makefile should generate the executable (e.g. apc, or whatever target is set in makefile).

If object files are already present, you may want to make clean first.

Running
Once built:

bash
Copy code
./apc
Then input a big-number expression, e.g.:

Copy code
12345678901234567890 + 98765432109876543210
It should parse, compute, and output the result.

You may get prompts to continue (y/n) or the program may loop until exit.

Usage & Examples
Input	Operation	Sample Output
12345 + 67890	Addition	80235
1000000 - 1	Subtraction	999999
12345 * 678	Multiplication	8369010
1000000 / 5	Division	200000
0 + 12345	Edge-case	12345

You can test with more extreme cases (100s or 1000s of digits) to see how it handles scaling.

Limitations & Future Work
May not support fractional / decimal numbers (depending on implementation).

No or limited support for modulus or exponentiation (unless added).

Performance will degrade for extremely large numbers (e.g. millions of digits).

Memory leaks, edge-case bugs, and carry/borrow errors may exist — needs testing.

User interface is minimal; no expression parsing precedence beyond simple operator.

Could expand: support negative numbers, parentheses, floating points, power operator, modular arithmetic, etc.

Contributing
If you want to pitch in:

Fork the repo.

Create a new branch: git checkout -b feature/your-feature.

Add your feature, tests, and documentation.

Submit a pull request, explaining your changes.

Ensure you don’t break existing functionality.

Focus areas for help:

Add support for more operations (modulus, power).

Add better parsing (multiple operators, parentheses).

Optimize performance (use better algorithms for multiplication, division).

Add memory checks / tests / benchmarking.