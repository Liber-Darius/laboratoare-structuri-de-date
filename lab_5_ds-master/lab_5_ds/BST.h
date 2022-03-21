#pragma once
#include "Node.h"
class BST
{
private:
	
public:
	Node* root;
	int size;
	TValue search(TKey elem);
	Node* insertRec(Node *currentNode, TElem elem);
	Node* insert(TElem elem);
	TValue removeRec(Node* root, TKey elem);
	TValue remove(TKey elem);
	Node* findMaximumNode(Node* ptr); //returnez nodul nu valoarea
	TElem getMinimum();
	BST();

};

