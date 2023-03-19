#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"list.h"



int main(void)
{
    dlistint_t *head;

    head = NULL;
    add_dnodeint(&head, 0);
    add_dnodeint(&head, 1);
    add_dnodeint(&head, 2);
    add_dnodeint(&head, 3);
    add_dnodeint(&head, 4);
    add_dnodeint(&head, 98);
    add_dnodeint(&head, 402);
    add_dnodeint(&head, 1024);
    print_dlistint(head);
    return (EXIT_SUCCESS);
}



dlistint_t *add_dnodeint(dlistint_t **head, const int n){
    dlistint_t *new_node  = (dlistint_t*) malloc(sizeof(dlistint_t));
     if (new_node == NULL){
        printf("cant allocate memory\n");
        return NULL;
     }

    new_node->n = n;
    new_node->next = NULL;
    new_node->prev = NULL;
    if ((*head) == NULL){
        (*head) = new_node;
        return new_node;
    }
    new_node->next = (*head);
    (*head)->prev = new_node;
    (*head) = new_node;
    return new_node;
}
size_t print_dlistint(const dlistint_t *h){
   const dlistint_t *curr = h;
   int i = 0;
    for(curr; curr != NULL; curr = curr->next){
        printf("%d\n" ,curr->n);
        i++;
    } 
    return i;
}