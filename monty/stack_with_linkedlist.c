#include<stdio.h>
#include<stdlib.h>
#include"monty.h"


  
int main(){
   

   stack_t* root = NULL;
   push(&root , 5);
   push(&root , 4);
   add(&root);  
   push(&root , 6);
   swap(&root);
   
   display(root);
   
  

   free_t(root);


 


 return 0;
}

stack_t* push(stack_t** head , const int value){
  stack_t* new_node = (stack_t*) malloc(sizeof(stack_t));
  if(new_node == NULL){
    printf("cant allocate memory\n");
    return (*head);
  }
  new_node->n = value;
  new_node->next = NULL;
  new_node->prev = NULL;

  if(!(*head)){
    (*head) = new_node;
    return new_node;
  } 

  new_node->next = *head;
  (*head)->prev = new_node;
  (*head) = new_node;
  return new_node;

}
size_t display(stack_t* head){
  stack_t* curr = head;
  int n = 0;
   while(curr != NULL){
    printf("%d\n" , curr->n);
    curr = curr->next;
    n++;
   }
   return n;
}
void free_t(stack_t* head){
  stack_t* curr = head;
  while(curr != NULL){
    stack_t* remove = curr;
    curr = curr->next;
    free(remove); 
  }
}
stack_t* pop(stack_t** head){

  if((*head) == NULL){
    printf("Stack Underflow\n");
    // return 0;
    }
 // printf("Poped out %d \n" , (*head)->n);
  stack_t* remove = (*head);  
  (*head) = (*head)->next;
  //(*head)->prev = NULL;
  free(remove);
  return(*head);

}
stack_t* add(stack_t** head){
  if((*head)->next == NULL){
    printf("cant add single value\n");
    return (*head);
  }
   int sum = 0;
   sum = ((*head)->n + (*head)->next->n);
   pop(head);
   pop(head);
   push(head , sum);
  // printf("sum -> ");
   return (*head);
}
stack_t* swap(stack_t** head){
  if((*head) == NULL || (*head)->next == NULL){
    printf("error swaping more than one item required\n");
    return (*head);
  }
  int first = (*head)->n;
  int second = (*head)->next->n;
  int swap = first;
  first = second;
  second  = swap;
  pop(head);
  pop(head);
  push(head , second);
  push(head , first);
  return (*head);
}



