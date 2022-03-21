#include <exception>
#include "BagIterator.h"
#include "Bag.h"

using namespace std;


BagIterator::BagIterator(const Bag& c): bag(c)
{
	this->current = 0;
	this->goneTrough = 0;
	
}

void BagIterator::first() {
	this->current = 0;
	this->goneTrough = 1;
}


void BagIterator::next() {
	if (this->current == this->bag.len )
	{
		throw exception();
	}
	else if (this->goneTrough == this->bag.elements[this->current].second)
	{
		
		this->goneTrough = 1;
		this->current++;
	}
	else this->goneTrough++;


}

//|| ((this->current == this->bag.len - 1) && (this->goneTrough == this->bag.elements[this->current].second))

bool BagIterator::valid()  {
	if (this->goneTrough == this->bag.elements[this->current].second)
	{
		if (this->current + 1 == this->bag.len) return false;
	}
	if (this->current < this->bag.len ) return true;
	return false;
	
}

TElem BagIterator::getCurrent() const
{
	if (this->current == this->bag.len )
	{
		throw exception();
	}
	else return this->bag.elements[this->current].first;
	
	
}
