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

int linearProbe(int);//0
int linearStepProbe(int);//1
int quadraticProbe(int);//2
int bucketHashing(int);//3
int pseudoRandomProbe(int);//4
int doubleHashing(int);//5
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
    if(HashMap.elements[hashed]==NULL){
      HashMap.elements[hashed] = keyPair;
      printf("Inserted %i without probing\n",value);
      return;
    }
    while(HashMap.elements[hashed]!=NULL){
      switch(probe){
       case 0:
         hashed = linearProbe(hashed);
         break;
       case 1:
         hashed = linearStepProbe(hashed);
         break;
       case 2:
         hashed = quadraticProbe(hashed);
         break;
       case 3:
         hashed = bucketHashing(hashed);
         break;
       case 4:
         hashed = doubleHashing(hashed);
         break;
       case 5:
         hashed = pseudoRandomProbe(hashed);
         break;
     }
    }
    HashMap.elements[hashed] = keyPair;
    printf("Inserted %i with probing\n",value);
}

int get(char* key){
}


int linearProbe(int hashed){
}

int linearStepProbe(int hashed){
}

int quadraticProbe(int hashed){
}

int bucketHashing(int hashed){
}

int pseudoRandomProbe(int hashed){
}

int doubleHashing(int hashed){
}
