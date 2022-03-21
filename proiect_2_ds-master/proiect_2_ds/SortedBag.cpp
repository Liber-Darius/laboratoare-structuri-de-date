#include "SortedBag.h"
#include "SortedBagIterator.h"
#include <iostream>
using namespace std;
#include <utility>
#include "Node.h"
#define NULL_TCOMP -11111;

SortedBag::SortedBag(Relation r) {
	
	this->r = r;
	this->data = new DLL();
	
	
}

void SortedBag::add(TComp e) {
	int ok = 0;
	Node* a = new Node();
	a = this->data->head;
	if (this->data->head == nullptr) {
		Node* nou = new Node();
		nou->myPair = std::make_pair(e, 1);
		nou->next = this->data->tail;
		this->data->head = nou;
		this->data->tail = nou;
		ok = 1;
	}
	Node* b = new Node();
	b = this->data->head;
	while (b != nullptr && ok == 0)
	{
		if (b->myPair.first == e) { //verific daca elementul exista deja 
			b->myPair.second++; 
			ok = 1;
		}
		b = b->next;
	}
	if (ok == 0) {
		Node* nout = new Node();

		nout->myPair = std::make_pair(e, 1);
		this->data->tail->next= nout;
		nout->next = nullptr;
		nout->prev = this->data->tail;
		this->data->tail = nout;
	}
	
}


bool SortedBag::remove(TComp e) {
	//first check if it is empty
	Node* current = new Node();
	current = this->data->head;
	while (current != nullptr && current->myPair.first != e)current = current->next;
	Node* deletedNode = new Node();
	deletedNode = current;
	if (current != nullptr && current->myPair.second <= 1) {
		if (current == this->data->head) {//remove first 
			if (current == this->data->tail) {
				this->data->tail = nullptr;
				this->data->head = nullptr;
				return true;
			}
			else {
				this->data->head = this->data->head->next;
				this->data->head->prev = nullptr;
				return true;
			}
		}
		else if (current == this->data->tail) {
			this->data->tail = this->data->tail->prev;
			this->data->tail->next = nullptr;
			return true;
		}
		else {
			current->next->prev = current->prev;
			current->prev->next = current->next;
			return true;
		}
	}
	else if (current != nullptr && current->myPair.second > 1) {
		current->myPair.second--;
		return true;
	}
	Node* deletedElement = new Node();
	deletedElement = deletedNode;
	return false;
}


bool SortedBag::search(TComp elem) const {
	
	Node* ptr = this->data->head;
	while (ptr != NULL)
	{
		if (ptr->myPair.first == elem) {
			return true;
		}
		ptr = ptr->next;
	}
	return false;
}


int SortedBag::nrOccurrences(TComp elem) const {
	int sum = 0;
	Node* ptr = this->data->head;
	while (ptr != NULL)
	{
		if (ptr->myPair.first == elem) {
			return ptr->myPair.second;
		}
		ptr = ptr->next;
	}
	return 0;
}



int SortedBag::size() const {
	int sum = 0;
	Node* ptr = this->data->head;
	while (ptr != NULL)
	{
		sum = sum + ptr->myPair.second;
		ptr = ptr->next;
	}
	return sum;
}


bool SortedBag::isEmpty() const {
	if (this->data->head == NULL)
		return true;
	return false;
}


SortedBagIterator SortedBag::iterator() const {
	return SortedBagIterator(*this);
}


SortedBag::~SortedBag() {
	delete[] this->data;
}

void SortedBag::displayInfo()
{
	
	Node* ptr = this->data->head;
	while (ptr != nullptr)
	{
		std::cout << ptr->myPair.first << "de "<<ptr->myPair.second<< " ori "<<endl;
		ptr = ptr->next;
	}
	

}
