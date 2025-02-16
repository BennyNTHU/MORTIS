#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

template <class K, class E> class Dictionary;

template <class K, class E>
struct pair {
    K first; 
    E second;
};

Pair<K, E>* RankGet(int r);
void Split(const K& k, BST<K, E>& small, pair<K, E>*& mid, BST<K, E>& big);


template <class K, class E>
class Dictionary
{
   public:    
      virtual bool IsEmptay() const = 0;  // return true if dictionary is empty
      virtual pair<K,E>* Get(const K&) const = 0;  // return pointer to the pair w. specified key
      virtual void Insert(const Pair <K, E>&) = 0;   // insert the given pair; if key ia a duplicate, update associate element
      virtual void Delete(const K&) = 0;  // delete pair w. specified key      
};