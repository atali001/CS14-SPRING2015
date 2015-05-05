#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node
{
   T data;
   Node* next;
   
   Node(T data): data(data), next(0) {} //node constructor
};

#endif
