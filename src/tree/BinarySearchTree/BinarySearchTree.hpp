#ifndef BST
#define BST

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;
template<class K, class E>
class BST: public Dictionary, public BinaryTree
{
   private:


   public:    
      virtual bool IsEmptay() const = 0;
      virtual pair<K,E>* Get(const K&) const = 0;
      virtual void Insert(const Pair <K, E>&) = 0;
      virtual void Delete(const K&) = 0;
};

#endif