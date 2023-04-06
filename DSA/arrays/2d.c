#include<stdio.h>
#include"list.h"
#define width 3
#define height 3
int a[height][width] = {1,2,3 , 4,5,6 , 7,8,9};

int main(int argc , char** argv[]){

  //insert(3 ,3  ,6);
  delete(3 , 2);
 display();




    return 0;
}

void insert(const int row  ,  const int column , int value){
   
    for(int i = (height - 1); i >= (row - 1); i--){
        if( i != (row - 1)){
        for(int j = (width - 1); j >= (0); j--){
            a[i][j + 1] = a[i][j];
            //printf("array[%d][%d] = array[%d][%d]\n" , i, j + 1 , i , j);
        }
        }
        else if ( i == (row - 1)){
             for(int j = (width - 1); j >= (column - 1); j--){
            a[i][j + 1] = a[i][j];
           //printf("array[%d][%d] = array[%d][%d]\n" , i, j + 1 , i , j);
        }

        }
    }

    a[row - 1][column - 1] = value;
}


void display(){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
         printf(" %d  " , a[i][j]);
        }
        printf("\n");
    }
    return;
}

void delete(const int row , const int  column){
  
     a[row - 1][column - 1] = 0;
     for(int i = (row - 1); i < height; i++){
        if (i == (row - 1)){
        for(int j = (column - 1); j < width; j++){
            a[i][j] = a[i][j + 1];
            printf("array[%d][%d] = array[%d][%d]\n" , i, j , i , j+1);
      }
        }
        else if (i != (row - 1)){
             for(int j = 0; j < width; j++){
            a[i][j] = a[i][j + 1];
            printf("array[%d][%d] = array[%d][%d]\n" , i, j , i , j+1);
      }

        }

     }

        a[height - 1][width - 1] = 0;
        

}