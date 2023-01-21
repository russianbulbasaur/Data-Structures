#include <stdlib.h>
#include <stdio.h>
struct Node{
   int value;
   struct Node* next;
};

struct Node* top = NULL;
struct Node* bottom = NULL;


void push(int value){
 struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
 newNode->value = value;
 newNode->next = top;
 printf("%s %i \n","Pushed ",value);
 if(top==NULL){
   top = newNode;
   bottom = newNode;
   return;
 }
 top = newNode;
}

void pop(){
  if(top==NULL){
    printf("%s","Stack empty");
    return;
  }
  printf("%i \n",top->value);
  struct Node* temp = top->next;
  top = temp; 
}

void main(){
  push(1);
  push(2);
  push(3);
  push(5);
  push(9);
  pop();
  pop();
  pop();
  pop();
  pop();
  pop();
}
