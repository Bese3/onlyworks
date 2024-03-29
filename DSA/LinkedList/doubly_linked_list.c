#include"header.h"

/*
 * Implemetation of LinkedList
 * SinglyLinkedList
 * DoublyLinkedList
 * CircularLinkedList
*/


int main(int argc , char** argv[]){
   dlistint_t* head = NULL;
   dlistint_t* tail = NULL;
   add_dnodeint(&tail , 0);
   add_dnodeint_end(&tail , 1);
   add_dnodeint_end(&tail , 2);
   add_dnodeint_end(&tail , 3);
   add_dnodeint_end(&tail , 4);
   add_dnodeint_end(&tail , 5);
   printf("Sample list\n");
   print_dlistint(tail);
   int data , position , choice , loop;
   do{
     printf("\n");
     printf("  ####################################\n");
     printf("  #    LinkedList Implementation     #\n");
     printf("  ####################################\n");
     printf(" 1. Insert at the beginning\n 2. Insert at the middle \n 3. Insert at the end\n 4. Insert sorted\n 5. Print the LS\n");
     printf(" 6. Delete a LS\n 7. Concatenate lists\n 8. Circulate a list\n 9. Reverse a LS\n 10. Reset\n");
     scanf("%d" , &choice);
     switch(choice){
        case 1:
          printf("Enter the Number to add in the Linked List\n");
          scanf("%d" , &data);
          add_dnodeint(&head , data);
          break;
        case 2:
          printf("Enter the Position and the value\n");
          printf("Position: ");
          scanf("%d" , &position);
          printf("Value: ");
          scanf("%d" , &data);
          add_dnodeint_mid(&head , position , data);
          break;
        case 3:
          printf("Enter the Number to add in the Linked List\n");
          scanf("%d" , &data);
          add_dnodeint_end(&head , data);
          break;
        case 4:
          printf("Enter the Number to add in the Linked List\n");
          scanf("%d" , &data);
          add_dnodeint_sorted(&head , data);
          break; 
        case 5:
          print_dlistint(head);
          break; 
        case 6:
          printf("Enter the Position to delete\n");
          printf("Position: ");
          scanf("%d" , &position);
          delete_dnodeint_at_index(&head , position);
          break;
        case 7:
          concatenate(head , tail);
          break;
        case 8:
          printf("Enter the Position to circulate\n");
          printf("Position: ");
          scanf("%d" , &position);
          circular_linked(&head , position);
          break; 
        case 9:
          reverse(&head);
          break;
        case 10:
          free_dlistint(head);
          break;  
        default:
           printf("Invalid Choice\n");   
           break;     
        
      } 

    
   }while(choice < 11 && choice > 0);
   
   free_dlistint(head);
   free_dlistint(tail);
   
   
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
    int loop  = has_loops(*head);
    if(loop == 1){
       add_dnodeint_mid(head , 0 , new_node->n);
       return *head; 
    }
    new_node->next = (*head);
    new_node->prev = (*head)->prev;
    (*head)->prev = new_node;
    (*head) = new_node;
    return new_node;
}

/// @brief add node in the middle of the linked list
/// @param head  the linked list we use to add
/// @param index  position to add the node 
/// @param value  value to be added at index position
/// @return  new list 
dlistint_t *add_dnodeint_mid(dlistint_t **head , const int index ,int value){
    if((*head) == NULL){
        add_dnodeint(head , value);
        return (*head);
    }
    dlistint_t* new_node = (dlistint_t*)malloc(sizeof(dlistint_t));
    
    if (!new_node){
        printf("cant allocate memory\n");
        return NULL;
        }
    int size = print_dlistint(*head);
    if (index > size){
        printf("Please enter index in the size of the list\n");
        return NULL;
     }    
    dlistint_t* curr = *head;
     new_node->n = value;
     new_node->next = NULL;
     new_node->prev = NULL;
     int i = 0;
     while(i < (index)){
        curr = curr->next;
        i++;
     }
     dlistint_t* temp = curr->prev;
     curr->prev = new_node;
     temp->next = new_node;
     new_node->next = curr;
     new_node->prev = temp;
     return (*head);     

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

/// @brief concatenate doubly linked list
/// @param first_half  first half of the linked list
/// @param second_half  second half of the linked list
/// @return the join list
dlistint_t* concatenate(dlistint_t* first_half , dlistint_t* second_half){
    dlistint_t* new_list;
    dlistint_t* curr = first_half;
    int loop1 = has_loops(first_half);
    int loop2 = has_loops(second_half);
    if(loop1 == 1 || loop2 == 1){
        printf("Cant Concatenate Circular Loops!!!\n");
        return NULL;
    }
    if(first_half == NULL){
       first_half = second_half;
    //    first_half->next = second_half->next;
       return first_half;

    }
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = second_half;
    second_half->prev = curr;
    new_list = first_half;
    return new_list;
}

/// @brief  circulates a list
/// @param head list
/// @param index index which the list circulates
/// @return circulated list
dlistint_t* circular_linked(dlistint_t** head , const int index){
    dlistint_t* new_list = (*head);
    int i = 0;
    int loop  =  has_loops(*head);
    if(loop == 1){
        printf("Cant Circulate again\n");
        return NULL;
    }
    while(i < index - 1){
        if(new_list->next !=NULL)
          new_list = new_list->next;
         i++;
    }
    int size  = size_of(*head);
    if(new_list == NULL && i != (size - 1)){
        printf("Enter a Number in the size of the List\n");
        return (*head);
    }
    new_list->next = (*head);
    (*head)->prev = new_list;
    return new_list;
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
       if(slow == fast){
          printf("Linked List Linked from %d -> %d\n" , slow->prev->n , slow->n);          
          return 1;
        }
    }
    return 0;   

}

/// @brief this function deletes a node at a specific index  
/// @param head  the linked list we use to iterate
/// @param index  index where the node will be deleted
/// @return  the index which has been deleted
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index){
     dlistint_t *curr = *head;
     int size = print_dlistint(curr);
     if (index > size || index < 1 || (*head) == NULL){
        printf("Please Enter Index in the size of the List or add the List size\n");
        return size;
     }
    int i = 0;
    if (index == 1){
        dlistint_t *remove = *head;
        (*head) = (*head)->next;
        (*head)->prev = remove->prev;
        remove->prev->next = (*head);
        free(remove);
        return index;
    }
    while( i < (index - 1)){
        if(curr->next != NULL)
           curr = curr->next;
        i++;
    }
    if(curr->next == NULL){
       dlistint_t* to_remove = curr;
       curr = curr->prev;
       curr->next = NULL;
       free(to_remove);
       return index;
    }
    else if(curr->next->next == NULL){
        dlistint_t* to_remove = curr;
        curr = curr->prev;
        curr->next = curr->next->next;
        free(to_remove);
        return index;
    }
    dlistint_t *to_delete = curr;
    curr = curr->next;
    curr->prev = to_delete->prev;
    to_delete->prev->next = curr;
    free(to_delete);
    return index;
}

/// @brief this function prints out the linked list
/// @param h  the linked list to print out
/// @return  size of the list
size_t print_dlistint(dlistint_t *h){
   int loop  = has_loops(h);
   dlistint_t *curr = h;
   dlistint_t *slow = h;
   dlistint_t *fast = h;
   int i = 0;
  
  if(loop == 1){
   printf("##### Circular Linked List #####\n"); 
   while(fast != NULL && fast->next != NULL && fast->next->next != NULL){
   slow = slow->next;
   fast = fast->next->next;
   printf("L[%d] = %d\n" ,i + 1,slow->prev->n);
      if(slow == fast){
        printf("##### End Linked List #####\n");
        printf("Loop Exists in Your Linked List\n");
        return i;

     }
     i++;
   }
 }
 
  
  
   
   
   
   printf("##### Linked List #####\n"); 
  
   
    for(curr; curr != NULL; curr = curr->next){
        printf("L[%d] = %d\n" ,i + 1,curr->n);
        i++;
    } 
    printf("##### End Linked List #####\n");
    return i;
}

/// @brief frees the memory after use of a function in the list
/// @param head list to be freed
void free_dlistint(dlistint_t *head){
    dlistint_t *curr = head;
   
    int loop = has_loops(head);
    if(loop == 1){
        while(curr->next != head){
          curr = curr->next;
        }
        dlistint_t *temp = head;
        while(temp != curr){
            dlistint_t *delete = temp;
            temp = temp->next;
            free(delete);
            delete = NULL;
        }
        free(temp);
        temp = NULL;
        return;        
      
        }


    while(curr != NULL){
        dlistint_t *delete = curr;
        curr = curr->next;
       
        free(delete);
        delete = NULL;
    }
    return;

}

/// @brief a fun that add node in the sorted order
/// @param head list to deal with
/// @param value value in the node
/// @return  new list
dlistint_t * add_dnodeint_sorted(dlistint_t** head , int value){
    if(!(*head) || (*head)->n > value){
        add_dnodeint(head , value);
        return (*head);
    }
    int i = 0;
    dlistint_t *curr = *head;
    while(curr->next !=NULL){
        if((curr->next->n > value) && curr->n < value){
            add_dnodeint_mid(head , (i + 1) , value);
            return (*head);
            }
            i++;
            curr = curr->next;
    }
    add_dnodeint_end(head , value);
    return (*head);

}

/// @brief reverses the linked list
/// @param head  the list to be reversed
/// @return newly reversed list
dlistint_t *reverse(dlistint_t** head){
    dlistint_t* prev = NULL;
    dlistint_t* curr = *head;
    dlistint_t* next = NULL;
    int loop  = has_loops(*head);
    if(loop == 1){
        printf("Cant Reverse Circular Linked List!!!\n");
        return NULL;
    }
       
     while(curr != NULL)
     {
      next = curr->next;
      curr->next = prev;
      curr->prev = next;    
      prev = curr;
      curr = next; 
      
     }  
     *head = prev;   
     return (*head);   
}
size_t size_of(dlistint_t* head){
    dlistint_t* curr = head;
    size_t size = 0;
   for(curr; curr->next != NULL; curr = curr->next){
        size++;
    } 
    return size;

}