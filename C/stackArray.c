#include <stdio.h>
#include <stdlib.h>
struct Stack{
     int max;
     int top; //pointing to the current filled position
     int* elements; //only integers can be pushed on this stack
} stack;

void push(int value){
     if((stack.top+1)==stack.max){
        printf("Stack full%i\n",stack.top);
        return;
     }
     stack.elements[++(stack.top)] = value;
     printf("Pushed %i\n",stack.elements[stack.top]);
}

int pop(){
    if(stack.top<0){
       printf("Stack empty\n");
       exit(0);
    }
    int val = (stack.elements[stack.top--]);
    printf("Poped : %i\n",val);
    return val;
}

void init(int capacity){
       int elements[capacity];
       stack.max = capacity;
       stack.top = -1;
       stack.elements = &elements[0];
       printf("Stack initialized with %i capacity of integer elements\n",capacity);
       return;
}

void main(int argc,char* argv[]){
    if(argc<2){
      printf("Enter stack capacity");
      return;
    }
    int capacity;
    sscanf(argv[1],"%i",&capacity);
    init(capacity);
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
