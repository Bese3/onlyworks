#include"header.h"


int main(int argc , char** argv[]){
   dlistint_t* head = NULL;
   dlistint_t* tail = NULL;
   add_dnodeint_end(&tail , 1);
   add_dnodeint_end(&tail , 2);
   add_dnodeint_end(&tail , 3);
   add_dnodeint_end(&head , 5);
   add_dnodeint_end(&head , 6);
   add_dnodeint_end(&head , 7);
   concatenate(tail , head);
   circular_linked(&head , 10);
   int x = has_loops(tail);
   if (x == 1){
    printf("list has loop\n");
    return 1;
   }
    
   print_dlistint(tail);
   free(head);
   
   
    return 0;
}

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index){
     dlistint_t *curr = *head;
    int i = 0;
    if (index == 0){
        dlistint_t *remove = *head;
        (*head) = (*head)->next;
        (*head)->prev = NULL;
        free(remove);
        return index;
    }
    while( i < (index - 1)){
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
    dlistint_t *to_delete = curr->next;
    curr->next = curr->next->next;
    curr->next->prev = curr;
    free(to_delete);
    return index;
}

size_t print_dlistint(const dlistint_t *h){
   const dlistint_t *curr = h;
   int i = 0;
    for(curr; curr != NULL; curr = curr->next){
        printf("%d\n" ,curr->n);
        i++;
    } 
    return i;
}

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
    (*head)->prev = new_node;
    (*head) = new_node;
    return new_node;
}

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

void free_dlistint(dlistint_t *head){
    dlistint_t *curr = head;
    while(curr != NULL){
        dlistint_t *delete = curr;
        curr = curr->next;
        free(delete);
    }
    return;

}
dlistint_t* concatenate(dlistint_t* first_half , dlistint_t* second_half){
    dlistint_t* new_list;
    dlistint_t* curr = first_half;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = second_half;
    second_half->prev = curr;
    new_list = first_half;
    return new_list;
}
dlistint_t* circular_linked(dlistint_t** head , const int index){
    dlistint_t* new_list = (*head);
    int i = 0;
    while(i < index && new_list->next != NULL){
        new_list = new_list->next;
        i++;
    }
    if(i != (index - 1)){
        printf("Enter a Number in the size of the list\n");
        return new_list;
    }
    new_list->next = (*head);
    (*head)->prev = new_list;
    return new_list;
}
int has_loops(dlistint_t* head){
    dlistint_t* fast = head;
    dlistint_t* slow = head;
    while(fast != NULL && fast->next != NULL && fast->next->next != NULL){
       if(slow == fast)
          return 1;
       slow = slow->next;
       fast = fast->next->next;
    }
    return 0;   

}

