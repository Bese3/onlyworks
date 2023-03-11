#include<stdio.h>
#include<stdlib.h>

  typedef struct node{
    int data;
    struct node *next;
  }node;
  node* top = NULL;
int main(){

 node *root;
 root->data = 2;
 root->next = NULL;   //malloc(sizeof(node));





 for(node* curr = root; curr != NULL; curr = curr->next){
    printf("%d\n" , curr->data);
 }



 return 0;
}


void push(){
  node* new_node = malloc(sizeof(node));
 
}


