#ifndef LIST_H
#define LIST_H


typedef struct node{
    int x;
    struct node* next;
 }node;
  void insert_end(node** root , int value);
  void insert_beginning(node** root , int value);
  void deallocate(node** root);
  void insert_middle(node* add , int value);
  void insert_sorted(node** root , int value);
  void delete_list(node** root , int value);
  int has_loop(node* root);
  #endif/*LIST_H*/
