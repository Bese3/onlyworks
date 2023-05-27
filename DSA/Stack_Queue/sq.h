#ifndef SQ_H
#define SQ_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stack_s
{
        int n;
        struct stack_s *next;
} stack_t;

stack_t* stack_1;
stack_t* stack_2;
void enqueue(int data);
void dequeue();
stack_t* push(stack_t** head , const int value);
void free_t(stack_t* head);
stack_t* pop(stack_t** head);


#endif/*sq_h*/