#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define n 10
int array[n];
int front = -1;
int rear =  -1;
void enquefront(int data);
void enquerear(int data);
void dequefront();
void dequerear();
void display();

int main(){
    int choice,data;
    do{
    printf("################################################\n");
    printf("#### Queue Implementation in Circular Array ####\n");
    printf("################################################\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    scanf("%d" , &choice);
    switch(choice){
        case 1:
           printf("Enter the data to be inserted : ");
           scanf("%d" , &data);
           enquerear(data);
           break;
        case 2:
           dequerear();
           break;
        case 3:
           display();
           break;
        default:
           printf("Invalid Choice\n");
        

    }
    
    
    }while(choice == 1 || choice  == 2 || choice == 3);
    return 0;
}

 void enquefront(int data){
    if((front == 0 && rear == n  - 1) || front  == rear + 1 ){
        printf("Queue is full\n");
        return;
    }
    else if (front == -1 && rear ==  -1){
        front  = rear = 0;
        array[front] = data;
    }
    else if(front == 0){
       front = n - 1;
       array[front] = data;
    }
    else{
        front--;
        array[front] = data;
    }
    printf("Enqueued Number is %d\n" , array[front]);
 }

 void enquerear(int data){
    if((front == 0 && rear == n  - 1) || front  == rear + 1 ){
        printf("Queue is full\n");
        return;
    }
    else if (front == -1 && rear ==  -1){
        front  = rear = 0;
        array[rear] = data;
    }
    else if (rear == n - 1){
        rear = 0;
        array[rear] = data;
    
    }
    else {
        rear++;
        array[rear] = data;
    }
    printf("Enqueued Number is %d\n" , array[rear]);

 }

void dequefront(){
    if((front == -1 && rear == -1)){
        printf("Queue is Empty\n");
        return;
    }
    else if(front == rear){
        front = rear = -1;
    }
    else if(front  == rear - 1){
       printf("%d\n" , array[front]);
        front = 0;
    }
    else{
        printf("%d\n" , array[front]);
        front++;
    }

}
void dequerear(){
    if(front == -1 && rear == -1){
        printf("Queue is Empty\n");
        return;
    }
    else if (front == rear ){
        front  = rear = -1;
    }
    else if(rear == 0){
        printf("%d\n" , array[rear]);
        rear = n - 1;
    }
    else{
        printf("%d\n" , array[rear]);
        rear--;
    }
}
void display(){
    int i = front;
    while( i != rear){
        printf("%d\n" , array[i]);
        i =(i + 1) % n;
    }
    printf("%d\n" , array[rear]);
}

