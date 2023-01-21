#include <stdio.h>
#include <stdlib.h>
struct Item{
  int value;
  struct Item* next;
};

struct Item nextinline;
struct Item lastinline;

void enqueue(int value){
   struct Item item;
   item.value = value;
   item.next = NULL;
   if(lastinline==NULL && nextinline==NULL){
     lastinline = &item;
     nextinline = &item;
     printf("Added %i \n",value);
     return;
   }
   printf("Added %i \n",value);
   lastinline->next = &item;
}



void dequeue(){
     if(nextinline==NULL){
      printf("Queue is empty");
      return;
     }
     printf("Value of next is %i \n",nextinline->value);
     nextinline = nextinline->next;
}

void main(){
  enqueue(2);
  enqueue(55);
  dequeue();
  dequeue();
}
