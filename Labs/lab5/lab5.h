///////////////////////////////
//       LAB 5
//
//Name: Alex Taliaferro
//SID: 861023533
//Date: 4/29
//TA: Mandar
//////////////////////////////

#include <cassert>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <map>
#include <list>
#include <math.h>
using namespace std;
#define nil 0

template < typename Value >
class BST {
   class Node { // binary tree node
      public:
      Node* left;
      Node* right;
      Value value;
      bool selected;
      bool visited;
      
      //Node constructor
      Node( const Value v = Value() )
      : left(nil), right(nil), value(v), selected(false), visited(false)
      {}
      
      //Node functions
      Value& content() { return value; }
      bool isInternal() { return left != nil && right != nil; }
      bool isExternal() { return left != nil || right != nil; }
      bool isLeaf() { return left == nil && right == nil; }
      
      int height() {
         int leftHeight, rightHeight, maxHeight;

         if (isLeaf()){
            return 0;
         }
         
         if(left!=nil){
            leftHeight=1+this->left->height();
         }
         else{leftHeight=0;}
         
         if(right!=nil){
            rightHeight=1+this->right->height();
         }
         else{rightHeight=0;}
         
         if(leftHeight>rightHeight){maxHeight=leftHeight;}
         else{maxHeight=rightHeight;}
         
         return maxHeight;
      }
   
      int size() {
        
            int leftSum, rightSum, size;
   
            if (this->isLeaf()){
               return 1;
            }
            
            if(left!=nil){
               leftSum=this->left->size();
            }
            else{leftSum=0;}
            
            if(right!=nil){
               rightSum=this->right->size();
            }
            else{rightSum=0;}
            
            size=leftSum+rightSum+1;  //size = sum of #left node + # rightnode +1 
            
            return size;
         }
         
      bool childSelected(){        //returns false if one child is not selected
         //cout << "child selected test" << endl;
         if (left==nil & right==nil){return true;}
         if (left!=nil){
            if (left->selected==false){return false;}
         }
         if (right!=nil){
            if (right->selected==false){return false;}
         }
         return true;
         
      }
   }; // Node
   
   
   // const Node* nil; // later nil will point to a sentinel node.
   Node* root;
   int count;
   public:
   int size() {return root->size();}
   int height() {return root->height();}
   bool empty() { return size() == 0; }
   void print_node( const Node* n ) {cout << n->value;}
   
   bool search ( Value x ) {
      Node *point=root;
      while(point!=nil){
         if(point->value==x){return true;}
         else if(point->value<x){point=point->right;}
         else if(point->value>x){point=point->left;}
      }
      return false;
   }
   
   
   //recursive version of display functions
   void preorder(Node *point)const{
      if(point==nil){return;}
      cout << point->value << endl;
      preorder(point->left);
      preorder(point->right);
   }
   void inorder(Node *point)const {
      if(point==nil){return;}
      inorder(point->left);
      cout << point->value << endl;
      inorder(point->right);
   }
   void postorder(Node *point)const {
      if(point==nil){return;}
      postorder(point->left);
      postorder(point->right);
      cout << point->value << endl;
   }

   //non-recursive version of display functions
   void preorder()const {
      if(root==nil){return;}
      cout << root->value << endl;
      preorder(root->left);
      preorder(root->right);
   }
   void postorder()const {
      if(root==nil){return;}
      postorder(root->left);
      postorder(root->right);
      cout << root->value << endl;
   }
   void inorder()const {
      if(root==nil){return;}
      inorder(root->left);
      cout << root->value << endl;
      inorder(root->right);
   }
   
   //helper function creates inorder vector which can be used to look up values
   void braketOpHelper(vector<Value> &V, Node *point){
      if(point==nil){return;}
      braketOpHelper(V, point->left);
      V.push_back(point->value);
      //cout << "pushed back: " << V.back()<<". New size = "<< V.size() << endl;
      braketOpHelper(V, point->right);

   }
   
   Value& operator[] (int n) {
      vector<Value> V;
      braketOpHelper(V, root);
      
      return V.at(n);
   }
   
   BST() : root(nil), count(0) {}
   void insert( Value X ) { root = insert( X, root ); }
   Node* insert( Value X, Node* T ) {
      // The normal binary-tree insertion procedure ...
      if ( T == nil ) {
         T = new Node( X ); // the only place that T gets updated.
      } 
      else if ( X < T->value ) {
         T->left = insert( X, T->left );
      } 
      else if ( X > T->value ) {
         T->right = insert( X, T->right );
      } 
      else {
         T->value = X;
      }
      // later, rebalancing code will be installed here
      return T;
   }
   
   void remove( Value X ) { root = remove( X, root ); }
   Node* remove( Value X, Node*& T ) {
      // The normal binary-tree removal procedure ...
      // Weiss’s code is faster but way more intricate.
      if ( T != nil ) {
      if ( X > T->value ) {
      T->right = remove( X, T->right );
      } else if ( X < T->value ) {
      T->left = remove( X, T->left );
      } else { // X == T->value
      if ( T->right != nil ) {
      Node* x = T->right;
      while ( x->left != nil ) x = x->left;
      T->value = x->value; // successor’s value
      T->right = remove( T->value, T->right );
      } else if ( T->left != nil ) {
      Node* x = T->left;
      while ( x->right != nil ) x = x->right;
      T->value = x->value; // predecessor’s value
      T->left = remove( T->value, T->left );
      } else { // *T is external
      delete T;
      T = nil; // the only updating of T
      }
      }
      }
      // later, rebalancing code will be installed here
      return T;
   }
   
   void minCover(Node* n){
      if(n==nil){return;}
      minCover(n->left);
      minCover(n->right);
      if( n->visited){return;}
      n->visited==true;
      if(n->childSelected()==false){n->selected=true;}
      
   }
   
   void displayMinCover(Node* point, int& i){
      //cout << "display called" << endl; //test only
      if(point==nil){return;}
      displayMinCover(point->left, i);
      if(point->selected){
         cout << point->value << " ";
         i++;
      }
      displayMinCover(point->right, i);
   }
   
   void displayMinCover(){
      cout << "Part 1" << endl;
      if(root==nil){return;}
      int i = 0;
      displayMinCover(root->left, i);
      displayMinCover(root->right, i);
      cout << endl << i << endl;
   }
   
   void minCover(){
      minCover(root);
      displayMinCover();
   }
   
   void findPath(Node *point,int subsum, int sum, vector<Value> v,bool& found){
         ///cout << " test subsum =" <<subsum  << endl; ///testing only
         if(point==nil){return;}
         if(subsum + point->value <= sum){
            v.push_back(point->value);
            subsum = subsum + point->value;
            if(subsum==sum && point->isLeaf()){
               for( int i=0; i<v.size(); i++)
               {
                  cout << v.at(i) << " ";
                  found = true;
               }
            cout << endl;
            return;
            }
            else{
               findPath(point->left, subsum, sum, v, found);
               findPath(point->right, subsum, sum, v, found);
            }
         }
         else{
            return;
         }
   }
         
   
   void findSumPath(Node* n, int sum, int buffer[]){
      cout << "Part 2:" << endl;
      vector<Value> v;
      v.push_back(root->value);
      bool found=false;
      findPath(root->left,root->value, sum, v, found);
      findPath(root->right,root->value, sum, v, found);
      if(!found){cout << 0 << endl;}
   }
   
   
   void vertSum(Node* node, int hd, map<int, int>& m){
      if(node==nil){return;}
      if(m.count(hd)==1){
         int sum =m[hd]+node->value;
         m[hd]=sum;
      }
      else{m[hd]=node->value;}
      
      vertSum(node->left, hd-1, m);
      vertSum(node->right, hd+1, m);
      
      if(node==root){
         cout << "Part 3:" << endl;
         typedef map<int, int>::iterator it_type;
         for(it_type iterator = m.begin(); iterator != m.end(); iterator++) {
            cout << iterator->second << " "; 
         }
         cout << endl;
      }
   }
   
   void okay( ) { okay( root ); }
   
   Node* getRoot(){return root;}
   void okay( Node* T ) {
   // diagnostic code can be installed here
   return;
   }
}; // BST