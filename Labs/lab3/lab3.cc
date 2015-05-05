
#include <forward_list>
#include "lab3.h"
#include <iostream>


using namespace std;


List::List()
{
   head = 0;
   tail = 0;
}

List::~List()
{
   while( head!= 0)
   {
      pop_front();
   }
}

void List::display() const
{
   if (head!=0)
   {
      Node* point;
      point = head;
   
      while(point!=tail)
      {
         cout << point->data  << " ";
         point=point->next;
      }
   
      cout << point->data;   
   }
   
}

void List::push_front( int value)
{
   Node* temp;
   temp = head;
   head = new Node(value);
   head->next=temp;
   
   if(tail==0)
   {
      tail=head;
   }
}

void List::pop_front()
{
   if (head==tail)
   {
      delete head;
      head=0;
      tail=0;
   }
   else
   {
      Node* temp;
      temp = head->next;
      delete head;
      head = temp;
   }
}                                            /// end of list functions


int primeCount(forward_list<int> lst)        ///exercise 1
{
   if(lst.empty())                           //basecase
   {
         return 0;
   }
   else
   {
      int prime = isPrime(*lst.begin());   //chck if front num is prime then pop
      lst.pop_front();
      
      int subtotal= prime + primeCount(lst);      //recursive case
      return subtotal;
   }
}

bool isPrime(int x)                           ///ex 1 helper fx
{
   for (int i=2; i<x; i++)
	{
		if (x % i == 0)
		{
			return false;
		}
	}
	
	return true;	
}

template <typename Type>

void listCopy (forward_list<Type> L, forward_list <Type>& P)  //ex 3
{
   P.reverse();              
   P.splice_after(P.before_begin(), L);
   P.reverse();
}

void List::elementSwap(int pos )                          //ex 4
{
   Node* point = head;
  
  if (pos == 0)
  {
     point= head->next;
     head->next=head->next->next;
     point->next=head;
     head = point;
  }
   
   for (int i=1; i<pos; i++)
   {
      point = point->next; 
   }
   
   Node* point1 = point->next;
   
   point->next = point1->next;
   point = point1->next->next;
   point1->next->next = point1;
   point1->next=point;
}

template <typename Type>
void printLots (forward_list <Type> L, forward_list <int> P)
{                                                                     //ex2
   int i=0;
   
   while (!P.empty())
   {
      if(i==P.front())
      {
         cout << L.front() << " ";
         P.pop_front();
      }
      
      L.pop_front();
      i++;
      
   }
   cout << endl;
}

int main()
{
   
   forward_list<int> L (3,40);
   L.push_front(30);
   L.push_front(20);
   L.push_front(10);
   L.push_front(9);
   L.push_front(8);
   forward_list<int> P (1,7);
   P.push_front(4);
   P.push_front(3);
   P.push_front(1);
   
   List T;
   T.push_front(7);
   T.push_front(6);
   T.push_front(5);
   T.push_front(4);
   T.push_front(3);
   T.push_front(2);
   
   T.elementSwap(3);
   T.display();
   //listCopy (L,P);
   //printLots(L,P);
   /*while(!P.empty())
   {
      cout << P.front() << " ";
      P.pop_front();
   }
   cout << "test1" << endl;
   return 0; */
}
