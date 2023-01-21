#include <stdlib.h>
#include <stdio.h>
struct Stack{
    int* items;
    int top;
    int bottom;
    int size;
};

struct Stack* makeStack(int size){
    struct Stack *stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->items = (int*)malloc(size*sizeof(int));
    stack->top = -1;
    stack->bottom = -1;
    stack->size = size;
    return stack;
}

void push(int value,struct Stack* stack){
    if((stack->top)==stack->size){
     printf("%s","Stack is full \n");
     return;
    }
    stack->top = stack->top + 1;
    stack->items[stack->top] = value;
    printf("%s","Value pushed \n");
}

void pop(struct Stack* stack){
    if(stack->top==stack->bottom){
        printf("%s","Underflow \n");
        return;
    }
    printf("%i \n",stack->items[stack->top]);
    stack->top = stack->top -1;
}


void peek(struct Stack* stack){
    if(stack->top==-1){
      printf("%s","Stack empty");
      return;
     }
     printf("%i \n",stack->items[stack->top]);
     free(stack);
}



void main(){
  struct Stack* stack = makeStack(2);
  push(1,stack);
  push(2,stack);
  push(3,stack);
  peek(stack);
  pop(stack);
}
