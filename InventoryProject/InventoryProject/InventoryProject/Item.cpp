#include "Item.h"
#include <iostream>

Item::Item()
{
	Category = "";
	Brand = "";
	Type = "";
	Color = "";
	Price = 0;
}

Item::Item(string a, string b, string c, string d, int e) {
	Category = a;
	Brand = b;
	Type = c;
	Color = d;
	Price = e;
}

string Item::getCategory() {
	return Category;
}

string Item::getBrand() {
	return Brand;
}

string Item::getType() {
	return Type;
}

string Item::getColor() {
	return Color;
}

int Item::getPrice() {
	return Price;
}

