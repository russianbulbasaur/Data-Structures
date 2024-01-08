#include <stdlib.h>
#include <stdio.h>
struct Node{
   int value;
   struct Node* left;
   struct Node* right;
};


struct ListNode{
  struct Node* node;
  struct ListNode* next;
};

void enqueue(struct Node*);
struct Node* dequeue();
void makeTree();
void bfs();
void insert();
struct Node* peek();

struct Node* root = NULL;

struct ListNode* head = NULL;
struct ListNode* tail = NULL;

void main(int argc,char* argv[]){
    makeTree();
    bfs();
}


void bfs(){
    enqueue(root);
    while(peek()!=NULL){
        struct Node* currentNode = dequeue();
        printf("Visited : %i\n",currentNode->value);
        if(currentNode->left!=NULL){
           enqueue(currentNode->left);
        }
        if(currentNode->right!=NULL){
           enqueue(currentNode->right);
        }
    }
}


struct Node* peek(){
    if(head==NULL){
        printf("Queue is empty\n");
        return NULL;
     }
     struct Node* tbr = head->node;
     return tbr;
}

void enqueue(struct Node* node){
     struct ListNode* listNode = (struct ListNode*)malloc(sizeof(struct ListNode));
     listNode->node = node;
     if(head==NULL){
       head = listNode;
       tail = listNode;
       return;
     }
     tail->next = listNode;
     tail = listNode;
}


struct Node* dequeue(){
     if(head==NULL){
        printf("Queue is empty\n");
        return NULL;
     }
     struct Node* tbr = head->node;
     head = head->next;
     return tbr;
}


void makeTree(){
    insert(55);
    insert(22);
    insert(77);
    insert(30);
    insert(99);
    insert(10);
}


void insert(int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    if(root==NULL){
      root = newNode;
      printf("Inserted %i\n",value);
      return;
    }
    struct Node* prevNode = root;
    struct Node* currentNode = root;
    int insertOnLeft = 0;
    while(currentNode!=NULL){
         if(currentNode->value<value){
           prevNode = currentNode;
           insertOnLeft = 0;
           currentNode = currentNode->right;
         }else if(currentNode->value>value){
           prevNode = currentNode;
           insertOnLeft = 1;
           currentNode = currentNode->left;
         }else{
           printf("Duplicate values");
           return;
         }
    }
    if(insertOnLeft){
       prevNode->left = newNode;
       printf("Inserted %i\n",value);
       return;
    }
    prevNode->right = newNode;
    printf("Inserted %i\n",value);
    return;
}


