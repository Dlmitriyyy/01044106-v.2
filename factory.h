#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include "product.h"

using namespace std;

class Factory
{
public:
	virtual shared_ptr<Product> createProduct() = 0;
	virtual ~Factory() {};
};

class Espresso : public Factory
{
public:
	shared_ptr<Product> createProduct() override
	{
		return make_shared<Product>(" Еспресо", "             | 30 мл.|", 25);
	}
};

class Americano : public Factory
{
public:
	shared_ptr<Product> createProduct() override
	{
		return make_shared<Product>(" Амерікано", "           |150 мл.|", 35);
	}
};

class Latte : public Factory
{
public:
	shared_ptr<Product> createProduct() override
	{
		return make_shared<Product>(" Латте", "               |240 мл.|", 40);
	}
};

class Cappucino : public Factory
{
public:
	shared_ptr<Product> createProduct() override
	{
		return make_shared<Product>(" Капучіно", "            |150 мл.|", 37);
	}
};


class Irish_Coffee : public Factory
{
public:
	shared_ptr<Product> createProduct() override
	{
		return make_shared<Product>(" Ірландский віскі", "    |180 мл.|", 45);
	}
};

class Tiramisu : public Factory
{
public:
	shared_ptr<Product> createProduct() override
	{
		return make_shared<Product>(" Тірамісу", "            |150 гр.|", 65);
	}
};

class Cake : public Factory
{
public:
	shared_ptr<Product> createProduct() override
	{
		return make_shared<Product>(" Кекс", "                | 70 гр.|", 23);
	}
};

class Mini_Eclairs : public Factory
{
public:
	shared_ptr<Product> createProduct() override
	{
		return make_shared<Product>(" Міні еклери", "         | 35 гр.|", 18);
	}
};
