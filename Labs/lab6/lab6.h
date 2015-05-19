///////////////////////////////
//       LAB 6
//
//Name: Alex Taliaferro
//SID: 861023533
//Date: 5/15
//TA: Mandar
//////////////////////////////

#include <utility>
using namespace std;

int moves=0;
template<typename L>
void selectionsort(L &l){
   moves = 0;
   if(l.begin()==l.end()){return;}
   typename L::iterator front = l.begin();
   typename L::iterator back = l.end();
   while(front!=back){
     typename L::iterator i= front;
     typename L::iterator min= i;
     bool newMin=false;
     while(i!=back){
        if(*i<*min){min=i; newMin=true;}
        i++;
     }
     if(newMin){
         swap(*front, *min);
         moves++;
     }
     front++;
   }
   
}