//  =============== BEGIN ASSESSMENT HEADER ================
/// @brief Lab <#2>
///
/// @author <Alex Taliaferro> [atali001@ucr.edu]
/// @SID: 861023533 
///     
///Lab Section: <22>
///
///Date: 4/7/15
///TA: Mandar
///
/// @par Plagiarism Section
/// I hereby certify that the code in this file
/// is ENTIRELY my own original work.
//  ================== END ASSESSMENT HEADER ===============
#include "Lab1List.h"
#include <iostream>

using namespace std;

template<typename T>
Lab1List<T>::Lab1List()
{
   head = 0;
   tail = 0;
}

template<typename T>
Lab1List<T>::Lab1List(const string& str)
{
   head = 0;
   Node<T>* NodeLinker;
   
   for(int i=0; i<str.size(); i++)
   {
   
      if(head==0)
      {
         head= new Node<T>(str.at(i));
         NodeLinker = head;
      }
      else
      {
         NodeLinker->next = new Node<T>(str.at(i));
         NodeLinker = NodeLinker->next;
      }
   }
   tail = NodeLinker;
}

template<typename T>
void Lab1List<T>::display() const
{
   if (head!=0)
   {
      Node<T>* point;
      point = head;
   
      while(point!=tail)
      {
         cout << point->data  << " ";
         point=point->next;
      }
   
      cout << point->data;   
   }
}

template<typename T>
void Lab1List<T>::push(char c)
{
   tail->next = new Node<char>(c);
   tail=tail->next;
}

template<typename T>
void Lab1List<T>::rotate(int k)
{
   Node<T>* point = head;
   for(int i=0; i<k; i++)
   {
      head=head->next;
   }
   
   tail->next= point;
   
   for(int i=0; i<k; i++)
   {
      tail=tail->next;
   }
}

Lab1List& Lab1List<char>::operator+(Lab1List<char>& head2)
{
   int size=1;
   Node* point=head;
   
   while (point!=tail)
   {
      size++;
      point=point->next;
   }
   
   head2.rotate(size);
   
   for (int i=0; i<size; i++)
   {
      this->head.data= this->head.data + head2->head.data;
   }
   
   return this*;
}


int main()
{
   string test ="3515204060";
   Lab1List<char> x(test);
   x.display();
   
   x.push('9');
   x.push('6');
   cout << endl;
   x.display();
   cout << endl;
   
   x.rotate(4);
   x.display();
   cout << endl;
}