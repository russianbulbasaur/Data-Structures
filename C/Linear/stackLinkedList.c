#include <stdio.h>
#include <stdlib.h>
#define null NULL
//Well no max limit, i have a lot of heap memory hahaha : )

struct Node{
      int value;//integer values on stack
      struct Node* next; //this is actually the previouslly push value on stack (A reversed linked list)
};

struct Stack{
     struct Node* top; //pointing to the current filled position
} stack;

void push(int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    if(stack.top==null){
         newNode->next = null;
    }else{
         newNode->next = stack.top;
    }
    stack.top = newNode;
    printf("Pushed %i\n",stack.top->value);
    return;
}

int pop(){
    if(stack.top==null){
       printf("Stack empty\n");
       return -1;
    }
    int value = stack.top->value;
    stack.top = stack.top->next;
    printf("Poped %i\n",value);
    return value;
}

void main(int argc,char* argv[]){
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
}
