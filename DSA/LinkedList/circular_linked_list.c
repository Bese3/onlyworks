#include"header.h"









int main(int *argc , char **argv[]){
 
   
   dlistint_t* root = NULL;
   add_dnodeint_end(&root , 0);
   add_dnodeint_end(&root , 1);
   add_dnodeint_end(&root , 2);
   add_dnodeint_end(&root , 3);
   add_dnodeint_end(&root , 4);
   add_dnodeint_end(&root , 5);
   add_dnodeint_end(&root , 6);
   add_dnodeint_end(&root , 7);
   circular_linked(&root , 7);
   add_circular(&root ,4 , 44);

   int loop  = has_loops(root);
   if(loop == 1){
            printf("The list has a loop cant be displayed\n");
            return 1;
          }
          print_dlistint(root);



   

    free(root);
    return 0;
}

/// @brief this fun add a node at the end of linked list
/// @param head  linked list head
/// @param n  value at the node to be linked
/// @return  the new list 
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

/// @brief  circulates a list
/// @param head list
/// @param index index which the list circulates
/// @return circulated list
dlistint_t* circular_linked(dlistint_t** head , const int index){
    dlistint_t* new_list = (*head);
    int i = 0;
    while(i < index){
        if(new_list->next !=NULL)
          new_list = new_list->next;
        printf("%d\n" , i);
        i++;
    }
    int size  = size_of(*head);
    if(new_list == NULL && i != (size - 1)){
        printf("Enter a Number in the size of the list\n");
        return (*head);
    }
    new_list->next = (*head);
    (*head)->prev = new_list;
    return new_list;
}


dlistint_t *add_circular(dlistint_t** head , const int index  ,int value){
    dlistint_t* curr = (*head);
    dlistint_t* node = (dlistint_t*)malloc(sizeof(dlistint_t));
    node->n = value;
    int i = 0;
    while(i < index){
        if(curr->next != NULL)
        curr = curr->next;
        i++;
    }
    int size  = size_of(*head);
    if(curr == NULL && i != (size - 1)){
        printf("Enter a Number in the size of the list\n");
        return (*head);
    }
    dlistint_t* temp = curr->prev;
    curr->prev = node;
    node->next = curr;
    node->prev = temp;
    temp->next = node;
    

   return curr;     

}

size_t size_of(dlistint_t* head){
    dlistint_t* curr = head;
    size_t size = 0;
    while(curr->next != NULL){
        size++;
        curr = curr->next;
    }
    return size;

}


/// @brief this function prints out the linked list
/// @param h  the linked list to print out
/// @return  size of the list
size_t print_dlistint(const dlistint_t *h){
   printf("#####Linked List#####\n"); 
   const dlistint_t *curr = h;
   int i = 0;
    for(curr; curr != NULL; curr = curr->next){
        printf("L[%d] = %d\n" ,i,curr->n);
        i++;
    } 
    printf("#####End Linked List#####\n");
    return i;
}

/// @brief frees the memory after use of a function in the list
/// @param head list to be freed
void free_dlistint(dlistint_t *head){
    dlistint_t *curr = head;
    while(curr != NULL){
        dlistint_t *delete = curr;
        curr = curr->next;
        free(delete);
    }
    return;

}

/// @brief checks whether the list is cicrcular or not 
/// @param head  list to be checked
/// @return 0 if not and 1 if  it is
int has_loops(dlistint_t* head){
    dlistint_t* fast = head;
    dlistint_t* slow = head;
    while(fast != NULL && fast->next != NULL && fast->next->next != NULL){
       slow = slow->next;
       fast = fast->next->next;
       if(slow == fast)
          return 1;
      
    }
    return 0;   

}
