#include "PancakeHouse.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;
int const PancakeHouse::pancake_types[] = {1, 2, 5, 3, 7};

PancakeHouse::PancakeHouse() {
    profit = 0;
    pancakesCooked = 0;
    cashRegister = new Register;
    shopQueue = new ShopQueue;
}

PancakeHouse::~PancakeHouse(){
    shopQueue -> ~ShopQueue();
    while(!cashRegister->isEmpty()){
        cashRegister -> pop();
    }
}

Register* PancakeHouse::getStack(){
    return cashRegister;
}

ShopQueue* PancakeHouse::getQueue() {
    return shopQueue;
}

int PancakeHouse::getProfit(){
    return profit;
}

void PancakeHouse::addOrder(string name, int number_of_pancakes, int type_of_pancakes) {
    if(shopQueue->queueSize() >= 20 || type_of_pancakes > 5|| type_of_pancakes < 1){
        return;
    }
    shopQueue -> enqueue(name, number_of_pancakes, type_of_pancakes);
}

void PancakeHouse::cookPancakes() {
    CustomerOrder *temp = shopQueue->peek();
    if(temp == nullptr){
        return;
    }
    pancakesCooked += temp->number_of_pancakes;
    int cost = (temp->number_of_pancakes) * (pancake_types[temp->type_of_pancakes - 1]);
    shopQueue->dequeue();
    cashRegister->push(cost);
}

void PancakeHouse::strikeOrder(){
    shopQueue->dequeue();
}

void PancakeHouse::refundOrder(){
    if(cashRegister->isEmpty()){
        cashRegister->pop();
        cout << "No money in the cash register!\n";
        return;
    }
    int amount = cashRegister->pop();
    cout << "Money refunded = " << amount << endl;
}

void PancakeHouse::closeShop(){
    if(!shopQueue->isEmpty()){
      shopQueue->~ShopQueue();  
    }
    while(!cashRegister->isEmpty()){
        cashRegister->pop();
    }
}

void PancakeHouse::updateTotalProfit(){
    while(!cashRegister->isEmpty()){
        int surplus = cashRegister->pop();
        profit += surplus;
    }
}

void PancakeHouse::printOrders(){
    CustomerOrder* print = shopQueue->peek();
    while(print != nullptr){
        cout << "Customer name: " << print->name << endl;
        cout << "Number of pancakes ordered: " << print->number_of_pancakes << endl;
        cout << "Type of pancakes: " << print->type_of_pancakes << endl;
        print = print->next;
    }
}