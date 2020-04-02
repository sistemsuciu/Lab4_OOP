#include "DynamicVector.h"

TElement* DynamicVector::getAllElems() const
{
	//returns all the elements from the vector
	return this->elems;
}

DynamicVector::DynamicVector(int capacity)
{
	//default constructor
	this->size = 0;
	this->capacity = capacity;
	this->elems = new TElement[capacity];
}

DynamicVector::DynamicVector(const DynamicVector& v)
{
	//copy constructor
	this->size = v.size;
	this->capacity = v.capacity;
	this->elems = new TElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];
}

DynamicVector::~DynamicVector()
{
	//destructor
	delete[] this->elems;
}

DynamicVector& DynamicVector::operator=(const DynamicVector& v)
{
	//assignment operator
	if (this == &v)
		return *this;

	this->size = v.size;
	this->capacity = v.capacity;

	delete[] this->elems;
	this->elems = new TElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];

	return *this;
}

int DynamicVector::getSize() const
{
	//returns the length of the vector
	return this->size;
}

void DynamicVector::deleteElement(const TElement& e, int index)
{
	//deletes an element from the current DynamicVector (by position)
	if (index < 0 || index >= this->size)
		return;
	//this->elems[index] =  NULL;
	for (int i = index; i < this->size - 1; i++)
	{
		this->elems[i] = this->elems[i + 1];
		//this->elems[i + 1] = NULL;
	}
	this->size = size - 1;
	if (this->size > 0 && this->size == this->capacity / 4)
		resize(2);

}

void DynamicVector::add(const TElement& e)
{
	//adds an element to the current DynamicVector
	if (this->size == this->capacity)
		this->resize();
	this->elems[this->size] = e;
	this->size++;
}

void DynamicVector::resize(double factor)
{
	//resizes the current DynamicVector, multiplying its capacity by a given factor (real number)
	this->capacity *= static_cast<int>(factor);

	TElement* els = new TElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		els[i] = this->elems[i];

	delete[] this->elems;
	this->elems = els;
}
