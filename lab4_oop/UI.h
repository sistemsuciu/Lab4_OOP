#pragma once
#include "Controller.h"

class UI
{
private:
	Controller ctrl;
	static void printMenu();

	void deleteMedicineFromVector();
	void addMedicineToRepo();
	void displayAllMedicineRepo();
	void displayMedicinebyPrice();
	void displayMedicinebyString();
	void displayMedicineShortSupply();

public:
	UI(Controller& c) : ctrl(c) {};
	~UI();
	void run();
};