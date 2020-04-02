#include "UI.h"
#include <iostream>
#include <string>
using namespace std;

UI::~UI()
{
	//destructor
}

void UI::printMenu()
{
	//prints the main menu
	cout << endl;
	cout << "Menu:" << endl;
	cout << "\t1 - Add a medicine." << endl;
	cout << "\t2 - Show all the medicines." << endl;
	cout << "\t3 - Remove a medicine." << endl;
	cout << "\t4 - See all the available medicines containing a given string." << endl;
	cout << "\t5 - See the medicines that are in short supply." << endl;
	cout << "\t6 - See the medicines grouped by price." << endl;
	cout << "\t7 - Undo the last operation." << endl;
	cout << "\t8 - Redo the last operation." << endl;
	cout << "\t0 - Exit." << endl;
	cout << "Choose an option: ";
}

void UI::addMedicineToRepo()
{
	//adds a medicine to the repository
	cout << "Type the name of the medicine: ";
	std::string name;
	std::string tempStr;
	getline(cin, name);
	cout << "Type the concentration of the medicine: ";
	float concentration;
	getline(cin, tempStr);
	concentration = stof(tempStr.c_str());
	while (concentration < 0 || concentration > 100)
	{
		cout << "The concentration must be positive and maximum 100!" << endl;
		cout << "Retype the concentration of the medicine: ";
		getline(cin, tempStr);
		concentration = stof(tempStr.c_str());
	}
	if (this->ctrl.FindMedicine(name, concentration) == false)
	{
		cout << "Type the quantity of the medicine: ";
		int quantity;
		std::string tempStr;
		getline(cin, tempStr);
		quantity = atoi(tempStr.c_str());
		while (quantity <= 0)
		{
			cout << "Quantity must be positive!" << endl;
			cout << "Retype the quantity:";
			getline(cin, tempStr);
			quantity = atoi(tempStr.c_str());
		}
		cout << "Type the price of the medicine: ";
		float price;
		getline(cin, tempStr);
		price = stof(tempStr.c_str());
		while (price <= 0)
		{
			cout << "The price must be positive!" << endl;
			cout << "Retype the quantity of the medicine: ";
			getline(cin, tempStr);
			price = stof(tempStr.c_str());
		}
		this->ctrl.addMedicineToRepository(name, concentration, quantity, price);
		cout << "Added!" << endl;
	}
	else
	{
		DynamicVector vector = this->ctrl.getRepository().getMedicine();
		Medication* medicine = vector.getAllElems();
		cout << "This medicine was found in the stock." << endl;
		cout << "Type the quantity that you want to add: ";
		int quantity;
		std::string tempStr;
		getline(cin, tempStr);
		quantity = atoi(tempStr.c_str());
		while (quantity <= 0)
		{
			cout << "The quantity must be positive!" << endl;
			cout << "Retype the quantity: ";
			getline(cin, tempStr);
			quantity = atoi(tempStr.c_str());
		}
		for (int i = 0; i < vector.getSize(); i++)
		{
			Medication m = medicine[i];
			if (m.get_name() == name && m.get_concentration() == concentration)
			{
				int new_quantity;
				new_quantity = m.get_quantity() + quantity;
				float price;
				price = m.get_price();
				this->ctrl.deleteMedicineFromRepository(name, concentration);
				this->ctrl.addMedicineToRepository(name, concentration, new_quantity, price);
				cout << "The quantity was successfully updated!" << endl;
				cout << endl;
				cout << "The new informations about the medicine: " << endl;
				cout << "  Name: " << m.get_name() << endl;
				cout << "  Concentration: " << m.get_concentration() << " %" << endl;
				cout << "  Quantity: " << new_quantity << " boxes" << endl;
				cout << "  Price: " << m.get_price() << " $" << endl;
			}
		}
	}
}

void UI::deleteMedicineFromVector()
{
	//deletes a medicine from the repository
	cout << "Type the name of the medicine that you want to delete:";
	std::string name;
	getline(cin, name);
	cout << "Type its concentration:";
	float concentration;
	std::string tempStr;
	getline(cin, tempStr);
	concentration = stof(tempStr.c_str());
	while (concentration < 0 || concentration > 100)
	{
		cout << "The concentration must be positive number and maximum 100!" << endl;
		cout << "Retype the concentration of the medicine.";
		getline(cin, tempStr);
		concentration = stof(tempStr.c_str());
	}
	this->ctrl.deleteMedicineFromRepository(name, concentration);
}

void UI::displayAllMedicineRepo()
{
	//shows all the medicines from the repository
	DynamicVector vector = this->ctrl.getRepository().getMedicine();
	Medication* medicine = vector.getAllElems();
	if (medicine == NULL)
		return;
	if (vector.getSize() == 0)
	{
		cout << "No medicine was found." << endl;
		return;
	}
	cout << "The medicine from the stock: " << endl << endl;
	for (int i = 0; i < vector.getSize(); i++)
	{
		Medication m = medicine[i];
		cout << i + 1 << "." << "Name: " << m.get_name() << endl;
		cout << "  Concentration: " << m.get_concentration() << " %" << endl;
		if (m.get_quantity() == 1)
			cout << "  Quantity: " << m.get_quantity() << " box" << endl;
		else
			cout << "  Quantity: " << m.get_quantity() << " boxes" << endl;
		cout << "  Price: " << m.get_price() << " $" << endl << endl;
	}
}

void UI::displayMedicinebyPrice()
{
	//shows all the medicine from the repository grouped by a given price
	DynamicVector vector = this->ctrl.getRepository().getMedicine();
	Medication* medicine = vector.getAllElems();
	if (medicine == NULL)
		cout << "No medicine with the given price was found." << endl;
	if (vector.getSize() == 0)
	{
		cout << "No medicine was found in the stock." << endl;
		return;
	}
	cout << "Type a price: " << endl;
	float price;
	std::string tempStr;
	getline(cin, tempStr);
	price = stof(tempStr.c_str());
	int ok = 0;
	while (price <= 0)
	{
		cout << "The price of the medicine must be positive." << endl;
		cout << "Retype the price: ";
		getline(cin, tempStr);
		price = stof(tempStr.c_str());
	}
	cout << "The medicine from the stock with the price of " << price << "$ are: " << endl;
	for (int i = 0; i < vector.getSize(); i++)
	{
		Medication m = medicine[i];
		if (price == m.get_price())
		{
			ok = 1;
			cout << i + 1 << "." << "Name: " << m.get_name() << endl;
			cout << "  Concentration: " << m.get_concentration() << " %" << endl;
			if (m.get_quantity() == 1)
				cout << "  Quantity: " << m.get_quantity() << " box" << endl;
			else
				cout << "  Quantity: " << m.get_quantity() << " boxes" << endl;
			cout << "  Price: " << m.get_price() << "$" << endl << endl;
		}
	}
	if (ok == 0)
		cout << "There are no medicines with the given price." << endl;
}

void UI::displayMedicinebyString()
{
	//shows all the medicine from the repository containing a given string
	DynamicVector vector = this->ctrl.getRepository().getMedicine();
	Medication* medicine = vector.getAllElems();
	if (medicine == NULL)
		cout << "No medicine with the given string was found." << endl;
	if (vector.getSize() == 0)
	{
		cout << "No medicine was found in the stock." << endl;
		return;
	}
	cout << "Type a string: " << endl;
	std::string string;
	getline(cin, string);
	if (string == "")
		cout << "The medicine from the stock containing the empty string are: " << endl;
	else
		cout << "The medicine from the stock containing \"" << string << "\" are: " << endl;

	Medication found[50];
	int l = 0, ok = 0;

	for (int i = 0; i < vector.getSize(); i++)
	{
		Medication m = medicine[i];
		if (m.get_name().find(string) != string::npos || string == "")
		{
			found[l].set_name(medicine[i].get_name());
			found[l].set_quantity(medicine[i].get_quantity());
			found[l].set_concentration(medicine[i].get_concentration());
			found[l].set_price(medicine[i].get_price());
			l++;
			ok = 1;
		}
	}

	for (int i = 0; i < l - 1; i++)
	{
		for (int j = i + 1; j < l; j++)
		{
			std::string x = found[i].get_name();
			std::string y = found[j].get_name();
			if (x.compare(y) > 0)
			{
				std::string aux;
				aux = x;
				x = y;
				y = aux;
			}
			found[i].set_name(x);
			found[j].set_name(y);
		}
	}

	if (ok == 1)
	{
		for (int i = 0; i < l; i++)
		{
			cout << i + 1 << "." << "Name: " << found[i].get_name() << endl;
			cout << "  Concentration: " << found[i].get_concentration() << " %" << endl;
			if (found[i].get_quantity() == 1)
				cout << "  Quantity: " << found[i].get_quantity() << " box" << endl;
			else
				cout << "  Quantity: " << found[i].get_quantity() << " boxes" << endl;
			cout << "  Price: " << found[i].get_price() << "$" << endl << endl;
		}
	}
	else
		cout << "There are no medicines with the given string." << endl;
}

void UI::displayMedicineShortSupply()
{
	//shows all the medicine that are in short supply (less than X)
	DynamicVector vector = this->ctrl.getRepository().getMedicine();
	Medication* medicine = vector.getAllElems();
	if (medicine == NULL)
		cout << "No medicine with the given quantity was found." << endl;
	if (vector.getSize() == 0)
	{
		cout << "No medicine was found in the stock." << endl;
		return;
	}
	cout << "Type a quantity: " << endl;
	float quantity;
	std::string tempStr;
	getline(cin, tempStr);
	quantity = atoi(tempStr.c_str());
	int ok = 0;
	while (quantity <= 0)
	{
		cout << "The quantity of the medicine must be positive." << endl;
		cout << "Retype the quantity: ";
		getline(cin, tempStr);
		quantity = atoi(tempStr.c_str());
	}
	if (quantity == 1)
		cout << "The medicine from the stock with the quantity less than " << quantity << " box are: " << endl;
	else
		cout << "The medicine from the stock with the quantity less than " << quantity << " boxes are: " << endl;
	for (int i = 0; i < vector.getSize(); i++)
	{
		Medication m = medicine[i];
		if (quantity > m.get_quantity())
		{
			ok = 1;
			cout << i + 1 << "." << "Name: " << m.get_name() << endl;
			cout << "  Concentration: " << m.get_concentration() << " %" << endl;
			if (m.get_quantity() == 1)
				cout << "  Quantity: " << m.get_quantity() << " box" << endl;
			else
				cout << "  Quantity: " << m.get_quantity() << " boxes" << endl;
			cout << "  Price: " << m.get_price() << "$" << endl << endl;
		}
	}
	if (ok == 0)
		cout << "There are no medicines with the given quantity." << endl;
}

void UI::run()
{
	//method runs the user interface
	int option;
	bool working = true;
	while (working != false)
	{
		printMenu();
		std::string tempStr;
		getline(cin, tempStr);
		option = atoi(tempStr.c_str());
		switch (option)
		{
		case 1:
		{
			addMedicineToRepo();
			break;
		}
		case 2:
		{
			displayAllMedicineRepo();
			break;
		}
		case 3:
		{
			deleteMedicineFromVector();
			break;
		}
		case 4:
		{
			displayMedicinebyString();
			break;
		}
		case 5:
		{
			displayMedicineShortSupply();
			break;
		}
		case 6:
		{
			displayMedicinebyPrice();
			break;
		}
		case 7:
		{
			break;
		}
		case 8:
		{
			break;
		}
		case 0:
		{
			working = false;
			break;
		}
		default:
		{
			cout << "The chosen option doesn't exist." << endl;
			cout << "Choose another option: ";
			std::string tempStr;
			getline(cin, tempStr);
			option = atoi(tempStr.c_str());
		}
		}
	}
}
