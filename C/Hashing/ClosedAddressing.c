#include <stdio.h>
#include <stdlib.h>


struct KeyPair{
      char* key;
      int value;
};

struct HashMap{
     struct KeyPair* elements[100];
     int max;
} HashMap;

int linearProbe();//0
int linearStepProbe();//1
int quadraticProbe();//2
void bucketHashing();//3
int pseudoRandomProbe();//4
int doubleHashing();//5
void put(char* key,int value);
int get(char* key);
int hash(char* key);
int probe = -1;

void main(int argc,char* argv[]){
    if(argc<2){
      printf("Enter probing type please.\n");
      return;
    }
    sscanf(argv[1],"%i",&probe);
    printf("%i",probe);
    HashMap.max = 100;
}

int hash(char* key){
    int total = 0;
    while(*key!='\0'){
        total += *key;
    }
    return (total%HashMap.max);
}


void put(char* key,int value){
    struct KeyPair* keyPair = (struct KeyPair*)malloc(sizeof(struct KeyPair));
    keyPair->value = value;
    keyPair->key = key;
    int hashed = hash(key);
    switch(probe){
      case 0:
        break;
      case 1:
        break;
      case 2:
        break;
      case 3:
        break;
      case 4:
        break;
      case 5:
        break;
    }
}

int get(char* key){
}
