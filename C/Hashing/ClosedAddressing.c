#include <stdio.h>
#include <stdlib.h>


struct KeyPair{
      char* key;
      int value;
};

struct HashMap{
     struct KeyPair elements[100];
} HashMap;

int linearProbe();
int quadraticProbe();
void bucketHashing();
int pseudoRandomProbe();
int doubleHashing();

void main(int argc,char* argv[]){
}
