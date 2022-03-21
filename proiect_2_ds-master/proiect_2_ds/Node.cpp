#include "Node.h"
#include "utility"
#include <utility>

Node::Node()
{
	this->myPair = std::make_pair(-11111, -11111);
	this->next = nullptr;
	this->prev = nullptr;
}



