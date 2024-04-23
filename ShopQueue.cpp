#include "ShopQueue.hpp"
#include <iostream>

using namespace std;

ShopQueue::ShopQueue() {
   queueEnd = nullptr;
   queueFront = nullptr;
}

ShopQueue::~ShopQueue() {
   while(queueFront != nullptr){
         CustomerOrder* temp = queueFront;
         queueFront = queueFront -> next;
         delete temp;
   }
   queueEnd = nullptr;
}

bool ShopQueue::isEmpty() {
   if(queueFront == nullptr && queueEnd == nullptr){
      return true;
   } else {
      return false;
   }
}

CustomerOrder* ShopQueue::peek() {
   if(isEmpty()){
      cout << "Queue empty, cannot peek!\n";
   }
   return queueFront;
}

void ShopQueue::enqueue(string name, int num_pancakes, int type_of_pancake) {
   CustomerOrder* temp = new CustomerOrder{name, num_pancakes, type_of_pancake};
   if(isEmpty()){
      queueEnd = temp;
      queueFront = temp;
   } else {
      queueEnd -> next = temp;
      queueEnd = temp;
   }
}

void ShopQueue::dequeue() {
   if(isEmpty()){
      cout << "Queue empty, cannot dequeue!\n";
      return;
   }
   CustomerOrder* temp = queueFront;
   queueFront = queueFront->next;
   if(queueFront == nullptr){
      queueEnd = nullptr;
   }
   
   delete temp;
}

int ShopQueue::queueSize(){
   int cnt = 0;
   CustomerOrder* temp = queueFront;
   while(temp != nullptr){
      cnt+=1;
      temp = temp -> next;
   }
   return cnt;
}

CustomerOrder* ShopQueue::getQueueEnd(){
   return queueEnd;
}