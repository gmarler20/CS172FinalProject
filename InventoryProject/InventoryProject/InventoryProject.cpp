// FinalProject.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Item.h"
#include "Customer.h"
using namespace std;


// This function was made to output a line to make the program look cleaner as it movers through the different functions.
// it is called often throughout the program to seperate when something major happens. 
void Break() {
	cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
}

// Basic header function to explain what this program does. 
void Header() {

	cout << "This is an inventory system for a sporting goods store." << endl;
	cout << "This system will take in a list of inventory from a store in any order" << endl;
	cout << "and organize it from lowest to highest cost of goods. " << endl;
	cout << "This program will also sort the inventory by category and output " << endl;
	cout << "an inventory list for each different sporting category. " << endl;
	cout << "The sports currently supported are Football, Basketball, Baseball, and Soccer " << endl;
	Break();
}



// This function fills an inventory vector with a list of products and their attributes.
// This function can take info from whatever file the user inputs as long as it matches the 
// format accepted by the program. 
void fillInventory(vector <Item>& Inventory) {

	string category1;
	string brand1;
	string type1;
	string color1;
	int price1;

	cout << "Enter the name of the inventory text file that you would like to sort: ";
	
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


// Took suggestions from your email about my exam 2, was able to apply it to my project and pull out each of the
// loops and put it into a function. This function will work for all sports in my inventory list. 
void WriteInventorytoFile(string filename, vector <Item> & Inventory) {
	ofstream output;

	output.open(filename+".txt");
	
	for (int i = 0; i < Inventory.size(); i++) {
		if(Inventory[i].getCategory() == filename)
			output << Inventory[i].getCategory() << " " << Inventory[i].getBrand() << " " << Inventory[i].getType()
			<< " " << Inventory[i].getColor() << " " << Inventory[i].getPrice() << endl;
	}

	cout << filename << ".txt has been created and stored in the project folder " << endl;
	cout << "You can now view your current inventory for " << filename << " in " << filename << ".txt" << endl;
	
	output.close();
}

// This function was not used in my main program, but was used to easily check if my fillVector function was working properly. 
/*void PrintInventory(vector <Item>& Inventory) {
	for (int i = 0; i < Inventory.size(); i++) {
		cout << Inventory[i].getCategory() << " " << Inventory[i].getBrand() << " " << Inventory[i].getType()
			<< " " << Inventory[i].getColor() << " " << Inventory[i].getPrice() << endl;

	}
}*/

// This function fills in a customer vector with all of the customer information. It can
// read from any customer file that matches the format. 
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
		return;
	}

	while (input1 >> fname >> lname >> email >> category >> brand >> iname >> color >> saleprice) {
		Customer newList(fname, lname , email , category , brand , iname , color , saleprice);
		List.push_back(newList);
	}
	cout << "Customer order list has been created " << endl;

}

// This function was not used in my final program, and was only used to test. 
/*void PrintCustomer(vector <Customer> & List) {
	for (int a = 0; a < List.size(); a++) {
		cout << List[a].getID() << " " << List[a].getFName() << " " << List[a].getLName() << " " << List[a].getEmail() << " "
			<< List[a].getCategory() << " " << List[a].getBrand() << " " << List[a].getIname() << " " << List[a].getColor() << " "
			<< List[a].getSaleprice() << endl;
	}
}*/


// This function sorts the inventory in ascending order by the cost of the item to the company.
void SortInventory(vector <Item> & Inventory) {
	Item temp;
	for (int i = 0; i <= Inventory.size() - 1; i++)

		for (int j = i + 1; j <= Inventory.size() - 1; j++)
			if (Inventory[i].getPrice() > Inventory[j].getPrice()) {
				temp = Inventory[i];
				Inventory[i] = Inventory[j];
				Inventory[j] = temp;
			}

	cout << "Inventory has been successfully sorted in ascending order. " << endl;
	
}


// This function will allow the marketing team to have easy access
// to a list of the first and last name, as well as the email address
// of the customers who have made multiple orders with us in a month. 
// This will allow us to contact these customers who purchase multiple items from us 
// with special promotional offers as we know they are loyal to the brand and want to buy
// a lot of items from us. 
void BulkBuyers(vector <Customer> & List) {
	ofstream output;
	
	output.open("BulkBuyers.txt");

	for (int a = 0; a < List.size(); a++)
	{
		
		for (int j = a + 1; j < List.size(); j++) {
			// This loop checks through the list of customer orders for duplicates. 
			// Because it is nested, the a loop runs through one item j times, 
			// and compares. If a duplicate is found, it gets output to BulkBuyers.txt. 
			// If a duplicate is not found, nothing happens. 
			if (List[a].getFName() == List[j].getFName() && List[a].getLName() == List[j].getLName() && List[a].getEmail() == List[j].getEmail())
			{
				output << List[a].getFName() << " " << List[a].getLName() << " " << List[a].getEmail() << endl;

			}
		}
	}
	output.close();
	cout << "List of our bulk buyers has been created and stored in the project folder via filename BulkBuyers.txt " << endl;

}

// Function called that allows the Updated Inventory to be written to different files. 
	void UpdatedInventorytoFile(string filename, vector <Item> & UpdatedInventory) {
		ofstream output;

		output.open("Updated" + filename + ".txt");

	
		for (int i = 0; i < UpdatedInventory.size(); i++) {
			// If the category of the updatedinventory is equal to the filename that is input
			// output all the informations for the inventory to the filename.txt
			if (UpdatedInventory[i].getCategory() == filename)
				output << UpdatedInventory[i].getCategory() << " " << UpdatedInventory[i].getBrand() << " "
				<< UpdatedInventory[i].getType() << " " << UpdatedInventory[i].getColor() << " " << UpdatedInventory[i].getPrice() << endl;
		}
		output.close();
		cout << "Updated" << filename << ".txt has been created and stored in the project folder " << endl;
		cout << "You can now view your updated inventory for " << filename << " in " <<"Updated" << filename << ".txt" << endl;
		
	}
// This function will compare the customer purchases to my objects of inventory. 
// This function will also track the total profit from each customers order. 
void UpdateInventoryandProfit(vector <Item> & Inventory, vector <Customer> & List , vector <Item> UpdatedInventory) {

	
	// Sets the product to in stock
	bool stock = true;
int temp = 0;
int profit = 0;
int saleamount = 0;
int cogs; // Cost of goods sold
	// Nested to loop through each inventory item
	for (int i = 0; i <= Inventory.size() - 1; i++) { ;
		// The following checks through all the orders to see if any match a current inventory item

		for (int j = 0; j <= List.size() - 1; j++) {
			if (Inventory[i].getCategory() == List[j].getCategory() && Inventory[i].getBrand() == List[j].getBrand()
				&& Inventory[i].getType() == List[j].getIname() && Inventory[i].getColor() == List[j].getColor())
			{
				// If an inventory item matches a customer purchase, the stock is now false. 
				stock = false;
				// Set amount sold to the sold item from the list
				saleamount = List[j].getSaleprice();
				// Take how much the item costs to us from our inventory file
				 cogs = Inventory[i].getPrice();
				 // Profit is equal to our sale amount minus our Cost of goods sold, and then add onto profit throughout the loop. 
				 profit += saleamount - cogs;
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
		// Reinitializing stock equal to true, because we want the nested loop 
		//above to be proved false otherwise the item is still in stock. 
		stock = true;
	}
	

	cout << "The Inventory list and customer order list have been compared. The total profit from this list of sales is " << profit << endl;
	Break();

	// Calling my function that writes the updated inventory to new files displaying the inventory
	// after it is compared to the customer purchses. 
	 UpdatedInventorytoFile("Football",  UpdatedInventory);
	 Break();
	 UpdatedInventorytoFile("Basketball", UpdatedInventory);
	 Break();
	 UpdatedInventorytoFile("Soccer", UpdatedInventory);
	 Break();
	 UpdatedInventorytoFile("Baseball", UpdatedInventory);

}


// This function allows the company to restock their inventory and buy more product. 
// This function will read in two files. The first one is a file containing 
// the amount of cash that the company currently has available to spend. This 
// can easily be modified by the user and is named AvailableCash.txt.
// The second file reads in a new inventory file of items that the company 
// wants to purchase more of. 
void BuyInventory(vector <Item> & UpdatedInventory)
{
	string category1;
	string brand1;
	string type1;
	string color1;
	int price1;
	int cash = 0;
	int cash1 = 0;
	int cashtotal = 1000;
	int initialcash;

	fstream input("AvailableCash.txt");

	if (input.fail()) {
		cout << "Invalid filename ";
			cash = 0;
	}

	// Set cash = to the amount that is read in from the file
	while (input >> cash1)
	{
		cash = cash1;
	}

	// Keep track of the initial cash amount so if the company decides not to proceed with the transaction,
	// the initial amount will still be stored and no money will be taken off the companies assets. 
	initialcash = cash;

	input.close();

	string filename;

	cout << "Enter the name of the file containing the items you would like to order more of: ";
	cin >> filename;
	cout << endl;

	// Open up the list of what the company is going to order more of. 
	fstream input2(filename +".txt");
	// Read in the file
	while (input2 >> category1 >> brand1 >> type1 >> color1 >> price1)
	{
		// This while statement subtracts the purchase price of each item the company is going to restock on
		// from the total amount of cash the company has available. 
		// Total cash is the cash minus the price of the first item. 
		// Cash is then reinitialized to the amount of cash that is left over.
		// and then it loops through until the end of the restockinventory file. 
		 cashtotal = cash - price1 ;
		 cash = cashtotal;

	}

	input2.close();

	string answer = "";

	// If the companies available balance falls to a negative number, warn the company before they decide to make the transaction.
	if (cashtotal < 0) {
		cout << "Warning: If you proceed with this transaction, The companies available cash will be negative in the amount of " << cashtotal << endl;
		cout << "Would you like to proceed with this transaction anyways? (Yes or No) ";
		cin >> answer;

		// If they want to make the transaction, let them and call the fillInventory function.
		// To complete the order, the company has to type "Yes" and then they will be prompted to type in RestockInventory
		// in order to complete the order. 
		if (answer == "Yes") {
			cout << "Enter in " << filename << " to complete the order " << endl;
			fillInventory(UpdatedInventory);
			Break();
			SortInventory(UpdatedInventory);
			Break();
			WriteInventorytoFile("Football", UpdatedInventory);
			Break();
			WriteInventorytoFile("Soccer", UpdatedInventory);
			Break();
			WriteInventorytoFile("Basketball", UpdatedInventory);
			Break();
			WriteInventorytoFile("Baseball", UpdatedInventory);
		}

		// If the company does not want to make the transaction, tell them the purchase will not be made. 
		if (answer == "No")
		{
			cout << "Inventory purchases will not be made. ";
			// Show them their original cash balance since no transaction was made. 
			cout << "Cash balance is still " << initialcash;
		}
	}

	// Provide no warning if the companies available cash is positive.
	// Proceed normally by placing the order and updating the inventory, 
	// as well as showing the company how much they have left in their cash balance. 
	if (cashtotal > 0)
	{
		fillInventory(UpdatedInventory);
		cout << "The current cash balance is " << cashtotal;
	Break();
	SortInventory(UpdatedInventory);
	Break();
	WriteInventorytoFile("Football", UpdatedInventory);
	Break();
	WriteInventorytoFile("Soccer", UpdatedInventory);
	Break();
	WriteInventorytoFile("Basketball", UpdatedInventory);
	Break();
	WriteInventorytoFile("Baseball", UpdatedInventory);
	}

	


}

/*void PrintUpdate(vector <Item> & UpdatedInventory) {
	for (int i = 0; i <= UpdatedInventory.size(); i++)
		cout << UpdatedInventory[i].getCategory() << " " << UpdatedInventory[i].getBrand() << " " << UpdatedInventory[i].getType() << " "
		<< UpdatedInventory[i].getColor() << " " << UpdatedInventory[i].getPrice() << endl;

}*/


// Test program in main that runs all my important functions. 
int main()
{

	Header();

	vector <Item> InitialInventory;

	fillInventory(InitialInventory);
	Break();
	
	SortInventory(InitialInventory);
	Break();
	WriteInventorytoFile("Football", InitialInventory);
	Break();
	WriteInventorytoFile("Soccer", InitialInventory);
	Break();
	WriteInventorytoFile("Baseball", InitialInventory);
	Break();
	WriteInventorytoFile("Basketball", InitialInventory);
	Break();

	vector <Customer> InitialCustomer;

	FillCustomer(InitialCustomer);
	Break();
	BulkBuyers(InitialCustomer);
	Break();

	vector <Item> Update;

	UpdateInventoryandProfit(InitialInventory, InitialCustomer, Update);
	Break();

	BuyInventory(InitialInventory);

	return 0;
}

