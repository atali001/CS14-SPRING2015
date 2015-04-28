#include "lab3.h"

template<class T>
TwoStackFixed<T>::TwoStackFixed(int size, int maxtop)
{
   array = new T[size];
   max=maxtop;
   cap=size;
   top1=-1;
   top2=size;
}

template<class T>
void TwoStackFixed<T>::pushStack1(T value)
{
   if(isFullStack1())
   {
      cout << "Error: cannot push onto stack, b/c it is full\n";
      return;
   }
   
   array[top1+1] = value;
   top1++;
   this->display();
}

template<class T>
void TwoStackFixed<T>::pushStack2(T value)
{
   if(isFullStack2())
   {
      cout << "Error: cannot push onto stack, b/c it is full\n";
      return;
   }
   
   array[top2-1] = value;
   top2--;
   this->display();
}

template<class T>
T TwoStackFixed<T>::popStack1()
{
   if(this->isEmptyStack1())
   {
      cout << "Error: cannot pop stack, b/c it is already empty\n";
   }
   else
   {
      top1 = top1 -1;
      return array[top1+1];
   }
   
}

template<class T>
T TwoStackFixed<T>::popStack2()
{
   if(this->isEmptyStack2())
   {
      cout << "Error: cannot pop stack, b/c it is already empty\n";
   }
   else
   {
      top2 = top2 +1;
      return array[top2-1];
   }
   
}

template<class T>
bool TwoStackFixed<T>::isFullStack1()
{
   return (top1==max);
}

template<class T>
bool TwoStackFixed<T>::isFullStack2()
{
   return (top2==max+1);
}

template<class T>
bool TwoStackFixed<T>::isEmptyStack1()
{
   return (top1==-1);
}

template<class T>
bool TwoStackFixed<T>::isEmptyStack2()
{
   return (top2==cap);
}

template<class T>
void TwoStackFixed<T>::display()
{
   for(int i=0; i<cap; i++)
   {
      if(top1>=i || top2<=i)
      {
         cout << array[i];
      }
      else
      {
         cout << ' ';
      }
   }
   cout << endl;
}


//START OF EXERCISE 2

template<class T>
TwoStackOptimal<T>::TwoStackOptimal(int size)
{
   array = new T[size];
   max=size/2;
   cap=size;
   top1=-1;
   top2=size;
}

template<class T>
void TwoStackOptimal<T>::pushFlexStack1(T value)
{
   if(isFullStack1())
   {
      cout << "Error: cannot push onto stack, b/c it is full\n";
      return;
   }
   
   array[top1+1] = value;
   top1++;
   this->display();
}

template<class T>
void TwoStackOptimal<T>::pushFlexStack2(T value)
{
   if(isFullStack2())
   {
      cout << "Error: cannot push onto stack, b/c it is full\n";
      return;
   }
   
   array[top2-1] = value;
   top2--;
   this->display();
}

template<class T>
T TwoStackOptimal<T>::popFlexStack1()
{
   if(this->isEmptyStack1())
   {
      cout << "Error: cannot pop stack, b/c it is already empty\n";
   }
   else
   {
      top1 = top1 -1;
      return array[top1+1];
   }
   
}

template<class T>
T TwoStackOptimal<T>::popFlexStack2()
{
   if(this->isEmptyStack2())
   {
      cout << "Error: cannot pop stack, b/c it is already empty\n";
   }
   else
   {
      top2 = top2 +1;
      return array[top2-1];
   }
   
}

template<class T>
bool TwoStackOptimal<T>::isFullStack1()
{
   if(top1!=max){return false;}
   else if(max!=top2-1){max++; return false;}
   else{return true;}
}

template<class T>
bool TwoStackOptimal<T>::isFullStack2()
{
   if(top2!=max+1){return false;}
   else if(max!=top1){max--; return false;}
   else{return true;}
}

template<class T>
bool TwoStackOptimal<T>::isEmptyStack1()
{
   return (top1==-1);
}

template<class T>
bool TwoStackOptimal<T>::isEmptyStack2()
{
   return (top2==cap);
}

template<class T>
void TwoStackOptimal<T>::display()
{
   for(int i=0; i<cap; i++)
   {
      if(top1>=i || top2<=i)
      {
         cout << array[i];
      }
      else
      {
         cout << ' ';
      }
   }
   cout << endl;
}

template <typename T>
void showTowerStates(int n, stack<T>& A, stack<T>& B, stack<T>& C)
{
   if(first) //if first call store locations of stacks
   {
      Aloc = &A;
      Bloc = &B;
      Cloc = &C;
      
      first = false;
   }
   
   if(n == 1)
   {
      C.push(A.top());
      A.pop();
      cout << "moved " << C.top() << " from peg ";
      if(&A==Aloc){cout << "A";}
      else if(&A==Bloc){cout << "B";}
      else if(&A==Cloc){cout << "C";}
      cout << " to ";
      if(&C==Aloc){cout << "A";}
      else if(&C==Bloc){cout << "B";}
      else if(&C==Cloc){cout << "C";}
      cout << endl;
   }
   else
	{
	   showTowerStates(n - 1, A, C, B); //move n-1 disks to auxiliary stack

		C.push(A.top());
      A.pop();//Move the remaining disk to the destination peg.
		cout << "moved " << C.top() << "from peg ";
      if(&A==Aloc){cout << "A";}
      else if(&A==Bloc){cout << "B";}
      else if(&A==Cloc){cout << "C";}
      cout << " to ";
      if(&C==Aloc){cout << "A";}
      else if(&C==Bloc){cout << "B";}
      else if(&C==Cloc){cout << "C";}
      cout << endl;

		//Move the disks we just moved to the spare back over to the dest peg.
		showTowerStates(n - 1, B, A, C);
	}
}



   
int main()
{
   //TwoStackFixed<int> test(10, 6); // for exercise 1 test
   //TwoStackOptimal<int> test(10);    // for exercise 2 test
   /* //for exercise 1 and 2
   int num;
   char choice2;
   while(choice2!='q')
   {
      cout << "choose member function to test (first letter of f(x) or q to exit): ";
      cin >>  choice2;
      
      if (choice2=='p')
      {
         cout << "value? ";
         cin >> num;
         test.pushFlexStack1(num);
      }
      else if (choice2=='P')
      {
         cout << "value? ";
         cin >> num;
         test.pushFlexStack2(num);
      }
      else if (choice2=='x')
      {
         cout << "deleting: " << test.popFlexStack1() << endl;
         test.display();
      }
      else if (choice2=='X')
      {
         cout << "deleting: " << test.popFlexStack2() << endl;
         test.display();
      }
   }
   */
   
   //for ex 3 test
   stack<int> A, B, C;
   A.push(4);
   A.push(3);
   A.push(2);
   A.push(1);
   
   showTowerStates(4, A, B, C);
   
}