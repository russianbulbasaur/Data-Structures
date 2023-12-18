#include <stdio.h>
#include <stblib.h>
struct Queue{
  int capacity; //queue capacity
  int front; //to track head of queue (Consume from)
  int back; //to track the tail of queue (Produce into)
  int* elements; //only integer elements, you can make structures with custom body
} queue;


void enqueue(int value){
}

int dequeue(){
}


void main(int argc,char* argv[]){
    if(argc<2){
      printf("Enter queue capacity\n");
      exit(0);
    }
    queue.front = 0;
    queue.back = 0;
    sscanf(argv[1],"%i",&queue.capacity);
    int elements[queue.capacity];
    queue.elements = &elements;
}

