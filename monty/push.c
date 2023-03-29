#include"monty.h"
#include<ctype.h>

 size_t check_if_int(char *arg[]){
    int i = 1;
    for(i; arg[i]; i++){
        if(isdigit(*arg[i]) == 0){
            return 1;
        }
    }
    return 0;
 }

void m_push(stack_t **stack , unsigned int line_number  , char *arg[]){
    int n;
    if (arg == NULL || check_if_int(arg) != 1){
        printf("L<%d>: usage: push integer\n" , line_number);
        return;
    }
    n = atoi(*arg);
    push(stack , n);
        
}


