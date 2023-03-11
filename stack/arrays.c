#include<stdio.h>
#include<stdlib.h>
#include"stackA.h"
#define n 10
int stack[n];
int top = -1;

int main()
{ 
    int choice = 0;
 do{
    printf("\n\n");
 printf("#####################################\n");
 printf("#   Stack Implementation on Arrays  #\n");
 printf("#####################################\n");
 printf("1 . Push\n");
 printf("2 . Pop\n");
 printf("3 . Display Stack\n");
 printf("4 . Peek\n");
 scanf("%d" , &choice);
 printf("\n\n");

 
 int data = 0;
 switch(choice)
 {
    case 1:
    printf("Enter Data:\n");
    scanf("%d" , &data);
    push(data);
    break;
    case 2:
     pop();
     break;
     case 3:
     display();
     break;
     case 4:
     peek();
     break;
     case 5:
     default:
     printf("Invalid\n");
     break;

 }

 }while( choice == 4 || choice == 1 || choice == 2 || choice ==3);
 display();


 return 0;
}

void push(int value){
    if(top == (n - 1)){
     printf("Stack Over Flow Occurence\n");
     return;
    }
    top++;
    stack[top] = value; 
    printf("Pushed The Value : %d\n" , value);
}
void pop(){
    if(top == -1){
        printf("Stack Under Flow Occurence\n");
        return;
    }
    printf("Poped Item Is: %d\n" , stack[top]);
    stack[top] = 0;
    top--;
    

}
void peek(){
     if(top == -1){
        printf("Stack Under Flow Occurence\n");
        return;
    }
    printf("Top Value of Stack Is: %d\n" , stack[top]);
}
void display(){
    if(top == (n - 1)){
     printf("Stack Over Flow Occurence\n");
     
    }
    else if(top == -1){
        printf("Stack Under Flow Occurence\n");
        
    }
    printf("\n\n");
    for(int i = (top); i >= 0; i--){
     printf("%d\n" , stack[i]);
    }

}
