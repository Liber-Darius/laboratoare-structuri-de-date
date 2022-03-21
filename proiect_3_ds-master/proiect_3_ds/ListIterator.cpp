#include "ListIterator.h"
#include "IteratedList.h"
#include <exception>

ListIterator::ListIterator(const IteratedList& list) : list(list) {
	this->current = this->list.head;
}

void ListIterator::first() {
	this->current = this->list.head;
}

void ListIterator::next() {
	this->current = list.next[this->current];
}

bool ListIterator::valid() const {
	if (this->current == -1 && !this->list.isEmpty())return false;
	return  true;
}

TElem ListIterator::getCurrent() const {
	return this->list.lista[this->current];
	return NULL_TELEM;
}



