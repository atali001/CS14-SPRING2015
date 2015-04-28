#include <iostream>
#include <stack>


using namespace std;

template <typename T>
class TwoStackFixed
{
   private:
   T* array;
   int max;
   int cap;
   int top1, top2;
   
   public:
   TwoStackFixed(int size, int maxtop);
   void pushStack1(T value);
   void pushStack2(T value);
   T popStack1();
   T popStack2();
   bool isFullStack1();
   bool isEmptyStack1();
   bool isFullStack2();
   bool isEmptyStack2();
   void display();
   
};

template <typename T>
class TwoStackOptimal
{
   
   
   private:
   T* array;
   int max;
   int cap;
   int top1, top2;
   
   public:
   TwoStackOptimal(int size); //constructor that constructs array of size and constructs empty
   void pushFlexStack1(T value); //to push element into first stack.
   void pushFlexStack2(T value); //to push element into second stack
   T popFlexStack1(); //to pop element into first stack. 
   T popFlexStack2(); //to pop element from second stack.
   bool isFullStack1(); //helper function to check whether first stack is full.
   bool isFullStack2(); //helper function to check whether second stack is full.
   bool isEmptyStack1(); //helper function to check whether 1st stack is empty.
   bool isEmptyStack2(); //helper function to check whether 2nd stack is empty.
   void display(); //to display contents of array.
   
};

template <typename T>
void showTowerStates(int n, stack<T>& A, stack<T>& B, stack<T>& C);

stack<int> *Aloc, *Bloc, *Cloc;
bool first=true;