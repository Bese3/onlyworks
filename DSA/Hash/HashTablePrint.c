#include"hash.h"

int main(void)
{
    hash_table_t *ht;

    ht = hash_table_create(1024);
    hash_table_print(ht);
    hash_table_set(ht, "c", "fun");
    hash_table_set(ht, "python", "awesome");
    hash_table_set(ht, "Bob", "and Kris love asm");
    hash_table_set(ht, "N", "queens");
    hash_table_set(ht, "Asterix", "Obelix");
    hash_table_set(ht, "Betty", "Cool");
    hash_table_set(ht, "98", "Battery Street");
    hash_table_print(ht);
    return (EXIT_SUCCESS);
}


hash_table_t *hash_table_create(unsigned long int size){
  hash_table_t* table = (hash_table_t*) malloc(sizeof(hash_table_t));
  table->size = size;
  table->array = (hash_node_t**)calloc(table->size , sizeof(hash_node_t));
  for(int i = 0; i < size; i++)
      table->array[i] = NULL;
    return table;
}

unsigned long int hash_djb2(const unsigned char *str)
{
    unsigned long int hash;
    int c;

    hash = 5381;
    while ((c = *str++))
    {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return (hash);
}
unsigned long int key_index(const unsigned char *key, unsigned long int size){
     unsigned long i = 0;

    for (int j = 0; key[j]; j++)
        i += key[j];

    return i % size;
}

int hash_table_set(hash_table_t *ht, const char *key, const char *value){
    hash_node_t* new_hash = (hash_node_t*)malloc(sizeof(hash_node_t));
   
    if (!ht || !key || strlen(key) == 0 || !new_hash){
        return 0;
    }
     unsigned int index = hash_djb2((const char*)key) % ht->size;
    new_hash->key = strdup(key);
    new_hash->value = strcmp(value , "") ? strdup(value) : "";

    if(!ht->array[index]){
        ht->array[index] = new_hash;
    }
    else if(strcmp(ht->array[index]->key , key) != 0){
        new_hash->next = ht->array[index];
        ht->array[index] = new_hash;

    }
    else{
      free(new_hash->value);
      free(new_hash);
      ht->array[index]->value = strdup(value);    
    }

}


char *hash_table_get(const hash_table_t *ht, const char *key){
    if (!ht || !key || strlen(key) == 0){
     return NULL;
    }
    unsigned int index = hash_djb2((const char*)key) % ht->size;
    hash_node_t *node = ht->array[index];
    while (node){
        if (strcmp(node->key , key) == 0){
            return node->value;
        }
        node = node->next;
    }
    return NULL;
}


void hash_table_print(const hash_table_t *ht)
{
	unsigned long i, j;
	hash_node_t *node;

	if (!ht)
		return;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		if (!ht->array[i])
		{
			if (i == ht->size - 1)
				printf("}\n");
			 continue;
		}

		node = ht->array[i];
		while (node)
		{
			// if (node->next)
			// 	comma_to_concat = ", ";
			// else
			// 	comma_to_concat = "";
			printf("\'%s\': \'%s\'", node->key, node->value);
			node = node->next;
		}

		
		for (j = i + 1; j < ht->size; j++)
		{
			if (ht->array[j])
			{
				printf(", ");
				break;
			}
		}
	}
}