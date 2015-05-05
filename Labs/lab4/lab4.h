///////////////////////////////
//Name: Alex Taliaferro
//SID: 861023533
//Date: 4/29
//TA: Mandar
//////////////////////////////


#include <iostream>
#include <cmath>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int,int> Entry;
class priority_queue {
   public:
   vector<Entry> entries;
   Entry& front() { return entries.back(); }
   void pop() { entries.pop_back(); }
   void push( Entry e ) {
      entries.push_back( e );
      for ( int i = entries.size()-1; i != 0; --i ) {
         if ( entries[i].first+entries[i].second <= 
            entries[i-1].first+entries[i-1].second ) break;//new comparison code
         swap(entries[i], entries[i-1]);
      }
   }
};

void coprimePreorder(int k);
void coprimePreorder(int m, int n, int k);
void coprimePostorder(int k);
void coprimePostorder(int m, int n, int k);
void coprimeInorder(int k);
void coprimeInorder(int m, int n, int k, priority_queue& Q);

///////Pre-order
void coprimePreorder(int k) {
  cout << "pre-order" << endl; // k = max sum of pairs (argv[1])
  coprimePreorder(2, 1, k);
  coprimePreorder(3, 1, k);
}

// Recursive function
void coprimePreorder(int m, int n, int k) {
   if(m+n>=k){return;}
   cout << m << " " << n << endl; //cout parent
   coprimePreorder(2*m-n, m, k); //cout left children
   coprimePreorder(2*m+n, m, k);//cout middle children
   coprimePreorder(m + 2*n, n, k);//cout right children
}


//////Post-Order 
void coprimePostorder(int k) {
  cout << "post-order" << endl; // k = max sum of pairs (argv[1])
  coprimePostorder(2, 1, k);
  coprimePostorder(3, 1, k);
}

// Recursive function
void coprimePostorder(int m, int n, int k) {
   if(m+n>=k){return;}
   coprimePostorder(2*m-n, m, k);//cout left children
   coprimePostorder(2*m+n, m, k);//cout middle children
   coprimePostorder(m+2*n, n, k);//cout right children
   cout << m << " " << n << endl; //cout parent
   
}


//////In-order
void coprimeInorder(int k){
   cout << "sorted" << endl; // k = max sum of pairs (argv[1])
   priority_queue sorted;
   coprimeInorder(2, 1, k, sorted);
   coprimeInorder(3, 1, k, sorted);
   
   while(!sorted.entries.empty()){
      cout << sorted.front().first << " ";
      cout << sorted.front().second << endl;
      sorted.pop();
   }
}

void coprimeInorder(int m, int n, int k, priority_queue& Q){
   if(m+n>=k){return;}
   Entry e(m,n);                         //make Entry type from m and n
   Q.push(e);                            //push entry parent ont Q
   coprimeInorder(2*m - n, m, k, Q);     //check left children
   coprimeInorder(2*m + n, m, k, Q);     //check middle children
   coprimeInorder(m + 2*n, n, k, Q);     //check right children
}

