// FinalProject.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Item.h"
#include "Customer.h"
using namespace std;

void fillInventory(vector <Item>& Inventory) {

	string category1;
	string brand1;
	string type1;
	string color1;
	int price1;

	cout << "Enter the name of the inventory file";
	
	string name;

	cin >> name;

	fstream input(name + ".txt");
	
	if (input.fail()) {
		cout << "Invalid filename" << endl;
	}

	while (input >> category1 >> brand1 >> type1 >> color1 >> price1) {

		Item newItem(category1, brand1, type1, color1, price1);
		Inventory.push_back(newItem);
	}
}

void PrintInventory(vector <Item>& Inventory) {
	for (int i = 0; i < Inventory.size(); i++) {
		cout << Inventory[i].getCategory() << " " << Inventory[i].getBrand() << " " << Inventory[i].getType()
			<< " " << Inventory[i].getColor() << " " << Inventory[i].getPrice() << endl;

	}
}

void FillCustomer(vector <Customer> & List) {
	string filename;
	string fname;
	string lname;
	string email;
	string category;
	string iname;
	string brand;
	string color;
	int saleprice;
	int ID;

	cout << "Enter the name of the customer order file ";



	cin >> filename;

	fstream input1(filename + ".txt");

	if (input1.fail()) {
		cout << "Invalid filename " << endl;
	}

	while (input1 >> fname >> lname >> email >> category >> brand >> iname >> color >> saleprice) {
		Customer newList(fname, lname , email , category , brand , iname , color , saleprice);
		List.push_back(newList);
	}
}

void PrintCustomer(vector <Customer> & List) {
	for (int a = 0; a < List.size(); a++) {
		cout << List[a].getID() << " " << List[a].getFName() << " " << List[a].getLName() << " " << List[a].getEmail() << " "
			<< List[a].getCategory() << " " << List[a].getBrand() << " " << List[a].getIname() << " " << List[a].getColor() << " "
			<< List[a].getSaleprice() << endl;
	}
}

void SortInventory(vector <Item> & Inventory) {
	Item temp;
	for (int i = 0; i <= Inventory.size() - 1; i++)

		for (int j = i + 1; j <= Inventory.size() - 1; j++)
			if (Inventory[i].getPrice() > Inventory[j].getPrice()) {
				temp = Inventory[i];
				Inventory[i] = Inventory[j];
				Inventory[j] = temp;
			}
}

void WriteInventorytoFiles() {}

/*void TopBuyers(vector <Customer> & List) {
	for (int a = 0; a < List.size(); a++)


}*/

// This function will compare the customer purchases to my objects of inventory. 
void UpdateInventory(vector <Item> & Inventory, vector <Customer> & List) {

	vector <Item> UpdatedInventory;
	// Sets the product to in stock
	bool stock = true;

	// Nested to loop through each inventory item
	for (int i = 0; i <= Inventory.size() - 1; i++) {

		// The following checks through all the orders to see if any match a current inventory item
		
		for (int j = 0; j <= List.size() - 1; j++) {
			if (Inventory[i].getCategory() == List[j].getCategory() && Inventory[i].getBrand() == List[j].getBrand()
				&& Inventory[i].getType() == List[j].getIname() && Inventory[i].getColor() == List[j].getColor())
			{
				// If an inventory item matches a customer purchase, the stock is now false. 
				stock = false;
			}
			// else do nothing
			else {
			}

		}
		// If the loop finishes and the stock is not false, then the item is still in stock. 
		if (stock != false) {
			// The instock item is placed into a new Updated inventory vector. 
			UpdatedInventory.push_back(Inventory[i]);
		}
		// Reinitializing stock equal to true, because we want the nested loop above to be proved false otherwise the item is still in stock. 
		stock = true;
	}
	for (int a = 0; a <= UpdatedInventory.size() - 1; a++) {
		cout << UpdatedInventory[a].getCategory() << " " << UpdatedInventory[a].getBrand() << " " << UpdatedInventory[a].getType() << " "
			<< UpdatedInventory[a].getColor() << " " << UpdatedInventory[a].getPrice() << endl;
	}
}

void TotalProfit(vector <Item> & Inventory, vector <Customer> & List) {}

/*void PrintUpdate(vector <Item> & UpdatedInventory) {
	for (int i = 0; i <= UpdatedInventory.size(); i++)
		cout << UpdatedInventory[i].getCategory() << " " << UpdatedInventory[i].getBrand() << " " << UpdatedInventory[i].getType() << " "
		<< UpdatedInventory[i].getColor() << " " << UpdatedInventory[i].getPrice() << endl;

}*/

int main()
{
	vector <Item> It;

	fillInventory(It);
	SortInventory(It);
	PrintInventory(It);

	vector <Customer> Itt;

	FillCustomer(Itt);
	PrintCustomer(Itt);

	UpdateInventory(It, Itt);

	return 0;
}

