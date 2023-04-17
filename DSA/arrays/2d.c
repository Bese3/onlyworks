#include<stdio.h>
#include"list.h"
#define width 3
#define height 3
int a[height][width] = {1,2,3 , 4,5,6 , 7,8,9};

int main(int argc , char** argv[]){
    int row , column , choice , data;

  printf("Sample Array\n");
  display();
 do{
  printf("\n");
  printf("  ####################################\n");
  printf("  #    2D Array Implementation       #\n");
  printf("  ####################################\n");
  printf(" 1. Insert\n 2. Traverse\n 3. Search\n 4. Delete\n 5. Display\n");
  scanf("%d" , &choice);
  switch(choice){

     case 1:
         printf("Which Row And Column Do U Like To Update?\n");
        //  sleep(5);
         printf("Row:");
         scanf("%d" , &row);
         printf("Column:");
         scanf("%d" , &column);
         printf("Enter The Number:\n");
         scanf("%d" , &data);
         insert(row , column , data);
         break;
     case 2:
         traverse();
         break;
     case 3:
         search();
         break;
     case 4:
         printf("Which Row And Column Do U Like To Delete?\n");
        // sleep(1);
         printf("Row:");
         scanf("%d" , &row);
         printf("Column:");
         scanf("%d" , &column);
         delete(row , column);
         break;
     case 5:
         display();
         break;
    default:
         printf("Invalid Choice\n");
  }


   }while(choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5);
 
 



    return 0;
}

void insert(const int row  ,  const int column , int value){
      if ((row < 1 || column < 1) || (row > height || column > width)){
        printf("Enter a Value in the size of the Array\n");
        return;
    }

    for(int i = (height - 1); i >= (row - 1); i--){
        if( i != (row - 1)){
          for(int j = (width - 1); j >= 0; j--){
               a[i][j + 1] = a[i][j];

            }
        }
        else if ( i == (row - 1)){
             for(int j = (width - 1); j >= (column - 1); j--){
                 a[i][j + 1] = a[i][j];

            }

        }
    }

    a[row - 1][column - 1] = value;
    return;
}


void display(){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
         printf(" %d   " , a[i][j]);
        }
        printf("\n");
    }
    return;
}

void delete(const int row , const int  column){
    if ((row < 1 || column < 1) || (row > height || column > width)){
        printf("Enter a Value in the size of the Array\n");
        return;
    }

     a[row - 1][column - 1] = 0;
     for(int i = (row - 1); i < height; i++){
        if (i == (row - 1)){
         for(int j = (column - 1); j < width; j++){
             a[i][j] = a[i][j + 1];

         }
        }
        else if (i != (row - 1)){
             for(int j = 0; j < width; j++){
                 a[i][j] = a[i][j + 1];

             }

        }

     }

        a[height - 1][width - 1] = 0;
        return;

}


void traverse(){
 for(int i = 0; i < height; i++){
    for(int j = 0; j < width; j++){
        printf("Enter the Array[%d][%d]:\n" , i + 1 , j + 1);
        scanf("%d" , &a[i][j]);
    }
 }
  return;
}

void search(){     //linear search
    long int data;
    printf("Enter the number to search\n");
    scanf("%d" , &data);
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            if(a[i][j] == data){
                printf("Found the number %d in the Array[%d][%d]\n" , data , (i + 1) , (j + 1));
                return;
            }
            else
               continue;

        }
    }
    printf("Your number isnt found in the Array\n");
    return;

}


