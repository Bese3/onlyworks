#include<stdio.h>
#include<stdlib.h>


int main(int argc , char* argv[]){
int count = 1;
int sum  = 0;
char *ptr = 0;
FILE* file;
if (argc == 1)
	{
		printf("0\n");
		return (0);
	};
 while(count < argc){
    file  = fopen(argv[count] , "r");
  sum += strtol(argv[count] , &ptr , 10);
  if (*ptr != 0)
		{
			printf("Error\n");
			return (1);
		}
  count++;
 }
 printf("%d\n" , sum);
 return EXIT_SUCCESS;

}