#define _CRTDBG_MAP_ALLOC
#include<stdio.h>
#include<stdlib.h>
#include<crtdbg.h>
#include"list.h"

/* initializing linked list with a struct and
 * adding values using defined functions.
 * deallocating at last.
 */






  int main()
  {
   node* root = malloc(sizeof(node));
   root->x = 5;
   root->next = NULL;

   insert_end(&root , 43);
   insert_end(&root , 4563);
   insert_end(&root , 4576);
   insert_end(&root , 4543);
   insert_middle(root->next , 3);
   insert_beginning(&root , 201);



   node* list = root;
   int i = 0;
  for (list; list != NULL; list= list->next)
  {
    printf("%d\n" , list->x);
    i++;
  }
  deallocate(&root);
  _CrtDumpMemoryLeaks();
 printf("linked lists with %d values is added\n" , i);


 return (0);
  }




   void  insert_end(node** root , int value)
  {
    node* new_node = malloc(sizeof(node));
    if (new_node == NULL)
    {
        exit(1);
    }
    new_node->x = value;
    new_node->next = NULL;


    node* curr = *root;
    while(curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = new_node;
  }
  void deallocate(node** root)
  {
   node* curr = *root;
   while(curr != NULL)
   {
    node* deal = curr;
    curr = curr->next;
    free(deal);
   }
 *root = NULL;

  }
  void insert_beginning(node** root , int value)
  {

    node* new_node  = malloc(sizeof(node));
    if (new_node == NULL)
    {
     exit(3);

    }
    new_node->x = value;
    new_node->next = *root;
    *root = new_node;
  }
  void insert_middle(node* add , int value)
  {
    node* new_node = malloc(sizeof(node));
    new_node->x = value;
    new_node->next = add->next;
    add->next = new_node;
    add = new_node;
  }
