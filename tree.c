#include<stdio.h>
#include<stdlib.h>


typedef struct node{
    int data;
    struct node *left , *right;
}node;

node *create();
void preorder(node* root);
void inorder(node* root);
void postorder(node* root);
node *insert_bst(node* root , int val);
node* search(node* root , int val);
node* delete(node* root , int val);
node* findlargest(node* root);




int main(){

 node *root = NULL;
   root = create();
//    preorder(root);
//  inorder(root);
  //  postorder(root);
  search(root , 18);


    return 0;
}

node *create(){
  int data;
  node *new_node = (node*)malloc(sizeof(node));
  printf("Enter data (-1 for NULL): ");
  scanf("%d" , &data);
  new_node->data = data;
  if(data == -1)
   return NULL;

  printf("Enter left child of %d: ", data);
  new_node->left = create();
  printf("Enter right child of %d: " , data);
  new_node->right = create();

  return new_node;

}
void preorder(node* root){
    if(root == NULL)
        return;
    printf("%d " , root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(node* root){
    if(root == NULL)
      return;
    inorder(root->left);
    printf("%d " , root->data);
    inorder(root->right);


}
void postorder(node* root){
    if (root == NULL)
      return;
      postorder(root->left);
      postorder(root->right);
      printf("%d" , root->data);
}


node *insert_bst(node* root , int val){
  node* new_node = (node*)malloc(sizeof(node));
     new_node->data = val;
     new_node->right = NULL;
     new_node->left = NULL;
  if(root == NULL){
     root = new_node;
    //  printf("%d" , root->dat a);
     return root;
  }
  else if(root->data <= val)
     insert_bst(root->right , val);
  else
     insert_bst(root->left , val);


}


node* search(node* root , int val){
  if(root == NULL){
    printf("cant find ur value\n");
    return NULL;
  }

  if(root->data == val){
    printf("Found the value %d\n" , root->data);
     return root;
  }
  if (root->data > val){
      printf("Going to left\n");
      return search(root->left , val);
  }
   printf("Going to right\n");
  return search(root->right , val);

}


node* delete(node* root , int val){
  if(root == NULL){
    printf("value is not found\n");
    return root;
  }
  else if(val < root->data)
    delete(root->left , val);
  else if(val > root->data)
    delete(root->right , val);
  else if(root->right && root->left){
    node* temp = findlargest(root->left);
    delete(root->left , temp->data);
    root->data = temp->data;
    free(temp);
  }
  else{
    node* temp = root;
    if(root->right == NULL && root->left == NULL)
      root = NULL;
    else if(root->right)
      root = root->right;
    else
       root = root->left;
    free(temp);
  }

}


node* findlargest(node* root){
  if(root == NULL || root->right == NULL)
    return root;

  return findlargest(root->right);

}
