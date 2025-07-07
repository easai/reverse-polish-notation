# Reverse Polish Notation

**Reverse Polish Notation (RPN)**, also known as *postfix notation*, is a mathematical notation in which each operator follows its operands. This eliminates the need for parentheses to dictate operation precedence, making it especially well-suited for stack-based evaluation.

The `reverse-polish-notation` program reads and evaluates mathematical expressions written in RPN. It uses a stack-based algorithm to perform arithmetic operations and provides basic error handling for invalid input.

---

## Compile the Program

To compile the source file and generate an executable (`a.exe`), use the following command:

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
