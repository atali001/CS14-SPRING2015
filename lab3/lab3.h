#ifndef LAB3_H
#define LAB3_H

#include <forward_list>

using namespace std;
struct Node                            // Node struct fot "List"
{
   int data;
   Node *next;
   
   Node(int data): data(data), next(0) {} //node constructor
};

class List                          // List class for exercise 2
{
   private:
   Node* head;
   Node* tail;
   
   public:
   List();
   ~List();
   void display() const;
   void push_front(int);
   void pop_front();  
   
   void elementSwap(int pos );   // exercise 2 function
};



int primeCount(forward_list<int> lst); //exercise 1
bool isPrime(int);

template <typename Type>
void listCopy (forward_list<Type> L, forward_list <Type>& P); //exercise 3

template <typename Type>
void printLots (forward_list <Type> L, forward_list <int> P); //exercise 4
#endif
