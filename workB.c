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
   insert_end(&root , 4563);
   insert_end(&root , 4576);
   insert_middle(root->next , 3);
   insert_middle(root->next , 3);
   insert_beginning(&root , 201);
   insert_sorted(&root , 4567);
   insert_sorted(&root , 5000);
   delete_list(&root , 4563);




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
  void insert_sorted(node** root , int value)
  {
    if (*root == NULL ||(*root)->x > value)
    {
      insert_beginning(root , value);
      return;
    }
    node* curr = * root;
    while(curr->next != NULL)
    {
      if (curr->next->x > value)
      {
        insert_middle(curr , value);
        return;
      }
      curr = curr->next;
    }
    insert_middle(curr , value);
  }
  void delete_list(node** root , int value)
  {
    if (*root == NULL)
    {
      return;
    }
     
     for(node* curr = *root; curr->next != NULL; curr = curr->next)
     {
      
      
        do
          {
           node* removed = curr->next;
           curr->next = curr->next->next;
           free(removed);
          }while(curr->next->x == value);
      
     }

         

  }