# Reverse Polish Notation

Reverse Polish Notation (RPN), also known as postfix notation, is a mathematical notation in which every operator follows all of its operands.

The `reverse-polish-notation` reads and evaluates a mathematical expression written in RPN. It uses a stack to perform arithmetic operations and handles errors gracefully.

## Compile the Script
The following will generate `a.exe` file.
```bash
g++ .\reverse-polish-notation.cpp
```
## Run the Executable
Suppose we have the following RPN expression:
```text
51 49 +
```
The corresponding infix expression is:
```text
51 + 49 = 100
```
If you run the executable, you will get the following.
```bash
> ./a.exe
51
49
+
=
100
```
