#include <iostream>
using namespace std;
int main(){
 int array1[5] = {34,45,67,89,100};
 int array2[5] = {35,56,65,97,120};
 int len1 = sizeof(array1)/4;
 int len2 = sizeof(array2)/4;
 int output[10] = {};
 int outindex = 0;
 int oneindex = 0;
 int twoindex = 0;
 while(oneindex!=5 || twoindex!=5){
  if(oneindex==5){
     output[outindex++] = array2[twoindex++];
     continue;
  }
  if(twoindex==5){
     output[outindex++] = array1[oneindex++];
   }
  if(array1[oneindex]<array2[twoindex]){
  output[outindex++] = array1[oneindex];
  oneindex++;
  }
  else if(array1[oneindex]>array2[twoindex]){
   output[outindex++] = array2[twoindex];
   twoindex++;
  }
  else{
   output[outindex++] = array1[oneindex];
   oneindex++;
   twoindex++;
  }
 }
 for(int i=0;i<(sizeof(output)/4);i++){
 cout << output[i] << endl; 
}
 return 1;
}
