#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"list.h"


int main(void)
{
    dlistint_t *head;
    dlistint_t *node;

    head = NULL;
    add_dnodeint_end(&head, 0);
    add_dnodeint_end(&head, 1);
    add_dnodeint_end(&head, 2);
    add_dnodeint_end(&head, 3);
    add_dnodeint_end(&head, 4);
    add_dnodeint_end(&head, 98);
    add_dnodeint_end(&head, 402);
    add_dnodeint_end(&head, 1024);
    print_dlistint(head);
    node = get_dnodeint_at_index(head, 5);
    printf("%d\n", node->n);
    free_dlistint(head);
    head = NULL;
    return (EXIT_SUCCESS);
}
void free_dlistint(dlistint_t *head){
    dlistint_t *curr = head;
    while(curr != NULL){
        dlistint_t *inter = curr;
        curr = curr->next;
        free(inter);
    }
    return;

}


dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index){
    dlistint_t *curr = head;
    for (int i = 0; i < index; i++){
        curr = curr->next;
    }
    return curr;

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

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n){
    dlistint_t *new_node = (dlistint_t*) malloc(sizeof(dlistint_t));
    if (new_node == NULL){
      printf("cant allocate memory for new node\n");
      return NULL;
    }
    new_node->n = n;
    new_node->next = NULL;
    new_node->prev = NULL;
    if ((*head) == NULL){
        (*head) = new_node;
        return new_node;
    }
    dlistint_t * curr = (*head);
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = new_node;
    new_node->prev = curr;
    curr = new_node;
    return curr;
}
