#pragma once
#include <iostream>
#include "product.h"
#include "factory.h"

class Menu
{
private:
	vector<shared_ptr<Product>> products;
public:
	 Menu() {} 

	~Menu() {}
	
	void addProduct(shared_ptr<Product> product)
	{
		products.push_back(move(product));
	}
	const vector<shared_ptr<Product>>& getProducts()
	{
		return products;
	}
	void displayMenu(Menu& menu)
	{
		cout << "|------------------------------------------|" << endl;
		cout << "|                   Μενώ:                  |" << endl;
		cout << "|------------------------------------------|" << endl;

		auto& products = menu.getProducts();

		for (int a = 0; a < products.size(); a++)
		{
			products[a]->display(a + 1);
		}
		cout << "|------------------------------------------|" << endl;
	}
};

Espresso EspressoFactory;
Americano AmericanoFactory;
Latte LatteFactory;
Cappucino CappucinoFactory;
Irish_Coffee Irish_CoffeeFactory;

Tiramisu TiramisuFactory;
Cake CakeFactory;
Mini_Eclairs Mini_EclairsFactory;

auto espresso = EspressoFactory.createProduct();
auto americano = AmericanoFactory.createProduct();
auto latte = LatteFactory.createProduct();
auto cappucino = CappucinoFactory.createProduct();
auto irish_coffe = Irish_CoffeeFactory.createProduct();

auto tiramisu = TiramisuFactory.createProduct();
auto cake = CakeFactory.createProduct();
auto mini_eclairs = Mini_EclairsFactory.createProduct();

