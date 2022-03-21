#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
#include <stdlib.h>
using namespace std;
long MEMORY_SIZE = 0x7fffffff;

Bag::Bag() {
	this->capacity = 1;
	this->len = 0;
	this->elements = new (std::nothrow) ValuePair[1251000];
	for (int i = 0; i < this->len; i++)
		this->elements[i].second = 1;
}

void Bag::add(int e) {
	bool found = false;
	int i=0;
	if (this->capacity == this->len)
	{
		this->capacity *=2;
	}
	for (i = 0; i < this->len; i++)
		if (this->elements[i].first == e)
		{
			this->elements[i].second++;
			found = true;
			break;
		}
	if (found == false) {
		this->elements[this->len].first = e;
		this->elements[this->len].second = 1;
		this->len++;
	}
}

	bool Bag::remove(TElem elem) {
		bool found = false;
		int i, position;
	
		for(i=0;i<this->len;i++)
		{
			if (this->elements[i].first == elem && this->elements[i].second > 1) {
				this->elements[i].second--; return true;
			}
			else if (this->elements[i].first == elem && this->elements[i].second == 1)
			{
				position = i;
				found = true;
				break;
				
			}
		}
		if(found == true)
		{
			for (i = position; i < this->len - 1; i++)
				this->elements[i] = this->elements[i + 1];
			this->len--;
			return true;
		}
		return false;
}


	bool Bag::search(TElem elem) const {
	for(int i = 0; i < this->len; i++)
	{
		if (this->elements[i].first == elem)return true;
	}
	return false; 
}

int Bag::nrOccurrences(TElem elem) const {
	int k = 0;
	for (int i = 0; i < this->len; i++)
		if (this->elements[i].first == elem)k=this->elements[i].second;
	return k;
}


int Bag::size() const {
	int size = 0;
	for (int i = 0; i < this->len; i++)
		size = size + this->elements[i].second;
	return size;
	
}


bool Bag::isEmpty() const {
	return(this->len == 0);
}

BagIterator Bag::iterator() const {
	return BagIterator(*this);
}


Bag::~Bag() {
	delete[this->capacity] this->elements;
}
	

