#include <stdio.h>
void main(int argc,char* argv[]){
   if(argc<2){
     printf("Enter target please\n");
     return;
   }
   int target = 0;
   sscanf(argv[1],"%i",&target);
   printf("Target : %i\n",target);
   int arr[15] = {1,2,3,4,5,7,8,9,12,14,23,56,678,768};
   int start = 0;
   int end = 14;
   int mid = 0;
   while(start<=end){
      mid = start + (end-start)/2;
      if(arr[mid]==target){
          printf("Found %i at %i\n",target,mid);
          return;
      }else if(arr[mid]<target){
          start = mid+1;
      }else{
          end = mid-1;
      }
   }
   printf("Not found %i\n",target);
   return;
}
