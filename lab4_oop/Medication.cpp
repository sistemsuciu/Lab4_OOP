// This file contains the implementation of the class "Medication"

#include "Medication.h"
#include <vector>


/* CONSTRUCTOR AND DESTRUCTOR */
Medication::Medication()
{
	//default constructor
	this->name = "";
	this->concentration = 0.0;
	this->quantity = 0;
	this->price = 0.0;
}

Medication::Medication(std::string& name, float& concentration, int& quantity, float& price)
{
	//constructor with parameters
	this->name = name;
	this->concentration = concentration;
	this->quantity = quantity;
	this->price = price;
}

Medication::Medication(std::string& name, float& concentration)
{
	//constructor
	this->name = name;
	this->concentration = concentration;
}

Medication::~Medication()
{
	//destructor
}

/* GETTERS */
std::string Medication::get_name()
{
	return this->name;
}

double Medication::get_concentration()
{
	return this->concentration;
}

int Medication::get_quantity()
{
	return this->quantity;
}

double Medication::get_price()
{
	return this->price;
}

/* SETTERS */
void Medication::set_name(std::string name)
{
	this->name = name;
}

void Medication::set_concentration(double concentration)
{
	this->concentration = concentration;
}

void Medication::set_quantity(int quantity)
{
	this->quantity = quantity;
}

void Medication::set_price(double price)
{
	this->price = price;
}
