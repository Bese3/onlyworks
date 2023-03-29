#include"monty.h"



int main(int argc , char *argv[]){



    return 0;
}
int process_lines(stack_t **stack , unsigned int line_numbers){
    
}


int process_opcode(stack_t **stack , int line_number , char *opcodes[]){
    for(int i = 0; opcodes[i]; i++){
        if(strcmp(opcodes[i] , "push") == 0)
        {
            m_push(stack , line_number , opcodes[i + 1]);
            break;
        }
        
    }
       return 0;

}