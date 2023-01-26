#include <stdlib.h>
#include <stdio.h>
struct Heap{
   int capacity;
   int* arr;
   int next;
};

struct Heap* build(int capacity){
   struct Heap* heap = (struct Heap*)malloc(sizeof(struct Heap));
   heap->capacity = capacity;
   heap->arr = (int*)malloc(capacity*sizeof(int));
   heap->next = 0;
   return heap;
}

void maxHeapify(struct Heap* heap){
      int rootIndex = 0;
      int temp = 0;
      int maxChildIndex = 0;
      while(heap->capacity){
          maxChildIndex = (heap->arr[(rootIndex*2)+1]>heap->arr[(rootIndex*2)+2])?(rootIndex*2)+1:(rootIndex*2)+2;
          if(maxChildIndex>heap->next){
               break;
          }
          if(heap->arr[rootIndex]<heap->arr[maxChildIndex]){
          temp = heap->arr[rootIndex];
          heap->arr[rootIndex] = heap->arr[maxChildIndex];
          heap->arr[maxChildIndex] = temp;
          rootIndex = maxChildIndex;
          }else{
          break;
          }
      }
}


void extractMax(struct Heap* heap){
      if(heap->next==0){
             printf("Underflow \n");
             return;
      }
      int tobereturned = heap->arr[0];
      if(heap->next==1){
        printf("%i \n",tobereturned);
        return;
      }
      heap->arr[0] = heap->arr[heap->next-1];
      heap->arr[heap->next-1] = 0;
      maxHeapify(heap);
      printf("Max priority : %i \n",tobereturned);
}

void insert(int value,struct Heap* heap){
      if(heap->next==0){
      heap->arr[heap->next++] = value;
      return;
      }
      if(heap->next==heap->capacity){
      printf("Over flow \n");
      return;
      }
      heap->arr[heap->next] = value;
      int parent = (heap->next - 1)/2;
      int i = heap->next;
      int temp = 0;
      while(parent>=0 && heap->arr[parent]<heap->arr[i]){
             temp = heap->arr[parent];
             heap->arr[parent] = heap->arr[i];
             heap->arr[i] = temp;
             i = parent;
             parent = (parent-1)/2;
      }
      heap->next++;
}

void printHeap(struct Heap* heap){
    for(int i=0;i<heap->capacity;i++){
       printf("%i ",heap->arr[i]);
    }
    printf("\n");
}

void main(){
   struct Heap* heap = build(20);
   insert(95,heap);
   insert(63,heap);
   insert(68,heap);
   insert(56,heap);
   insert(59,heap);
   insert(99,heap);
   insert(96,heap);
   printHeap(heap);
   extractMax(heap);
   printHeap(heap);
}
