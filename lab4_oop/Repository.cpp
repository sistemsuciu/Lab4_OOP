#include <iostream>
#include "Repository.h"

Repository::Repository()
{
	//default constructor
}

Repository::~Repository()
{
	//destructor
}

void Repository::AddMedicine(Medication& med)
{
	//adds a medicine in the repository
	this->medicine_vector.add(med);
}

bool Repository::findMedicineByNameAndConcentration(std::string& name, float& concentration)
{
	//searching for a given medicine in the vector.
	// if the medicine already exists, it returns true. Otherwise, it returns false.
	Medication* medicineInDynamicVector = this->medicine_vector.getAllElems();
	if (medicineInDynamicVector == NULL)
		return false;

	for (int i = 0; i < this->medicine_vector.getSize(); i++)
	{
		Medication medicine = medicineInDynamicVector[i]; //identifies a medicine after concentration and name
		if (medicine.get_name() == name && medicine.get_concentration() == concentration)
			return true;
	}
	return false;
}

void Repository::deleteMedicine(std::string& name, float& concentration)
{
	//deletes a medicine from the vector (if it exists). Otherwise, it shows a message.
	Medication* medicineInDynamicVector = this->medicine_vector.getAllElems();
	if (findMedicineByNameAndConcentration(name, concentration) == true)
	{
		for (int i = 0; i < this->medicine_vector.getSize(); i++)
		{
			Medication medicine = medicineInDynamicVector[i];
			if (medicine.get_name() == name && medicine.get_concentration() == concentration)
				this->medicine_vector.deleteElement(medicine, i);
		}
	}
	else
		std::cout << "The medicine wasn't found!" << std::endl;
}

DynamicVector Repository::getMedicine()
{
	//returns the vector of medicines.
	return medicine_vector;
}