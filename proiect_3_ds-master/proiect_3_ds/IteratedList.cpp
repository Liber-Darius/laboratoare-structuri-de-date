
#include <exception>
using namespace std;
#include "ListIterator.h"
#include "IteratedList.h"

IteratedList::IteratedList() {
	//TODO - Implementation
	this->cap = 1;
	this->lista = new int[this->cap];
	this->next = new int[this->cap];
	this->head = -1;
	this->firstEmpty = this->cap;
	this->nrOfEmpty = 1;
}

int IteratedList::size() const {
	//TODO - Implementation
	return this->cap - this->nrOfEmpty;
	return 0;
}

bool IteratedList::isEmpty() const {
	//TODO -  Implementation
	if (this->cap - this->nrOfEmpty == 0)return true;
	return false;
}

ListIterator IteratedList::first() const {
	return ListIterator(*this);
}

TElem IteratedList::getElement(ListIterator pos) const {
	//TODO - Implementation
	if (pos.getCurrent() > 0 && pos.getCurrent() <= this->cap)return this->lista[pos.getCurrent()];
	return NULL_TELEM;
}

TElem IteratedList::remove(ListIterator& pos) {
	int poz = pos.list.lista[pos.current-1];
	int nodC = this->head;
	int prevNode = -1;
	while (nodC != -1 && this->lista[nodC] != pos.getCurrent()) {
		prevNode = nodC;
		nodC = this->next[nodC];
	}
	if (nodC != -1) {
		if (nodC == this->head)
			this->head = this->next[this->head];
		else
			this->next[prevNode] = this->next[nodC];
		//add the nodC position to the list first empty space
		this->lista[nodC] = this->firstEmpty;
		this->firstEmpty = nodC;
		this->nrOfEmpty++;
		return pos.getCurrent();
	}
	return NULL_TELEM;
}

ListIterator IteratedList::search(TElem e) const{
	
	int current = this->head;
	while (current != -1 && this->lista[current] != e) {
		current = this->next[current];
	}
	ListIterator it = this->first();
	it.current = current;
	if (current != -1) return it;
	return ListIterator(*this);	
}

TElem IteratedList::setElement(ListIterator pos, TElem e) {
    //TODO - Implementation
	return NULL_TELEM;
}

void IteratedList::addToPosition(ListIterator& pos, TElem e) {
	int pozition = pos.current;
	if (pos.current < 1)
		throw exception();
	if (pos.current == 1)this->addToBeginning(pos.getCurrent());
	else {
		int pozCurrent = 1;
		int nodCurrent = this->head;
		while (nodCurrent != -1 && pozCurrent < pos.current - 1) {
			pozCurrent = pozCurrent + 1;
			nodCurrent = this->next[nodCurrent];
		}
		if (nodCurrent != -1) {
			int newElem = this->firstEmpty;
			this->firstEmpty = this->next[firstEmpty];
			this->lista[newElem] = e;
			this->next[newElem] = this->next[nodCurrent];
			this->next[nodCurrent] = newElem; this->nrOfEmpty--;
			pos.current = pozition;
		}
		else { int ok = 0; ok++; }
	}
}

void IteratedList::addToEnd(TElem e) {
	//caut cine e legat de ultimul
	if (this->head == -1)this->head = this->firstEmpty;
	if (this->isEmpty() == true) {
		
		this->lista[this->firstEmpty] = e;
		this->next[this->firstEmpty] = -1;
	}
	else {
		for (int i = 1; i < this->cap; i++)
			if (this->next[i] == -1) {
				this->next[i] = this->firstEmpty;
				this->lista[this->firstEmpty] = e;
				this->next[this->firstEmpty] = -1;
			}
	}
	if (this->firstEmpty == this->cap)this->firstEmpty++;
	this->cap++;

}

void IteratedList::addToBeginning(TElem e)
{
	if (this->cap == 1) {
		this->addToEnd(e);
	}
	else {
		//asta nou devine head si are next pe primul
		this->lista[this->firstEmpty] = e;
		this->next[this->firstEmpty] = this->head;
		if (this->cap == this->firstEmpty) {
			this->cap++;
			this->firstEmpty = this->cap;
			
		}
		this->nrOfEmpty--;
	}
}

IteratedList::~IteratedList() {
	//TODO - Implementation
}
