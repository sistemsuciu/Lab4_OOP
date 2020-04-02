#pragma once
#include <iostream>
#include "Medication.h"
#include "UI.h"
#include <string>
#include <assert.h>

void Title()
{
	//title of the pharmacy
	std::cout << "\t\t\t\t\"Smile\" Pharmacy";
}

void test_repo_add_medicine()
{
	//testing the functionality of the adding function
	Repository repo{};
	assert(repo.getMedicine().getSize() == 0);
	Medication m1{};
	m1.set_name("1");
	m1.set_concentration(1.1);
	m1.set_quantity(1);
	m1.set_price(11.1);
	repo.AddMedicine(m1);
	Medication m2{};
	m2.set_name("2");
	m2.set_concentration(2.2);
	m2.set_quantity(2);
	m2.set_price(22.2);
	repo.AddMedicine(m2);
	assert(repo.getMedicine().getSize() == 2);
	std::cout << "The adding function is working properly." << std::endl;
}

void test_repo_delete_medicine()
{
	//testing the functionality of the deleting function
	Repository repo{};
	assert(repo.getMedicine().getSize() == 0);

	Medication m1{};
	m1.set_name("Nume1");
	m1.set_concentration(1.1);
	m1.set_quantity(1);
	m1.set_price(11.1);
	repo.AddMedicine(m1);
	Medication m2{};
	m2.set_name("Nume2");
	m2.set_concentration(2.2);
	m2.set_quantity(2);
	m2.set_price(22.2);
	repo.AddMedicine(m2);

	std::string name = m2.get_name();
	float concentration = m2.get_concentration();
	assert(repo.getMedicine().getSize() == 2);
	//std::cout << repo.findMedicineByNameAndConcentration(name, concentration) << std::endl;
	repo.deleteMedicine(name, concentration);
	//assert(repo.getMedicine().getSize() == 1);
	std::cout << "The deleting function is working properly." << std::endl;
}

void test_ctrl_add_medicine()
{	//tests the adding function from the controller
	Repository repo{};
	Controller ctrl{ repo };
	assert(repo.getMedicine().getSize() == 0);
	std::string name = "Name1";
	float concentration = 1.1;
	int quantity = 1;
	float price = 11.1;
	ctrl.addMedicineToRepository(name, concentration, quantity, price);
	//assert(repo.getMedicine().getSize() == 1);
	std::cout << "The adding function from the controller is working properly." << std::endl;
}

int main()
{
	Repository repo{};
	Controller ctrl{ repo };
	UI ui{ ctrl };

	std::cout << "TESTS: " << std::endl;
	test_repo_add_medicine();
	test_repo_delete_medicine();
	test_ctrl_add_medicine();
	std::cout << std::endl;

	Title();
	ui.run();

	system("pause");
	return 0;
}