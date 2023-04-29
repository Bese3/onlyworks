#include"test.h"
#define CAPACITY 50000 // Size of the HashTable.


int main(){
     
     
    HashTable *ht = create_table(CAPACITY);
    ht_insert(ht, (char *)"1", (char *)"First address");
    ht_insert(ht, (char *)"2", (char *)"Second address");
    ht_insert(ht, (char *)"Hel", (char *)"Third address");
    ht_insert(ht, (char *)"Cau", (char *)"Fourth address");

    print_search(ht , (char *)"Hel");
    print_table(ht);


    return 0;
}


unsigned long hash_function(char* str)
{
    unsigned long i = 0;

    for (int j = 0; str[j]; j++)
        i += str[j];

    return i % CAPACITY;
}
Ht_item* create_item(char* key , char* value){
    Ht_item* items = (Ht_item*) malloc(sizeof(Ht_item));
    items->key = (char*) malloc(sizeof(strlen(key) + 1));
    items->value = (char*) malloc(sizeof(strlen(value) + 1));
    strcpy(items->key , key);
    strcpy(items->value , value);
    return items;
}

HashTable* create_table(int size){
 HashTable* table = (HashTable*) malloc(sizeof(HashTable));
 table->size = size;
 table->count = 0;
 table->items = (Ht_item**) calloc(table->size , sizeof(Ht_item));
 
 for (int i = 0; i < table->size; i++){
    table->items[i] = NULL;  
 }
//  table->overflow_buckets = create_overflow_buckets(table);
 return table;
}

void free_item(Ht_item* items){
    free(items->key);
    free(items->value);
    free(items);
}

void free_table(HashTable* table){
    for(int i = 0; i < table->size; i++){
        Ht_item* items = table->items[i];
        if (items != NULL){
            free_item(items);
        }

    }
    free(table->items);
    free(table);
}

void print_table(HashTable* table){
    printf("\nHash Table\n-------------------\n");
    for(int i = 0; i < table->size; i++){
        if(table->items[i])
        printf("Index: %d , Key: %s , Value: %s\n" , i , table->items[i]->key , table->items[i]->value);
    }
    printf("-------------------\n\n");
}

void ht_insert(HashTable* table , char* key , char* value){
  int index = hash_function(key);
  Ht_item*  item = create_item(key , value);
  Ht_item* curr = table->items[index];
  if(curr == NULL){
    if(table->count == table->size){
        printf("Insert Error: Hash Table is full\n");
        free_item(item);
        return;
    }
    table->items[index] = item;
    table->count++;
  }
  else{
     if(strcmp(curr->key , key) == 0){
        strcpy(table->items[index]->value , value);
        return;
     }
  }

}
char* ht_search(HashTable* table , char* key){
 int index = hash_function(key);
 Ht_item* item = table->items[index];
 if(item != NULL){
    if(strcmp(item->key  , key) == 0){
        return item->value;
    }
 }
 return NULL;
}
void print_search(HashTable* table , char* key){
  char* val;
  val = ht_search(table , key);
  if(val == NULL){
    printf("Key:%s does not exist\n", key);
    return;
  }
  else{
    printf("Key:%s, Value:%s\n", key, val);
  }
  return;
}

Linkedlist* allocate_list(){
     Linkedlist* list = (Linkedlist*) malloc(sizeof(Linkedlist));
     return list;
}
Linkedlist* linkedlist_insert(Linkedlist* list , Ht_item* item){
    if(list == NULL){
            Linkedlist* head = allocate_list();
            head->item = item;
            head->next = NULL;
            list = head;
            return head;
    }
    else if(list->next == NULL){
        Linkedlist* node = allocate_list();
        node->item = item;
        node->next = NULL;
        list->next = node;
        return list;
    }
    Linkedlist* temp = list;
    while(temp->next->next){
        temp = temp->next;
    }
    Linkedlist* node = allocate_list();
    node->item = item;
    node->next = NULL;
    temp->next = node;
    return list;
}

 Ht_item* linkedlist_remove(Linkedlist* list){
    // Removes the head from the LinkedList.
    // Returns the item of the popped element.
    if (!list)
        return NULL;

    if (!list->next)
        return NULL;

    Linkedlist* node = list->next;
    Linkedlist* temp = list;
    temp->next = NULL;
    list = node;
    Ht_item* it = NULL;
    memcpy(temp->item, it, sizeof(Ht_item));
    free(temp->item->key);
    free(temp->item->value);
    free(temp->item);
    free(temp);
    return it;
}

void free_linkedlist(Linkedlist* list){
    Linkedlist* temp;
    while(!list){
        temp = list;
        list = list->next;
        free(temp->item->key);
        free(temp->item->value);
        free(temp->item);
    }
}

// Linkedlist** create_overflow_buckets(HashTable* table){
//     Linkedlist* buckets = (Linkedlist*) calloc(table->size , sizeof(Linkedlist*));
//     for (int i = 0; i < table->size; i++){
//         buckets[i] = NULL;
//     }
//     return &buckets;
// }

// void free_overflow_table(HashTable* table){
//   Linkedlist* buckets = table->overflow_buckets;
//   for(int i = 0; i < table->size; i++){
//     free_linkedlist(buckets[i]);
//   }
//   free(buckets);
// }
