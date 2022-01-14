# Monty

## Synopsis
This project will interpret a monty bytecode file using C, and execute specific functionalities based on the bytecodes passed into the .m file.

## The Monty Language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

## Compililation
Files are compiled using `gcc -Wall -Werror -Wextra -pedantic *.c -o monty`

## Data Structures
```/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
```

```/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
```


## Description of monty code
* `push <int>` - pushes an integer onto the stack
* `pall` - prints all data inside stack
* `pint` - prints data at top of stack
* `pop` - deletes a node on stack
* `pchar` - prints char at top of stack
* `pstr` - prints string at top of stack
* `add` - add two integers at top of stack
* `sub` - subtracts two integers at top of stack
* `div` - divides two integers at top of stack
* `mul` - multiplies two integers at top of stack
* `mod` - returns remainder of divisions between two integers at top of stack