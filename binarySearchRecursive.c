#include <stdio.h>
void bs(int a[],int from,int to,int element){
     int mid = (from+to)/2;
     if(a[mid]==element){
         printf("Found %i at %i",a[mid],mid);
         return;
     }
     if(element>a[mid]){
        bs(a,mid+1,to,element);
     }else{
        bs(a,0,mid,element);
     }
}

void main(){
  int a[] = {10,20,30,40,50,60,70,100,120,140,201,400};
  bs(a,0,11,400);
}
