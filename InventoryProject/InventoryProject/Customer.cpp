#include "Customer.h"

Customer::Customer()
{
	fname = "";
	lname = "";
	email = "";
	category = "";
	brand = "";
	iname = "";
	color = "";
	saleprice = 0;
	ID = 0;
}

Customer::Customer(string a, string b, string c, string d, string e, string f, string g, int h) {
	fname = a;
	lname = b;
	email = c;
	category = d;
	brand = e;
	iname = f;
	color = g;
	saleprice = h;

	ID = IDPool++;

}

int Customer::IDPool = 0;

// Created with help of Chapter 04B video about static member variables
  void Customer::setIDPool(int ID) {
	IDPool = ID;
 }

string Customer::getFName() {
	return fname;
}

string Customer::getLName() {
	return lname;
}
string Customer::getBrand() {
	return brand;
}

string Customer::getColor() {
	return color;
}
string Customer::getEmail() {
	return email;
}
string Customer::getCategory() {
	return category;
}


string Customer::getIname() {
	return iname;
}
int Customer::getSaleprice() {
	return saleprice;

}
int Customer::getID() {
	return ID;
}