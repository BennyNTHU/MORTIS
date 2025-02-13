#ifndef NODE
#define NODE

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

class Node
{
	private:
		double coef;
		int exp;
		Node* next;
		// Hides constructor. Restrict access to object pool only.
		Node();

        static Node* IdleNodes;

	public:
		double GetCoef();
        int GetExp();
        Node* GetNext();
        static void DeleteNext(Node **node);
        static int AvailableNodeCount();
		static int ChainLength(Node *node);
		static void InsertEmpty(Node **node);
		static Node* GetNode();
		void Set (double coef, int exp);
        void Set (Node* next);
        void Set (double coef, int exp, Node* next);
        // Cut the first link, making it a simple singly linked list
		// Then linearly return these nodes
		void RetNode ();
};

#endif