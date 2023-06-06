#include "hash.h"


int main(void)
{
    hash_table_t *ht;

    ht = hash_table_create(1024);
    printf("%p\n", (void *)ht);
    return (EXIT_SUCCESS);
}

hash_table_t *hash_table_create(unsigned long int size){
  hash_table_t* table = (hash_table_t*) malloc(sizeof(hash_table_t));
  table->size = size;
  table->array = (hash_node_t**)malloc(table->size*sizeof(hash_node_t));
  for(int i = 0; i < size; i++)
      table->array[i] = NULL;
    return table;
}