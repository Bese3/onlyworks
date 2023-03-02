#include <stdio.h>
#include <stdlib.h>






int main()
{
   int num = 9;
   int pc =num | 0b0110;
   printf("%d" , pc);





}





/*int merge(long int a[] ,  int i ,long int b[] , int j , long int r[]);

int main()
{
    long int array1[] = {23,45,67,87,98};
    long  int array2[] ={12,21,32,53,35};
  long    int result[7];
    int a = 5;
    int b = 5;
     merge(array1 , a, array2 ,b ,result);
    for (int k=0;k < a+b;k++)
        printf("%ld\n" , result[k]);
 return (0);
}

int merge(long int a[] ,  int i ,long int b[] , int j , long int r[])
{
  if (i != 0 && j!=0)
  {
      if (j==0 || a[i] < b[j])
      {
          r[0] = a[0];
          merge(a+1,i-1 , b  , j ,r+1);

      }
      else if (i==0 || a[i] > b[j])
      {
          r[0] = b[0];
          merge(a ,i , b+1 ,j-1,r+1);

      }
  }
  else
    return (0);

}
*/
