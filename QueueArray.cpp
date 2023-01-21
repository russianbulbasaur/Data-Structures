
#include <iostream>
using namespace std;
class Queue{
   public:int arr[5];
   private:int nexttofill = 5-1;
   private:int nexttopick = 5-1;
   public:void enqueue(int value){
        if(nexttofill==-1){
          cout << "Queue is full" << endl;
          return;
        }
        arr[nexttofill--] = value;
        cout << "Added " << value << endl;
   }
   public:void dequeue(){
       if(nexttopick==nexttofill){
          cout << "Queue empty" << endl;
          return;
       }
       cout << arr[nexttopick--] << endl;
   }
};
int main(){
Queue queue;
queue.enqueue(55);
queue.enqueue(76);
queue.enqueue(88);
queue.enqueue(99);
queue.enqueue(100);
queue.enqueue(800);
queue.dequeue();
queue.dequeue();
queue.dequeue();
queue.dequeue();
queue.dequeue();
queue.dequeue();
return 0;
}
