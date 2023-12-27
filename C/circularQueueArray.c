#include <stdio.h>
#include <stdlib.h>

struct CircularQueue{
     int capacity;
     int rear;
     int front;
     int* elements;
} queue;



void enqueue(int value){
     int isFull = ((queue.rear+2)%queue.capacity);
     if(isFull){
       printf("The queue is full\n");
       return;
     }
     int rear = (queue.rear+1)%queue.capacity;
     queue.rear = rear;
     elements[rear] = value;
     printf("%i enqueued\n",value);
}

void dequeue(){
     int isEmpty = (((queue.rear + queue.capacity)+queue.front-1)==0);
     if(isEmpty){
       printf("The queue is empty\n");
       return;
     }
     printf("Here is %i\n",elements[queue.front]);
     int front = (queue.front+1)%queue.capacity;
     queue.front = front;
}



void main(int argc,char* argv[]){
     if(argc<2){
        printf("Specify capacity\n");
        return;
     }
     queue.rear = 0;
     queue.front = 1;
     sscanf(argv[1],"%i",&queue.capacity);
     int elements[queue.capacity];
     queue.elements = elements;
}
