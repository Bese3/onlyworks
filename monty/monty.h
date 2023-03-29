#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
extern int argc ;
extern char *argv[];
extern stack_t* push(stack_t** head , const int value);
extern size_t display(stack_t* head);
extern void free_t(stack_t* head);
extern stack_t* pop(stack_t** head);
extern stack_t* add(stack_t** head);
extern stack_t* swap(stack_t** head);
int process_lines(stack_t **stack , unsigned int line_numbers);
int process_opcode(stack_t **stack , int line_number , char *opcodes[]);
void m_push(stack_t **stack , unsigned int line_number , char *arg[]);
#endif /*monty_h*/
