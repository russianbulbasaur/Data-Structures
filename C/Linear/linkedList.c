#include <stdio.h>
#include <stdlib.h>
#define null NULL
struct Node{
    int value; //4 bytes
    struct Node* next; // 8 bytes
}; // Whole struct is 12 bytes exluding data padding

struct Node* head = null;
struct Node* tail = null;

void insert(int value){
   struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->value = value;
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
             printf("Deleted\n");
             free(node);
             return;
         }
         prev = node;
         node = node->next;
     }
}


void main(int argc, char* argv[]){
   insert(6);
   insert(7);
   display();
   delete(7);
   display();
   insert(9);
   insert(10);
   insert(11);
   insert(12);
   display();
}
