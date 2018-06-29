#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <iostream>
using namespace std;

class Customer
{
public:
	Customer();
	Customer(string a, string b, string c, string d, string e, string f, string g, int h);
	string getFName();
	string getLName();
	string getBrand();
	string getColor();
	string getEmail();
	string getCategory();
	string getIname();
	int getSaleprice();
	static void setIDPool(int ID);
	int getID();

private:
	string fname;
	string lname;
	string email;
	string category;
	string brand;
	string iname;
	string color;
	int saleprice;
	int ID;
	static int IDPool;
	int profit;
};
#endif
