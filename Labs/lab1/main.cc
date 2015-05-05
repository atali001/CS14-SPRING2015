#include "Lab1List.h"
#include <string>

using namespace std;

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