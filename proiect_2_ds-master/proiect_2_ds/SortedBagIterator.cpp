#include "SortedBagIterator.h"
#include "SortedBag.h"
#include <exception>

using namespace std;

SortedBagIterator::SortedBagIterator(const SortedBag& b) : bag(b) {
	this->current = this->bag.data->head;
}

TComp SortedBagIterator::getCurrent() {
	Node* current = bag.data->head;
	if (this->current == nullptr)
		throw exception();
	if (this->current != nullptr)
		return this->current->myPair.first;
	return NULL_TCOMP;
}

bool SortedBagIterator::valid() {
	if (this->current == nullptr)
		return false;
	else return true;
}

void SortedBagIterator::next() {
	if (this->current == nullptr)
		throw exception();
	this->current= this->current->next;
	//TODO - Implementation
}

void SortedBagIterator::first() {
	this->current = this->bag.data->head;
}

