#pragma once
#include "Medication.h"
#include "DynamicVector.h"
class Repository
{
private:
	DynamicVector medicine_vector;
public:
	Repository();
	~Repository();

	void AddMedicine(Medication& med);
	void deleteMedicine(std::string& name, float& concentration);

	bool findMedicineByNameAndConcentration(std::string& name, float& concentration);

	//daca medicamentul exista, atunci i se va schimba doar cantitatea
	//void ChangeQuantity(std::string &name, float &concentration, int &quantity, float &price); 

	DynamicVector getMedicine();
};

