# Monty ByteCodes Interpreter

This project implements an interpreter for Monty ByteCodes files written in C.

## Usage

Compile using:
```
gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
```

Run the Monty interpreter:
```
./monty <filename>
```

For Brainf*ck scripts, navigate to the `bf` directory and compile & run the `bf_interpreter.c` file.

## Implemented Opcodes

- push
- pall
- pint
- pop
- swap
- add
- nop

## Brainf*ck Interpreter

A simple Brainf*ck interpreter is also included in the `bf` directory.

## Error and Comment Handling

The Monty interpreter handles errors such as unknown instructions and provides clear error messages. Lines starting with the `#` character are considered comments and are ignored.
