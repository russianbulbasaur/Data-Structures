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

void delete(char value){
    struct Node* parent = root;
    struct Node* currentNode = root;
    int isLeft = 0;
    while(currentNode!=NULL){
         if(currentNode->value==value){
             //If no right subtree
             if(currentNode->right==NULL){
               if(isLeft){
                 parent->left = currentNode->left;
               }else{
                 parent->right = currentNode->left;
               }
               printf("Deleted %c\n",currentNode->value);
               return;
             }
             //Traverse to last left subtree
             struct Node* subNode = NULL;
             currentNode = currentNode->right;
             while(currentNode!=NULL){
                  subNode = currentNode;
                  currentNode = currentNode->left;
             }
             if(isLeft){
               parent->left = subNode;
             }else{
               parent->right = subNode;
             }
             printf("Deleted %c\n",subNode->value);
             return;
          }
          else if(currentNode->value<value){
             isLeft = 0;
             parent = currentNode;
             currentNode = currentNode->right;
          }else{
             isLeft = 1;
             parent = currentNode;
             currentNode = currentNode->left;
          }
    }
    printf("%c not found\n",value);
    return;
}


void main(){
   insert('B');
   insert('C');
   insert('A');
   insert('E');
   insert('D');
   insert('H');
   insert('J');
   insert('I');
   preorder(root);
   delete('E');
   preorder(root);
}
