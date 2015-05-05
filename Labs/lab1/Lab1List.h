#ifndef LIST_H
#define LIST_H

#include "Node.h"
#include <string>
#include <iostream>

using namespace std;

template<typename T>

class Lab1List
{
   private:
   Node<T>* head;
   Node<T>* tail;
   
   public:
   Lab1List();
   Lab1List(const string& str);
   //~IntList();
   void display() const;
   void push(char);
   void rotate(int k);
   //Lab1List& operator+( Lab1List& head2);
   //void pop_front();   
};

#endif
