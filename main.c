#include <stdio.h>
#include <stdlib.h>




  int merge(int a[] ,  int i ,int b[] , int j , int r[]);

int main()
{
    int array1[] = {23,43,13,54,65,76,32,32,43};
     int array2[] ={34,21,12,65,74,56,98,89};
     int result[17];
    int a = 9;
    int b = 8;
     merge(array1 , a, array2 ,b ,result);
    for (int k=0;k<17;k++)
        printf("" , merge(array1 , a, array2 ,b ,result));
 return (0);
}

int merge(int a[] ,  int i ,int b[] , int j , int r[])
{
  if (i != 0 && j!=0)
  {
      if (j=0)
      {
          r[0] = a[0];
          merge(a+1,i-1 , b  , j ,r+1);

      }
      if (i=0)
      {
          r[0] = b[0];
          merge(a ,i , b+1 ,j-1,r+1);

      }
      else if (a[0] < b[0])
      {
          r[0] = a[0];
          merge(a+1 , i-1 ,b , j ,r+1);
      }
      else
      {
          r[0] = b[0];
          merge(a ,i , b+1 ,j-1 ,r+1);
      }
  }
  else
    return (0);

}
