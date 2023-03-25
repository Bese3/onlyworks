#ifndef STACKLIST_H
#define STACKLIST_H

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
extern stack_t* push(stack_t** head , const int value);
extern size_t display(stack_t* head);
extern void free_t(stack_t* head);
extern stack_t* pop(stack_t** head);
extern stack_t* add(stack_t** head);
extern stack_t* swap(stack_t** head);

#endif/*stacklist_h*/
