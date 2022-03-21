#include "SMIterator.h"
#include "SortedMap.h"
#include <exception>
#include "BST.h"
using namespace std;

SortedMap::SortedMap(Relation r) {
	this->r = r;
}

TValue SortedMap::add(TKey k, TValue v) {
	TElem elem;
	elem.first = k;
	elem.second = v;
	this->tree.root = this->tree.insert(elem);
	this->sizeo += 1;
	return v;
}

TValue SortedMap::search(TKey k)  {
	return this->tree.search(k);
}

TValue SortedMap::remove(TKey k) {
	TValue x =  this->tree.remove(k);
	if (x != NULL_TVALUE)this->sizeo--;
	return x;
}

int SortedMap::size() const {
	return this->sizeo;
}

bool SortedMap::isEmpty() const {
	if (this->sizeo == 0)return true;
	return false;
}

SMIterator SortedMap::iterator() const {
	return SMIterator(*this);
}

SortedMap::~SortedMap() {
	//TODO - Implementation
}
