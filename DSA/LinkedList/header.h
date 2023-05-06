#ifndef HEADER_H
#define HEADER_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct dlistint_s
{
    int n;
    struct dlistint_s *prev;
    struct dlistint_s *next;
} dlistint_t;

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index);
size_t print_dlistint(const dlistint_t *h);
dlistint_t *add_dnodeint(dlistint_t **head, const int n);
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n);
void free_dlistint(dlistint_t *head);
dlistint_t* concatenate(dlistint_t* first_half , dlistint_t* second_half);
dlistint_t* circular_linked(dlistint_t** head , const int index);
int has_loops(dlistint_t* head);
dlistint_t *add_dnodeint_mid(dlistint_t **head , const int index , const int value);
dlistint_t * add_dnodeint_sorted(dlistint_t** head , int value);
dlistint_t *reverse(dlistint_t**head);


#endif/*header_h*/