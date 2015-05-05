#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

int main()
{
int num;
cout << "Enter a number:";
cin >> num;

int sum=0;
while(num>0)
{
   int temp=num%10;
   sum+=temp;
   num= num-temp;
   num= num/10;
}

cout << "The sum of its digis are: " << sum << endl;

}
