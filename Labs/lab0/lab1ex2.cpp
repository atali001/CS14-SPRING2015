#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

int main()
{
   
   int a, b;
   
   cout<< "Enter values for a and b\na=";
   cin >> a;
   cout<< "b=";
   cin >> b;
   
   cout<< "swiching...\n";
   
   a=a-b;
   b=b+a;
   a=b-a;
   
   cout<< "a=" << a << " and b=" << b;
}
