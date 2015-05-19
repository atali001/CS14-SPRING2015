#include <vector>
#include <iostream>
#include <cstdlib>
#include <string>
#include <list>

#include "lab6.h"

template<typename L>
void display(L &l){
   typename L::iterator front = l.begin();
   typename L::iterator back = l.end();
   if(front==back){return;}
   while(front!=back){
      cout << *front << " ";
      front++;
   }
   cout << endl;
}

void display(list<pair<int,int>> l){
   list<pair<int,int>>::iterator front = l.begin();
   list<pair<int,int>>::iterator back = l.end();
   while(front!=back){
      cout << "(" << (*front).first << "," << (*front).second << ") ";
      front++;
   }
   cout << endl;
}


int main(){
   vector<char> diana;
   diana.push_back('b');
   diana.push_back('f');
   diana.push_back('k');
   diana.push_back('l');
   diana.push_back('h');
   diana.push_back('a');
   
   cout << "pre: "; display(diana);
   selectionsort(diana);
   cout << "post: "; display(diana);
   cout <<  "0 copies and " << moves << " moves" << endl << endl;
   
   
   vector<int> test2;
   test2.push_back(2);
   test2.push_back(4);
   test2.push_back(5);
   test2.push_back(1);
   test2.push_back(8);
   test2.push_back(9);
   
   cout << "pre: "; display(test2);
   selectionsort(test2);
   cout << "post: "; display(test2);
   cout <<  "0 copies and " << moves << " moves" << endl << endl;
   
   
   vector<int> test3;
   
   cout << "pre: " << endl; display(test3);
   selectionsort(test3);
   cout << "post: "<< endl; display(test3);
   cout <<  "0 copies and " << moves << " moves" << endl << endl;
   
   list<pair<int,int>> test4;
   test4.push_back(pair<int, int> (1,2));
   test4.push_back(pair<int, int> (3,-1));
   test4.push_back(pair<int, int> (-1,3));
   test4.push_back(pair<int, int> (0,0));
   test4.push_back(pair<int, int> (2,3));
   test4.push_back(pair<int, int> (1,2));
   test4.push_back(pair<int, int> (1,-2));
   test4.push_back(pair<int, int> (8,10));
   
   cout << "pre: "; display(test4);
   selectionsort(test4);
   cout << "post: "; display(test4);
   cout <<  "0 copies and " << moves << " moves" << endl << endl;
   
   list<pair<int,int>> test5;
   test5.push_back(pair<int, int> (10,2));
   test5.push_back(pair<int, int> (-3,-1));
   test5.push_back(pair<int, int> (-8,0));
   test5.push_back(pair<int, int> (1,1));
   test5.push_back(pair<int, int> (1,1));
   test5.push_back(pair<int, int> (0,0));
   test5.push_back(pair<int, int> (10,2));
   test5.push_back(pair<int, int> (5,5));
   test5.push_back(pair<int, int> (5,-5));
   test5.push_back(pair<int, int> (0,0));
   test5.push_back(pair<int, int> (10,2));
   
   cout << "pre: "; display(test5);
   selectionsort(test5);
   cout << "post: "; display(test5);
   cout <<  "0 copies and " << moves << " moves" << endl << endl;
   
   list<pair<int,int>> test6;
   test6.push_back(pair<int, int> (-1,3));
   test6.push_back(pair<int, int> (0,0));
   test6.push_back(pair<int, int> (1,-2));
   test6.push_back(pair<int, int> (1,2));
   test6.push_back(pair<int, int> (1,2));
   test6.push_back(pair<int, int> (2,3));
   test6.push_back(pair<int, int> (3,-1));
   test6.push_back(pair<int, int> (8,10));
   
   cout << "pre: "; display(test6);
   selectionsort(test6);
   cout << "post: "; display(test6);
   cout <<  "0 copies and " << moves << " moves" << endl << endl;
   
}