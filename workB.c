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
   root->x = 2;
   root->next = NULL;



   insert_end(&root , 3);
   insert_end(&root , 5);
   insert_middle(root->next , 10);
   reverse(&root);

   //root->next->next = root;
    int x = has_loop(root);

   if(x == 1)
   {
    printf("linked list has a loop\n");
    return 1;
   }








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
      new_node->next = NULL;
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
    //add = new_node;
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

       /*if((*root)->x == value)
          {
           node* removed = *root;
           (*root) = (*root)->next;
           free(removed);
           return;
          }*/


   for(node* curr = *root; curr->next != NULL; curr = curr->next)
     {

         while(curr->next->x == value)
          {
           node* removed = curr->next;
           curr->next = curr->next->next;
           free(removed);
           return;
          }

     }
  }
  int has_loop(node* root)
  {
    node* slow = root;
    node* fast = root;
    while(slow != NULL && fast != NULL && fast->next != NULL)
    {
      slow = slow->next;
      fast = fast->next->next;
      if(fast == slow)
      {
        return 1;
      }
    }
  return 0;
  }
  void reverse(node** root)
   {
    node* prev = NULL;
    node* curr = *root;
    
       
     while(curr != NULL)
     {
       node* next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next; 
      
     }  
     *root = prev;   


   }
