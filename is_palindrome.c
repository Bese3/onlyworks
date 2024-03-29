#include<stdio.h>
#include<stdlib.h>
#include"list.h"




 int is_palindrome(listint_t **head)
 {
   if (*head == NULL)
   {
    return 1;
   }
   listint_t* slow = *head;
   listint_t* fast = *head;
   while(fast->next != NULL && fast->next->next != NULL)
   {
    slow = slow->next;
    fast = fast->next->next;
   }
   listint_t* first_half = *head;
  // reversing the second half of linked list
   listint_t* prev = NULL;
    listint_t* curr  = slow->next;
     while(curr != NULL)
     {
        listint_t* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
     }
     slow->next = prev;
     listint_t* second_half = slow->next;

     while(first_half != NULL && second_half != NULL)
     {
        if(first_half->n != second_half->n){
            printf("%d is not equal to %d\n" , first_half->n , second_half->n);
            return 0;
            }

            first_half = first_half->next;
            second_half = second_half->next;
     }
     return 1;
 }
 /**
 * print_listint - prints all elements of a listint_t list
 * @h: pointer to head of list
 * Return: number of nodes
 */
size_t print_listint(const listint_t *h)
{
    const listint_t *current;
    unsigned int n; /* number of nodes */

    current = h;
    n = 0;
    while (current != NULL)
    {
        printf("%i\n", current->n);
        current = current->next;
        n++;
    }

    return (n);
}

/**
 * add_nodeint_end - adds a new node at the end of a listint_t list
 * @head: pointer to pointer of first node of listint_t list
 * @n: integer to be included in new node
 * Return: address of the new element or NULL if it fails
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
    listint_t *new;
    listint_t *current;

    current = *head;

    new = (listint_t*) malloc(sizeof(listint_t));
    if (new == NULL)
        return (NULL);

    new->n = n;
    new->next = NULL;

    if (*head == NULL)
        *head = new;
    else
    {
        while (current->next != NULL)
            current = current->next;
        current->next = new;
    }

    return (new);
}

/**
 * free_listint - frees a listint_t list
 * @head: pointer to list to be freed
 * Return: void
 */
void free_listint(listint_t *head)
{
    listint_t *current;

    while (head != NULL)
    {
        current = head;
        head = head->next;
        free(current);
    }
}


int listint_len(const listint_t *h)
{
	size_t len = 0;

	while (h->next != NULL)
	{
		len++;
		h = h->next;
	}

	return (len);
}


/**
 * main - check the code for
 *
 * Return: Always 0.
 */
int main(void)
{
    listint_t *head;

    head = NULL;
    add_nodeint_end(&head, 0);
    add_nodeint_end(&head, 1);
    add_nodeint_end(&head, 17);
    add_nodeint_end(&head, 972);
    add_nodeint_end(&head, 50);
    add_nodeint_end(&head, 98);
    add_nodeint_end(&head, 98);
    add_nodeint_end(&head, 50);
    add_nodeint_end(&head, 972);
    add_nodeint_end(&head, 17);
    add_nodeint_end(&head, 1);
    add_nodeint_end(&head, 0);

    print_listint(head);

    if (is_palindrome(&head) == 1)
        printf("Linked list is a palindrome\n");
    else
        printf("Linked list is not a palindrome\n");

    free_listint(head);

    return (0);
}

