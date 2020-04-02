#pragma once
#include "Repository.h"

class Controller
{
private:
	Repository repo;

public:
	Controller();
	Controller(const Repository& r) : repo(r) {}
	~Controller();

	Repository getRepository();
	void addMedicineToRepository(std::string& name, float& concentration, int& quantity, float& price);
	void deleteMedicineFromRepository(std::string& name, float& concentration);
	bool FindMedicine(std::string& name, float& concentration);
};

