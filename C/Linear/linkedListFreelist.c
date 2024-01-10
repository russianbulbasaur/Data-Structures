#include <stdio.h>
#include <stdlib.h>
#define null NULL
struct Node{
    int value; //4 bytes
    struct Node* next; // 8 bytes
}; // Whole struct is 12 bytes exluding data alignment

struct Node* head = null;
struct Node* tail = null;
struct Node* freeListHead = null;
struct Node* freeListTail = null;

void insert(int value){
   struct Node* newNode;
   if(freeListHead==null){
         newNode = (struct Node*)malloc(sizeof(struct Node));
   }else{
        newNode = freeListHead;
        freeListHead = freeListHead->next;
   }
   newNode->value = value;
   printf("Node used address : %p\n",newNode);
   if(head==null){
      head = newNode;
      tail = newNode;
      return;
   }
   tail->next = newNode;
   tail = newNode;
   return;
}

void display(){
     struct Node* node = head;
     while(node!=null){
          printf("%i ->",node->value);
          node = node->next;
     }
     printf("\n");
}

void find(int value){
     struct Node* node = head;
     while(node!=null){
          if(node->value==value){
             printf("Found\n");
             return;
          }
          node = node->next;
     }
     printf("Not found\n");
}

void insertIntoFreeList(struct Node* node){
     if(freeListHead==null){
        freeListHead = node;
        freeListTail = node;
        return;
     }
     freeListTail->next = node;
     freeListTail = node;
     return;
}

void delete(int value){
     struct Node* prev = null;
     struct Node* node = head;
     while(node!=null){
         if(node->value==value){
             if(prev==null){
                head = node->next;
             }else{
                prev->next = node->next;
                tail = (node->next==null)?prev:tail;
             }
             insertIntoFreeList(node);
             printf("Deleted\n");
             return;
         }
         prev = node;
         node = node->next;
     }
}


void main(int argc, char* argv[]){
   insert(4);
   display();
   delete(4);
   display();
   insert(6);
   insert(7);
   display();
   delete(7);
   display();
   insert(5);
   insert(9);
   insert(10);
   insert(40);
   display();
}
