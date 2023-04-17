#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define size 10

int array[size] = {1,2,3,4,5,6,7,8,9,10};

void insertion(const int position , int value);
void deletion(const int position);

int main(){

 insertion(4 , 15);


  for(int i = 0; i < size; i++)
     printf(" %d " , array[i]);
    return 0;
}
void insertion(const int position , int value){        // insertion in array at given index(position - 1)
    for(int i = (size - 1); i >= (position - 1); i--){
     array[i + 1] = array[i];
    // printf("array[%d] = array[%d]\n" , i + 1 , i);
    }
    array[position - 1] = value;

}
void deletion(const int position){     // deletion in array at specified position
    if((position - 1) < 0 || (position - 1) > (size  - 1)){
        printf("Invalid\n");
        return;
    }
    array[position - 1] = 0;
    int i;
    for(i = (position - 1); i < size; i++){
        array[i] = array[i + 1];
    }
    array[i] = 0;

}
