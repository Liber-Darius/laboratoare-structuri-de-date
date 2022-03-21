#pragma once
typedef int TKey;
typedef int TValue;
#include <utility>
#include "BST.h"
typedef int TKey;
typedef int TValue;
#include <utility>
typedef std::pair<TKey, TValue> TElem;
#define NULL_TVALUE -111111
#define NULL_TPAIR pair<TKey, TValue>(-111111, -111111);

class Node
{
public:
	Node* parent, * left, * right;
	TElem info;
	Node();
	Node(TElem elem);
};

