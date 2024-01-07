#include <stdio.h>
 #include <stdlib.h>

struct CircularQueue{
     int capacity;
     int rear;
     int front;
     int* elements;
} queue;



void enqueue(int value){
     if(queue.front==-1 && queue.rear==-1){
        queue.elements[0] = value;
        queue.front = 0;
        queue.rear = 0;
        printf("%i enqueued\n",queue.elements[0]);
        return;
     }
     int rear = (queue.rear+1)%queue.capacity;
     if(rear == queue.front){
       printf("The queue is full\n");
       return;
     }
     queue.rear = rear;
     queue.elements[rear] = value;
     printf("%i enqueued\n",queue.elements[rear]);
}



void dequeue(){
     if(queue.front==-1){
       printf("The queue is empty\n");
       return;
     }
     printf("Here is %i\n",queue.elements[queue.front]);
     int front = (queue.front+1)%queue.capacity;
     if(queue.front==queue.rear){
        queue.front = queue.rear = -1;
     }else{
        queue.front = front;
     }
}



void main(int argc,char* argv[]){
     if(argc<2){
        printf("Specify capacity\n");
        return;
     }
     queue.rear = -1;
     queue.front = -1;
     sscanf(argv[1],"%i",&queue.capacity);
     int elements[queue.capacity];
     queue.elements = elements;
     enqueue(1);
     enqueue(2);
     enqueue(3);
     enqueue(4);
     enqueue(5);
     enqueue(6);
     dequeue();
     enqueue(6);
     dequeue();
     enqueue(7);
     enqueue(8);
}
