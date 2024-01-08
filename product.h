#pragma once
using namespace std;

class Product
{
public:
	string name, volume;
	double price;

	Product(string n, string v, double p) : name(n), volume(v), price(p) {}

	~Product() {}

	void display(int productNumber) const
	{
		cout << "| " << productNumber << ")  " << name << volume << " " << price << "���.|" << endl;
	}

	int getProductPrice() const
	{
		return price;
	}
};