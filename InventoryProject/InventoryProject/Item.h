#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>
using namespace std;

class Item
{
public:
	Item();
	Item(string a, string b, string c, string d, int e);
	string getCategory();
	string getBrand();
	string getType();
	string getColor();
	int getPrice();

private:
	string Category;
	string Brand;
	string Type;
	string Color;
	int Price;
};

#endif

