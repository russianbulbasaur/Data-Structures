#include <stdio.h>
int findMin(int arr[],int i,int j){
    if(i==j){
        return i;
    }
    int jj = findMin(arr,i+1,j);
    return (arr[i]>arr[jj])?jj:i;
}

void recurse(int arr[],int index,int to){
    if(index==to){
       return;
    }
    int min = findMin(arr,index,to);
    int temp = arr[index];
    arr[index] = arr[min];
    arr[min] = temp;
    recurse(arr,index+1,to);
}

void main(){
   int arr[] = {3,4,2,5,2,1,5,4,56,3,5,3,2,2,4,54,6,7,3,-5,348,6,43,1,3};
   recurse(arr,0,24);
   for(int i=0;i<25;i++){
      printf("%i,",arr[i]);
   }
}
