#include <stdio.h>
#include <stdlib.h>

struct ListNode {
     char *key;
     int value;
     struct ListNode* next;
};

struct HashMap{
     struct ListNode* hashMapArray[100];
     int max;
} HashMap;

void put(int,char*);
int get(char*);
int hash(char*);

void main(int argc,char* argv[]){
     HashMap.max = 100;
     put(1,"one");
     put(2,"two");
     get("one");
}


int hash(char* key){
   int total = 0;
   while(*key!='\0'){
        total += *key;
        key++;
   }
   return (total%HashMap.max);
}

void put(int value,char* key){
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->value = value;
    newNode->key = key;
    int hashed = hash(key);
    struct ListNode* currentNode = HashMap.hashMapArray[hashed];
    if(currentNode==NULL){
      HashMap.hashMapArray[hashed] = newNode;
      printf("Inserted %i at %i\n",value,hashed);
      return;
    }
    //Open Probing
    while(currentNode!=NULL){
      currentNode = currentNode->next;
    }
    currentNode->next = newNode;
    printf("Inserted %i at %i\n",value,hashed);
}


int get(char *key){
    int hashed = hash(key);
    struct ListNode* node = HashMap.hashMapArray[hashed];
    if(node==NULL){
       printf("Not found\n");
       return -1;
    }
    printf("%s\n",node->key);
    while(node->key!=key){
         node = node->next;
    }
    printf("Here is %i\n",node->value);
    return node->value;
}






