#include <iostream>
using namespace std;
struct Node{
   char value;
   Node* next = nullptr;
   Node* previous = nullptr;
};


class DoublyLinkedList{
   public: Node* head = nullptr;
   public: Node* tail = nullptr;
   public:
      void append(char value);
      void search(char value);
      void del(int index);
      void insert(char value,int index);
      void printList();
      void reverse();
};

void DoublyLinkedList::append(char value){
     Node* newNode = new Node;
     newNode->value = value;
     if(tail==nullptr){
        head = newNode;
        tail = newNode;
        return;
     }
     tail->next = newNode;
     newNode->previous = tail;
     tail = newNode;
     cout << newNode->previous->value << endl;
};

void DoublyLinkedList::search(char value){
     Node* node = head;
     int index = 0;
     while(node!=nullptr){
         if(node->value==value){
           cout << "Value found at " << index << endl;
           return;
         }
         node = node->next;
         index++;
     }
};


void DoublyLinkedList::del(int at){
    int index = 0;
    Node* node = head;
    Node* prev = nullptr;
    while(node!=nullptr){
       if(index==at){
          if(node->next==nullptr){
              tail = prev;
              tail->next = nullptr;
              return;
          }
          if(prev!=nullptr){
             prev->next = node->next;
             return;
          }
          head = node->next;
          return;
       }
       prev = node;
       node = node->next;
       index++;
    }
};


void DoublyLinkedList::insert(char value,int at){
     int index = 0;
     Node* node = head;
     Node* newNode = new Node;
     Node* nodesnext =  nullptr;
     newNode->value = value;
     while(node!=nullptr){
         if((index+1)==at){
           nodesnext = node->next;
           node->next = newNode;
           newNode->previous = node;
           newNode->next = nodesnext;
           nodesnext->previous = newNode;
           return;
         }
         index++;
         node = node->next;
     }
};


void DoublyLinkedList::printList(){
   Node* currentNode = head;
   while(currentNode!=nullptr){
      cout << currentNode->value << " -> ";
      currentNode = currentNode->next;
   }
   cout << endl;
}


void DoublyLinkedList::reverse(){
    Node* prev = nullptr;
    Node* current = head;
    Node* next = current->next;
    Node* tempnext = nullptr;
    head = tail;
    tail = current;
    while(next!=nullptr){
        tempnext = next->next;
        next->next = current;
        current->next = prev;
        prev = current;
        current = next;
        next = tempnext;
    }
}


int main(){
char c[] = "ankit";
DoublyLinkedList ob;
ob.append(c[0]);
ob.append(c[1]);
ob.append(c[2]);
ob.append(c[3]);
ob.append(c[4]);
return 0;
}
