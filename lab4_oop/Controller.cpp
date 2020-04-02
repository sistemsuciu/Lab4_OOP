#pragma once
#include "Controller.h"

Controller::Controller()
{
	//constructor
}

Controller::~Controller()
{
	//destructor
}

Repository Controller::getRepository()
{
	//returns the repository
	return repo;
}

void Controller::addMedicineToRepository(std::string& name, float& concentration, int& quantity, float& price)
{
	//adds a medicine in the repository
	Medication m{ name,concentration,quantity,price };
	this->repo.AddMedicine(m);
}

bool Controller::FindMedicine(std::string& name, float& concentration)
{
	//checks if a medicine exists in the repository
	Medication m{ name,concentration };
	if (this->repo.findMedicineByNameAndConcentration(name, concentration) == true)
		return true;
	return false;
}

void Controller::deleteMedicineFromRepository(std::string& name, float& concentration)
{
	//deletes a medicine from the repository
	this->repo.deleteMedicine(name, concentration);
}
