
#pragma once
//DO NOT INCLUDE SORTEDBAGITERATOR
#include <utility>
#include "Node.h"
//DO NOT CHANGE THIS PART
typedef int TComp;
typedef TComp TElem;
typedef bool(*Relation)(TComp, TComp);
#define NULL_TCOMP -11111;
typedef std::pair<TComp, int> ValuePair;
class DLL
{
public:
	Node* head;
	Node* tail;
	DLL();
	

};

