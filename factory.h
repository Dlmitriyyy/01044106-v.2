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
		return make_shared<Product>(" �������", "             | 30 ��.|", 25);
	}
};

class Americano : public Factory
{
public:
	shared_ptr<Product> createProduct() override
	{
		return make_shared<Product>(" ��������", "           |150 ��.|", 35);
	}
};

class Latte : public Factory
{
public:
	shared_ptr<Product> createProduct() override
	{
		return make_shared<Product>(" �����", "               |240 ��.|", 40);
	}
};

class Cappucino : public Factory
{
public:
	shared_ptr<Product> createProduct() override
	{
		return make_shared<Product>(" ��������", "            |150 ��.|", 37);
	}
};


class Irish_Coffee : public Factory
{
public:
	shared_ptr<Product> createProduct() override
	{
		return make_shared<Product>(" ���������� ���", "    |180 ��.|", 45);
	}
};

class Tiramisu : public Factory
{
public:
	shared_ptr<Product> createProduct() override
	{
		return make_shared<Product>(" ҳ�����", "            |150 ��.|", 65);
	}
};

class Cake : public Factory
{
public:
	shared_ptr<Product> createProduct() override
	{
		return make_shared<Product>(" ����", "                | 70 ��.|", 23);
	}
};

class Mini_Eclairs : public Factory
{
public:
	shared_ptr<Product> createProduct() override
	{
		return make_shared<Product>(" ̳� ������", "         | 35 ��.|", 18);
	}
};
