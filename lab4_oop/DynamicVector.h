#pragma once
#include "Medication.h"

typedef Medication TElement;

class DynamicVector
{
private:
	//private attributes:
	TElement* elems;
	int size;
	int capacity;
	void resize(double factor = 2);

public:
	//default constructor
	DynamicVector(int capacity = 15);

	//copy constructor
	DynamicVector(const DynamicVector& v);

	//destructor
	~DynamicVector();

	//methods
	DynamicVector& operator=(const DynamicVector& v);
	void add(const TElement& e);
	void deleteElement(const TElement& e, int index);
	int getSize() const;
	TElement* getAllElems() const;
};


