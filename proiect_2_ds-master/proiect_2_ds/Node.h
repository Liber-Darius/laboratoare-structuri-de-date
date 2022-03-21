#pragma once
#include <iostream>
#include <utility>
#include <utility>
using namespace std;
//DO NOT CHANGE THIS PART
typedef int TComp;
typedef TComp TElem;
typedef bool(*Relation)(TComp, TComp);
#define NULL_TCOMP -11111;
typedef std::pair<TComp, int> ValuePair;
class Node
{
public:
	ValuePair myPair;
	Node* next = nullptr;
	Node* prev = nullptr;
	Node();
	


};

