#include <utility>
#include "BST.h"
typedef int TKey;
typedef int TValue;
#include <utility>
typedef std::pair<TKey, TValue> TElem;
#define NULL_TVALUE -111111
#define NULL_TPAIR pair<TKey, TValue>(-111111, -111111);
Node::Node()
{
	this->info.first = NULL_TVALUE;
	this->info.second = NULL_TVALUE;
	this->right = nullptr;
	this->left = nullptr;
	this->parent = nullptr;

}

Node::Node(TElem elem)
{
	this->info = elem;
}
