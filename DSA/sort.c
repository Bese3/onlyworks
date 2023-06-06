#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 20
int unsorted[SIZE] ={10, 2, 34, 9, 24, 18, 56, 20, 4, 15, 30, 27, 7, 39, 41, 23, 19, 65, 37, 50};

int bubble_sort();
size_t print();
int binary_search(int element , int left , int right);

  
int main(){

  bubble_sort();
  print();
  binary_search(37 , 0 , SIZE - 1);
    return 0;
}

  


int bubble_sort(){
   for(int i = 0;  i < SIZE; i++){
      for(int j = 0; j < SIZE - 1; j++){
        if(unsorted[j] > unsorted[j + 1]){
            int temp = unsorted[j];
            unsorted[j] = unsorted[j + 1];
            unsorted[j + 1] = temp;
        }
      }
   }
}


size_t print(){
    for(int i  = 0; i < SIZE; i++){
        printf("Array[%d] = %d\n" , i , unsorted[i]);
    }
    return SIZE;
}


int binary_search(int element , int left , int right){
  int middle = left + (right - left)/2;
static int iteration = 0;
  iteration++;

  if(left > right){
    printf("cant find ur number in the array\n");
    return -1;
  }
  if(unsorted[middle] == element){
    printf("Found the number %d in index %d\n" , element , middle);
    printf("number of middles needed are %d \n" , iteration);
    return 1;
  }
  else if(unsorted[middle] > element)
     return binary_search(element , left , middle - 1);
  else
     return binary_search(element , middle + 1 , right);
}

