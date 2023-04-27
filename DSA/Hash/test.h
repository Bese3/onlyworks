#ifndef TEST_H
#define TEST_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Defines the HashTable item.
typedef struct Ht_item
{
    char* key;
    char* value;
} Ht_item;

// Defines the HashTable.
typedef struct HashTable
{
    // Contains an array of pointers to items.
    Ht_item** items;
    Linkedlist** overflow_buckets;
    int size;
    int count;
} HashTable;

typedef struct LinkedList{
    Ht_item* item;
    struct LinkedList* next;
}Linkedlist;
unsigned long hash_function(char* str);
Ht_item* create_item(char* key , char* value);
HashTable* create_table(int size);
void free_item(Ht_item* items);
void free_table(HashTable* table);
void print_table(HashTable* table);
void ht_insert(HashTable* table , char* key , char* value);
char* ht_search(HashTable* table , char* key);
void print_search(HashTable* table , char* key);
Linkedlist* allocate_list();
Linkedlist* linkedlist_insert(Linkedlist* list , Ht_item* item);
Ht_item* linkedlist_remove(Linkedlist* list);
void free_linkedlist(Linkedlist* list);
#endif /*TEST_H*/