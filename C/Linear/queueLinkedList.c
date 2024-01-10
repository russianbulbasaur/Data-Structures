#include <stdio.h>
#include <stdlib.h>
//Well, unlimited capacity
struct Node{
    int value; //Integer value
    struct Node* next;
};


struct Queue{
     struct Node* front;
     struct Node* back;
} queue;


void enqueue(int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    if(queue.back==NULL){
       queue.back = newNode;
       queue.front = newNode;
       printf("%i inserted\n",value);
       return;
    }
    queue.back->next = newNode;
    queue.back = newNode;
    printf("%i inserted\n",value);
}

void dequeue(){
   if(queue.front==NULL){
      printf("Queue is empty\n");
      return;
   }
   printf("Here is %i\n",queue.front->value);
   queue.front = queue.front->next;
}


void main(int argc,char* argv[]){
     enqueue(10);
     enqueue(5);
     enqueue(9);
     dequeue();
     enqueue(11);
     dequeue();
     dequeue();
     dequeue();
     dequeue();
}
