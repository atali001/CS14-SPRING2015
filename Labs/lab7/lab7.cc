///////////////////////////////
//       LAB 7
//
//Name: Alex Taliaferro
//SID: 861023533
//Date: 5/25
//TA: Mandar
//////////////////////////////
#include <vector>
#include <cstdlib>
#include <chrono>
#include <set>
#include <unordered_set>
#include <iostream>
#include <fstream>

using namespace std;

int main( int argc, char* argv[] ) {
   if ( argc != 2 ) {
      cout << "Usage: lab7.h <dictionary_file>\n";
      exit(-1);
   }
   
   string listFile = argv[1];   //get dict file name
   
//import dictionary into dic vector
   vector<string> dic;
   ifstream infs;
   
   infs.open(listFile.c_str());
   if (!infs.is_open()) {
      cout << "Could not open input file" << endl;
   }
   ofstream outfs ("data.txt");
   if (!outfs.is_open()){
      cout << "Could not open output file" << endl;
   }

   
   string line;
   while(infs>>line)
   {
      dic.push_back(line);
   }
   //cout << dic.size() << " " << dic.front() << " " << dic.back() << endl;//dict test


   
   srand(0);

   unordered_set<string> hash;
   set<string> tree;
   vector<double> hash_times(11,0), tree_times(11,0), hash_search_times(11,0), tree_search_times(11,0);
   
   for(int k=0; k<10; k++){
      //randomize dic vector    
      for(unsigned i=0; i<dic.size(); i++){    
         swap(dic.at(i), dic.at(rand()%(dic.size()-1)));
      }
      
      for(int j=5000; j<=50000; j+=5000){
          
         auto hash_start = chrono::steady_clock::now();
            for(int i=0; i<j; i++){
               hash.insert(dic.at(i));
            }   
         auto hash_end = chrono::steady_clock::now();
         
         hash_times.at(j/5000) += chrono::duration_cast<std::chrono::nanoseconds>(hash_end-hash_start).count()/j;
         
         auto tree_start = chrono::steady_clock::now();
            for(int i=0; i<j; i++){
               tree.insert(dic.at(i));
            }   
         auto tree_end = chrono::steady_clock::now();
         tree_times.at(j/5000) += chrono::duration_cast<std::chrono::nanoseconds>(tree_end-tree_start).count()/j;
         
         auto hash_search_start = chrono::steady_clock::now();
            for(int i=0; i<j; i++){
               tree.find(dic.at(i));
            }
         auto hash_search_end = chrono::steady_clock::now();
         hash_search_times.at(j/5000) += chrono::duration_cast<std::chrono::nanoseconds>(hash_search_end-hash_search_start).count()/j;
         
         auto tree_search_start = chrono::steady_clock::now();
            for(int i=0; i<j; i++){
               hash.find(dic.at(i));
            }
         auto tree_search_end = chrono::steady_clock::now();
         tree_search_times.at(j/5000) += chrono::duration_cast<std::chrono::nanoseconds>(tree_search_end-tree_search_start).count()/j;
         
          tree.clear();
          hash.clear();
      }

   }
   for(int i=1; i<=10; i++){
      outfs << i*5000 << " " << tree_times.at(i)/10 << " " << hash_times.at(i)/10; 
      outfs <<  " " <<  tree_search_times.at(i)/10 <<  " " << hash_search_times.at(i)/10 << endl;
   }    
}