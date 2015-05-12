#include "lab5.h"

int main(){
   BST<int> test;
   
      int buffer[5];
   cout << "test 1: " << endl;
   test.postorder();//used to test call on empty BST
   test.insert(4);
   test.insert(13);
   test.insert(5);
   test.insert(6);
   test.insert(1);
   test.insert(45);
   test.insert(23);
   test.insert(100);
   test.insert(7);
   test.insert(10);
   test.insert(2);
   test.insert(3);
   test.insert(0);
 
   test.minCover();
   test.findSumPath(test.getRoot(),45,buffer);
   
   map<int, int> testmap;
   test.vertSum(test.getRoot(), 0, testmap );
   
   
   BST<int> test2;
   cout << endl << "test 2: " << endl;
   
   test2.insert(50);
   test2.insert(20);
   test2.insert(60);
   test2.insert(10);
   test2.insert(40);
   test2.insert(70);
   test2.insert(35);
   test2.insert(45);
   
   test2.minCover();
   test2.findSumPath(test2.getRoot(),80,buffer);
   
   map<int, int> test2map;
   test2.vertSum(test2.getRoot(), 0, test2map );
   
   return 0;
}