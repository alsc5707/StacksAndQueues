#include <iostream>
#include <cstdlib>
#include <iostream>
#include "Register.hpp"


using namespace std;

Register::Register(){
   top = 0;
}

bool Register::isFull(){
   if(top >= SIZE){
      return true;
   }
   return false;
}

void Register::push(int money){
   if(isFull()){
      cout << "Stack overflow: \n";
      return;
   }
   top +=1;
   a[top] = money;
}


bool Register::isEmpty(){
   if(top == 0){
      return true;
   }
   return false;
}

void Register::disp(){
   if(!isEmpty())
   {
      cout << "top = " << a[top] << endl;
      for(int i = top; i >= 0; i--)
      {
         cout << a[i] << endl;
      }
   }
}

int Register::pop(){
   if(isEmpty()){
      cout << "Stack empty, cannot pop an item!\n";
      return -1;
   }
   int temp = a[top];
   top -= 1;
   return temp;
}