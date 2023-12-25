//Linear queue suffers with reusability problems
//The front will keep moving forward leaving the beginning spaces unusable
//If we move the elements in the queue then we'll have the extra overhead of moving items
#include <stdio.h>
#include <stdlib.h>
struct Queue{
  int capacity; //queue capacity
  int front; //to track head of queue (Consume from)
  int back; //to track the tail of queue (Produce into)
  int* elements; //only integer elements, you can make structures with custom body
} queue;


void enqueue(int value){
     if(queue.back==queue.capacity-1){
       printf("Queue full\n");
       return;
     }
     queue.elements[++queue.back] = value;
     printf("%i enqueued\n",value);
}

void dequeue(){
    if(queue.front>queue.back){
      printf("Queue empty\n");
      return;
    }
    printf("Here is %i\n",queue.elements[queue.front++]);
    return;
}


void main(int argc,char* argv[]){
    if(argc<2){
      printf("Enter queue capacity\n");
      exit(0);
    }
    queue.front = 0;
    queue.back = -1;
    sscanf(argv[1],"%i",&queue.capacity);
    int elements[queue.capacity];
    queue.elements = elements;
    enqueue(1);
    enqueue(2);
    enqueue(3);
    dequeue();
    dequeue();
    dequeue();
}

