#include"hanoi.h"
dlistint_t *source = NULL;
dlistint_t *inter = NULL;
dlistint_t *destination = NULL;

int main(){
   add_dnodeint(&source , 4);
   add_dnodeint(&source , 3);
   add_dnodeint(&source , 2);
   add_dnodeint(&source , 1);

   hanoi();




    free_t(source);
    free_t(inter);
    free_t(destination);
    return 0;
}


/// @brief  this function add a node at the beginning of the linked list 
/// @param head linked list which we add the node
/// @param n   the value we add
/// @return  the new list
 dlistint_t *add_dnodeint(dlistint_t **head, const int n){
     dlistint_t *new_node  = (dlistint_t*) malloc(sizeof(dlistint_t));
     if (new_node == NULL){
        printf("cant allocate memory\n");
        return NULL;
     }

    new_node->n = n;
    new_node->next = NULL;
    new_node->prev = NULL;
    if ((*head) == NULL){
        (*head) = new_node;
        return new_node;
    }
    
    new_node->next = (*head);
    new_node->prev = (*head)->prev;
    (*head)->prev = new_node;
    (*head) = new_node;
    return new_node;
}


dlistint_t* push(dlistint_t** head , const int value){
  dlistint_t* new_node = (dlistint_t*) malloc(sizeof(dlistint_t));
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



dlistint_t *pop(dlistint_t** head){

  if((*head) == NULL){
    printf("Stack Underflow\n");
    return 0;
    }
 // printf("Poped out %d \n" , (*head)->n);
  dlistint_t* remove = (*head);
  (*head) = (*head)->next;
//  (*head)->prev = NULL;
  free(remove);
  return(*head);

}
  
/// @brief works  with the first four element
/// @return 1 if success -1 if no value
int hanoi(){
    if(source == NULL){
        printf("No value to work with\n");
        return -1;
    }
    int steps = 0;

    while(source != NULL){
        push(&inter , source->n);     //from A -> B    2,3,4 - 1 - 
        pop(&source);
        printf("Step %d\n" , steps++);
        printf("Source Stack:\n");
        print(source);
        printf("Intermidiate Stack:\n");
        print(inter);
        printf("Destination Stack :\n"); 
        print(destination);
        sleep(3);
    
        push(&destination , source->n);  //from A -> C    3.4 - 1 - 2
        pop(&source);
        printf("Step %d\n" , steps++);
        printf("Source Stack:\n");
        print(source);
        printf("Intermidiate Stack:\n");
        print(inter);
        printf("Destination Stack :\n"); 
        print(destination);
        sleep(3);
    
        push(&destination , inter->n);   //from B -> C    3,4 - - 1,2
        pop(&inter);
        printf("Step %d\n" , steps++);
        printf("Source Stack:\n");
        print(source);
        printf("Intermidiate Stack:\n");
        print(inter);
        printf("Destination Stack :\n"); 
        print(destination);
        sleep(3);
    
        push(&inter , source->n);     //from A -> B     4 - 3 - 1,2
        pop(&source);
        printf("Step %d\n" , steps++);
        printf("Source Stack:\n");
        print(source);
        printf("Intermidiate Stack:\n");
        print(inter);
        printf("Destination Stack :\n"); 
        print(destination);
        sleep(3);

        push(&source , destination->n);     //from C -> A     1,4 - 3 - 2
        pop(&destination);
        printf("Step %d\n" , steps++);
        printf("Source Stack:\n");
        print(source);
        printf("Intermidiate Stack:\n");
        print(inter);
        printf("Destination Stack :\n"); 
        print(destination);
    
        sleep(3);

    
        push(&inter , destination->n);     //from C -> B    1,4 - 2,3 - 
        pop(&destination);
        printf("Step %d\n" , steps++);
        printf("Source Stack:\n");
        print(source);
        printf("Intermidiate Stack:\n");
        print(inter);
        printf("Destination Stack :\n"); 
        print(destination);
        sleep(3);

        push(&inter , source->n);     //from A -> B     4 - 1,2,3 - 
        pop(&source);
        printf("Step %d\n" , steps++);
        printf("Source Stack:\n");
        print(source);
        printf("Intermidiate Stack:\n");
        print(inter);
        printf("Destination Stack :\n"); 
        print(destination); 
        sleep(3);

        push(&destination , source->n);     //from A -> C      - 1,2,3 - 4
        pop(&source);
        printf("Step %d\n" , steps++);
        printf("Source Stack:\n");
        print(source);
        printf("Intermidiate Stack:\n");
        print(inter);
        printf("Destination Stack :\n"); 
        print(destination);
        sleep(3);

        push(&destination , inter->n);     //from B -> C      - 2,3 - 1,4
        pop(&inter);
        printf("Step %d\n" , steps++);
        printf("Source Stack:\n");
        print(source);
        printf("Intermidiate Stack:\n");
        print(inter);
        printf("Destination Stack :\n"); 
        print(destination);
        sleep(3);

        push(&source , inter->n);     //from B -> A     2 - 3 - 1,4
        pop(&inter);
        printf("Step %d\n" , steps++);
        printf("Source Stack:\n");
        print(source);
        printf("Intermidiate Stack:\n");
        print(inter);
        printf("Destination Stack :\n"); 
        print(destination);
        sleep(3);

        push(&source , destination->n);   //from C -> A    1,2 - 3 - 4
        pop(&destination);
        printf("Step %d\n" , steps++);
        printf("Source Stack:\n");
        print(source);
        printf("Intermidiate Stack:\n");
        print(inter);
        printf("Destination Stack :\n"); 
        print(destination);
        sleep(3);

        push(&destination , inter->n);   //from B -> C    1,2 -  - 3,4
        pop(&inter);
        printf("Step %d\n" , steps++);
        printf("Source Stack:\n");
        print(source);
        printf("Intermidiate Stack:\n");
        print(inter);
        printf("Destination Stack :\n"); 
        print(destination);
        sleep(3);
        
        push(&inter , source->n);   //from A -> B    2 - 1 - 3,4
        pop(&source);
        printf("Step %d\n" , steps++);
        printf("Source Stack:\n");
        print(source);
        printf("Intermidiate Stack:\n");
        print(inter);
        printf("Destination Stack :\n"); 
        print(destination);
        sleep(3);

        push(&destination , source->n);   //from A -> C     - 1 - 2,3,4
        pop(&source);
        printf("Step %d\n" , steps++);
        printf("Source Stack:\n");
        print(source);
        printf("Intermidiate Stack:\n");
        print(inter);
        printf("Destination Stack :\n"); 
        print(destination);
        sleep(3);
        
        push(&destination , inter->n);   //from B -> C     - - 1,2,3,4
        pop(&inter);
        printf("Step %d\n" , steps++);
        sleep(3);

           
    

   
    }

      printf("Source Stack:\n");
      print(source);
      printf("Intermidiate Stack:\n");
      print(inter);
      printf("Destination Stack :\n"); 
      print(destination);
    
    
}

size_t print(dlistint_t* head){
    if(head == NULL){
        printf("Empty Stack!\n");
        return 0;
    }
    int size = 0;
    dlistint_t* curr = head;
    for(curr; curr != NULL; curr = curr->next){
        printf("%d\n", curr->n);
        size++;
    }
    printf("\n");
    size = size + 1;
    return size;
}
void free_t(dlistint_t* head){
    dlistint_t* curr = head;
    while(curr != NULL){
        dlistint_t* temp = curr;
        curr = curr->next;
        free(temp);
    }
}