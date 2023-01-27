#include <stdio.h>
struct CustomSetItem{
   int key;
};
//Fucking O(n) lookup time

void find(struct CustomSetItem items[],int n,int key){
      for(int i=0;i<n;i++){
          if(items[i].key==key){
             printf("Found");
             return;
          }
      }
      printf("Not found");
      return;
}

void main(){
   int capacity;
   scanf("%i",&capacity);
   struct CustomSetItem items[capacity];
   int inputs[] = {234,43,543,52,342,324};
   for(int i=0;i<capacity;i++){
         items[i].key = inputs[i];
   }
   find(items,capacity,543);
}
