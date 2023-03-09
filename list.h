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
  void reverse(node** root);



   /**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for project
 */
 typedef struct listint_s
 {
    int n;
    struct listint_s *next;
 } listint_t;

 size_t print_listint(const listint_t *h);
 int listint_len(const listint_t *h);
 listint_t *add_nodeint_end(listint_t **head, const int n);
 void free_listint(listint_t *head);
 listint_t reverse_list(listint_t** head);
 
  


 int is_palindrome(listint_t **head);
  #endif/*LIST_H*/
