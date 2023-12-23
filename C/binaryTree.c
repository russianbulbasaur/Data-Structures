#include <stdio.h>
#include <stdlib.h>
struct Node{
     struct Node* left;
     struct Node* right;
     char value; //only char values in this tree
};

struct Node* root = NULL;

void preorder(struct Node* node){
     if(node==NULL){
        return;
     }
     printf("%c ",node->value);
     preorder(node->left);
     preorder(node->right);
}

void postorder(struct Node* node){
     if(node==NULL){
        return;
     }
     preorder(node->left);
     preorder(node->right);
     printf("%c ",node->value);
}

void inorder(struct Node* node){
     if(node==NULL){
        return;
     }
     preorder(node->left);
     printf("%c ",node->value);
     preorder(node->right);
}


void display(struct Node* currentNode){
    if(currentNode==NULL){
        return;
    }
    printf("%c\n",currentNode->value);
    display(currentNode->left);
    display(currentNode->right);
}

void insert(char value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    if(root==NULL){
       root = newNode;
       printf("Inserted : %c\n",value);
       return;
    }
    int insertOnLeft = 0;
    struct Node* parent = NULL;
    struct Node* currentNode = root;
    while(currentNode!=NULL){
       if(value==currentNode->value){
          printf("Duplicates cannot be inserted\n");
          return;
       }
       parent = currentNode;
       if(value<currentNode->value){
           currentNode = currentNode->left;
           insertOnLeft = 1;
       }else{
           currentNode = currentNode->right;
           insertOnLeft = 0;
       }
    }
    if(insertOnLeft){
       parent->left = newNode;
    }else{
       parent->right = newNode;
    }
    printf("Inserted : %c\n",value);
    return;
}

void find(char value){
     struct Node* currentNode = root;
     while(currentNode!=NULL){
          if(currentNode->value==value){
             printf("Found %c\n",value);
             return;
          }
          if(currentNode->value<value){
             currentNode = currentNode->right;
          }else{
             currentNode = currentNode->left;
          }
     }
     printf("%c not found\n",value);
     return;
}

void delete(){
}


void main(){
   insert('A');
   insert('B');
   insert('C');
   insert('D');
   insert('E');
   display(root);
   printf("\n");
   preorder(root);
   printf("\n");
   postorder(root);
   printf("\n");
   inorder(root);
   printf("\n");
   find('G');
   find('D');
}
