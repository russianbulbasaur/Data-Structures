#include <stdio.h>
#include <stdlib.h>
struct Node{
   int value;
   struct Node* left;
   struct Node* right;
};

struct Node* root = NULL;

void insert(int value){
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->value = value;
  if(root==NULL){
    root = newNode;
    return;
  }
  struct Node* currenthead = root;
  struct Node* prev = NULL;
  while(currenthead!=NULL){
     if(currenthead->value<value){
       prev = currenthead;
       currenthead = currenthead->right;
     }else if(currenthead->value>value){
       prev = currenthead;
       currenthead = currenthead->left;
     }
  }
  if(prev->value<value){
      prev->right = newNode;
  }else{
      prev->left = newNode;
  }
}

void del(int value){
   struct Node* currenthead = root;
   struct Node* prev = NULL;
   struct Node* consecutivenext = NULL;
   if(currenthead==NULL){
      printf("Nothing to traverse \n");
      return;
   }
   while(currenthead!=NULL){
        if(currenthead->value==value){
              struct Node* tbr_left = currenthead->left;
              struct Node* tbr_right = currenthead->right;
              struct Node* temp_left = NULL;
              if(tbr_left==NULL && tbr_right==NULL){
                    if(prev->value>value){
                             prev->left = NULL;
                    }else{
                             prev->right = NULL;
                    }
              }else if(tbr_right==NULL){
                    prev->left = tbr_left;
                    prev->right = NULL;
              }else{
                 currenthead = currenthead->right;
                 while(currenthead!=NULL){
                       temp_left = currenthead;
                       currenthead = currenthead->left;
                 }
                 temp_left->left = tbr_left;
                 if(tbr_right->value==value){
                 tbr_right = NULL;
                 }
                 temp_left->right = tbr_right;
                 if(value>prev->value){
                       prev->right = temp_left;
                 }else if(value<prev->value){
                       prev->left = temp_left;
                 }
             }
        }
        else if(value>currenthead->value){
             prev = currenthead;
             currenthead = currenthead->right;
        }
        else if(value<currenthead->value){
             prev = currenthead;
             currenthead = currenthead->left;
        }
   }
}

void main(){
   insert(34);
   insert(33);
   insert(90);
   insert(85);
   insert(88);
   insert(44);
   insert(47);
   insert(15);
   insert(13);
   insert(20);
   insert(16);
   insert(14);
   del(15);
   printf("%i",(root->left->left->left->right->value));
}
