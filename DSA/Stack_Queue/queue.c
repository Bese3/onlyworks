#include"sq.h"

int count  = 0;

int main(){

  int choice  , data;
  do{
    printf("#########################################\n");
    printf("#### Queue Impelemtation using Stack ####\n");
    printf("#########################################\n");
    printf("1. Enqueue\n2. Dequeue\n");
    scanf("%d" , &choice);
    switch(choice){
        case 1:
          printf("Enter the data to insert: \n");
          scanf("%d" , &data);
          enqueue(data);
          break;
        case 2:
          dequeue();
          break;
        default:
           printf("Invalid choice\n");

    }

  
  }while(choice == 1 || choice == 2);
    return 0;
}

void enqueue(int data){
    push(&stack_1 , data);
    count++;

}
void dequeue(){
    if(stack_1 == NULL){
      printf("Queue is Empty\n");
      return;        
    }
    for(int i = 0; i < count; i++){
        push(&stack_2 , stack_1->n);
        pop(&stack_1);
    }
    printf("Queue front  = %d\n" , stack_2->n);
    pop(&stack_2);
    count--;
    for(int i = 0; i < count; i++){
        push(&stack_1 , stack_2->n);
        pop(&stack_2);
    }
   
}
stack_t* push(stack_t** head , const int value){
  stack_t* new_node = (stack_t*) malloc(sizeof(stack_t));
  if(new_node == NULL){
    printf("cant allocate memory\n");
    return (*head);
  }
  new_node->n = value;
  new_node->next = NULL;
  

  if(!(*head)){
    (*head) = new_node;
    return new_node;
  }

  new_node->next = *head;
  (*head) = new_node;
  return new_node;

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
    return *head;
    }
  stack_t* remove = (*head);
  (*head) = (*head)->next;
  free(remove);
  return(*head);

}


