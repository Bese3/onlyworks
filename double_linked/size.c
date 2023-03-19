#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"list.h"



int main(void)
{
    dlistint_t *head;
    dlistint_t *new;
    dlistint_t hello = {8, NULL, NULL};
    size_t n;

    head = &hello;
    new = malloc(sizeof(dlistint_t));
    if (new == NULL)
    {
        printf("Error: Can't malloc\n");
        return (EXIT_FAILURE);
    }
    new->n = 9;
    head->prev = new;
    new->next = head;
    new->prev = NULL;
    head = new;
    n = dlistint_len(head);
    printf("-> %lu elements\n", n);
    free(new);
    return (EXIT_SUCCESS);
}

size_t dlistint_len(const dlistint_t *h){
    const dlistint_t *curr = h;
    int i = 0;
    for (curr; curr != NULL; curr = curr->next){
      i++;
    }
    return i;
}
