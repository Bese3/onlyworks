#ifndef HANOI_H
#define HANOI_H



#include<stdio.h>
#include<stdlib.h>
#include <stddef.h>
#include<time.h>
typedef struct dlistint_s
{
    int n;
    struct dlistint_s *prev;
    struct dlistint_s *next;
} dlistint_t;

dlistint_t* push(dlistint_t** head , const int value);
dlistint_t *pop(dlistint_t** head);
dlistint_t *add_dnodeint(dlistint_t **head, const int n);
int hanoi();
size_t print(dlistint_t* head);
void free_t(dlistint_t* head);

#endif