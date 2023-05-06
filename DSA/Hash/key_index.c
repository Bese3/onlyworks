#include"hash.h"

int main(void)
{
    char *s;
    unsigned long int hash_table_array_size;

    hash_table_array_size = 1024;
    s = "cisfun";
    printf("%lu\n", hash_djb2((unsigned char *)s));
    printf("%lu\n", key_index((unsigned char *)s, hash_table_array_size));
    s = "Don't forget to tweet today";
    printf("%lu\n", hash_djb2((unsigned char *)s));
    printf("%lu\n", key_index((unsigned char *)s, hash_table_array_size));
    s = "98";
    printf("%lu\n", hash_djb2((unsigned char *)s));
    printf("%lu\n", key_index((unsigned char *)s, hash_table_array_size));  
    return (EXIT_SUCCESS);
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