//Also can be a illustation of heap
#include <stdio.h>
#include <stdlib.h>

struct Task{
   char* name;
   int priority;
};


struct Heap{
   //default 100 slots in the heap
   struct Task* tasks[100];
} heap;



void maxHeapify();
void insert(char*,int);
struct Task* extract();
void display();

void main(int argc,char* argv[]){
    insert("Task 1",2);
    insert("Task 2",4);
    insert("Task 3",-3);
    display();
}


void insert(char* name,int priority){
    struct Task* newTask = (struct Task*)malloc(sizeof(struct Task));
    newTask->name = name;
    newTask->priority = priority;
    int nextIndex = 0;
    while(heap.tasks[nextIndex]!=NULL){
        if(heap.tasks[nextIndex]->priority<priority){
           nextIndex = (nextIndex*2) + 2;
        }else if(heap.tasks[nextIndex]->priority>=priority){
           nextIndex = (nextIndex*2) + 1;
        }
    }
    heap.tasks[nextIndex] = newTask;
    printf("Inserted %s\n",heap.tasks[nextIndex]->name);
}


void display(){
    int currentIndex = 0;
    while(heap.tasks[currentIndex]!=NULL){
        printf("%s %i -> ",heap.tasks[currentIndex]->name,heap.tasks[currentIndex]->priority);
        currentIndex++;
    }
    printf("\n");
}

void maxHeapify(){
}

struct Task* extract(){
     return NULL;
}
