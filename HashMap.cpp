
#include <iostream>
using namespace std;
#include <cstring>
struct data{
  char* key;
  int value;
  data* next = nullptr;
  int isset = 0;
};

class HashTable{
 public:
   struct data hashtable[2];
   int hash(char* key);
   void put(char* key,int value);
   int get(char* key);
};


int HashTable::hash(char* key){
  int hash = 0;
  for(int i=0;i<strlen(key);i++){
    hash = (hash + (int)key[i] + i) % (sizeof(hashtable)/sizeof(hashtable[0]));
  }
  return hash;
}


void HashTable::put(char* key,int value){
   int index = hash(key);
   data* ob = new data;
   ob->key = key;
   ob->value = value;
   ob->isset = 1;
   if(hashtable[index].isset==1){
       data* node = &hashtable[index];
       while(node->next!=nullptr){
           node = node->next;
       }
       node->next = ob;
   }else{
      hashtable[index] = *ob;
    }
}

int HashTable::get(char* key){
  int index = hash(key);
  if(hashtable[index].isset==1){
      data* node = &hashtable[index];
      while(node!=nullptr){
           if(node->key==key){
             return node->value;
           }
           node = node->next;
        }
  }
    cout << "Not found" << endl;
    return 0;
}


int main(){
 char c1[] = "onee";
 HashTable ob;
 ob.put(c1,1);
 char c2[] = "two";
 ob.put(c2,2);
 char c3[] = "three";
 ob.put(c3,3);
 char c4[] = "four";
 ob.put(c4,4);
 char c5[] = "five";
 ob.put(c5,5);
 char c6[] = "six";
 ob.put(c6,6);
 cout << ob.get(c2) << endl;
 cout << ob.get(c6) << endl;
 return 0;
}
