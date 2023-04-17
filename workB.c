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
   node* root =(node*) malloc(sizeof(node));
   root = NULL;

   insert_end(&root , 3);
   insert_end(&root , 4);
   insert_middle(root , 5);
   insert_beginning(&root , 1);
  //  insert_end(&root , 6);
  //  insert_beginning(&root , 1);
  //  insert_sorted(&root , 2);
  //  insert_sorted(&root , 0);
  //  insert_sorted(&root ,5);
  //  insert_sorted(&root , 7);
  //  insert_sorted(&root , 0);
  // //  delete_list(&root);
  //  delete_list_end(&root);
  //  delete_list_end(&root);
  //  delete_list_middle(&root , 5);






  //  root->next->next = root; //making a loop
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




  void insert_end(node** root,  int value)
{
    node* new;
    node* current;

    current = *root;

    new = malloc(sizeof(listint_t));
    if (new == NULL)
        return;

    new->x = value;
    new->next = NULL;

    if (*root == NULL)
        *root = new;
    else
    {
        while (current->next != NULL)
            current = current->next;
        current->next = new;
    }

  
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

    node* new_node  = (node*) malloc(sizeof(node));
    if (new_node == NULL)
    {
     printf("cannot allocate memory for new node\n");
     return;
    }
    new_node->x = value;
    new_node->next = *root;
    *root = new_node;
  }
  void insert_middle(node* add , int value)
  {
    node* new_node = (node*) malloc(sizeof(node));
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
      if (curr->next->x > value && curr->x <= value)
      {
        insert_middle(curr , value);
        return;
      }
      curr = curr->next;
    }
    insert_middle(curr , value);
  }
  void delete_list(node** root)
  {
     // at the beginning
     node* curr = *root;
    
      *root = (*root)->next;
      free(curr);
      return;
     
  }
  void delete_list_end(node** root)
  {
    node* curr  = *root;
    while(curr->next->next != NULL)
     {
      curr = curr->next;
     }
     node* temp = curr->next;
     curr->next = NULL;
     free(temp);

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
  void delete_list_middle(node** root , const int position)
  {
    int i = 0;
    node* curr = *root; 
    while (i < (position - 1))
    {
      curr = curr->next;
      i++;
    }
    node* new_node = curr->next->next;
    node* temp = curr->next;
    curr->next = new_node;
    free(temp);



  }