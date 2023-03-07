#define _CRTDBG_MAP_ALLOC
#include<stdio.h>
#include<stdlib.h>
#include<crtdbg.h>

/* initializing linked list with astruct and
 * adding value using defined functions.
 * deallocated at last.
 */

 typedef struct node{
    int x;
    struct node* next;
 }node;

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


  int main()
  {
   node* root = malloc(sizeof(node));
   root->x = 5;
   root->next = NULL;

   insert_end(&root , 43);
   insert_end(&root , 4563);
   insert_end(&root , 4576);
   insert_end(&root , 4543);


   node* list = root;
   int i = 0;
  for (list; list != NULL; list= list->next)
  {
    printf("%d\n" , list->x);
    i++;
  }
  deallocate(&root);
  _CrtDumpMemoryLeaks();
 printf("linked list with %d values is added\n" , i);


 return (0);
  }
