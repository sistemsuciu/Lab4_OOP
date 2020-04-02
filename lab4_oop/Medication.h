// This file contains the definition of the class "Medication"
#pragma once
#include <string>

class Medication
{
public:
	//constructors
	Medication();
	Medication(std::string& name, float& concentration);
	Medication(std::string& name, float& concentration, int& quantity, float& price);
	//destructor
	~Medication();

	//public methods:
	std::string get_name();
	double get_concentration();
	int get_quantity();
	double get_price();

	void set_name(std::string name);
	void set_concentration(double concentration);
	void set_quantity(int quantity);
	void set_price(double price);

private:
	//private attributes
	std::string name;
	double concentration;
	int quantity;
	double price;
};

