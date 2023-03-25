#include<stdio.h>
#include<stdlib.h>




typedef struct dlist{
    int data;
    struct dlist* next;
    struct dlist* prev;
}dlist;


void reverse(dlist** head);


int main(){

dlist* root = (dlist*)malloc(sizeof(dlist));
root->data = 1;
root->prev = NULL;
root->next = malloc(sizeof(dlist));
root->next->data = 5;
root->next->next = NULL;
root->next->prev = root;
reverse(&root);
for (dlist* value = root; value != NULL; value = value->next){
    printf("%d\n" , value->data);
}
free(root->next);
free(root->prev);
free(root); 

    return 0;
}

void reverse(dlist** head){

    dlist*  curr = *head;
    while(curr != NULL){
        dlist* temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->next;
    }
    return;
}