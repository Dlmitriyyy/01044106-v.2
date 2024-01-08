#pragma once
#include "promocodes.h"
#include "client.h"
using namespace std;

class Order
{
private:
	friend class OrderHistory;
	vector<shared_ptr<Product>> products;
	double totalPrice, promoPrices;
	string clientName;
public:
	bool promoActive;
	
	Order(string& clientName) : clientName(clientName), promoActive(false), totalPrice(0.0), promoPrices(0.0) {}
	
	Order() {}

	~Order() {}
	
	void addProduct(shared_ptr<Product> product)
	{
		products.push_back(move(product)); 
	}
	const vector<shared_ptr<Product>>& getProducts()
	{
		return products;
	}

	void displayOrder()
	{	
		cout << "|------------------------------------------|" << endl;
		cout << "|             ����� ����������:           |" << endl;
		cout << "|------------------------------------------|" << endl;
		for (int a = 0; a < products.size(); a++)
		{
			products[a]->display(a + 1);
		}
		cout << "|------------------------------------------|" << endl;
		cout << " ����� ����������: " << totalPrice << " ���." << endl;
		cout << "|------------------------------------------|" << endl;
	}

	double OrderPrice()
	{
		for (const auto& product : products)
		{
			totalPrice += product->getProductPrice();
		}
		return 0;
	}

	double getTotalPrice()
	{
		return totalPrice;
	}

	double promoPrice()
	{
		promoActive = true;
	    promoPrices = (totalPrice * 85) / 100;
		cout << "����� � �������: " << promoPrices << " ���." << endl;
		return promoActive;
	}
	
	double getPromoPrice()
	{
		return promoPrices;
	}
	
	string setClientName()
	{
		cout << "������ ���� ��'�: ";
		cin >> clientName;
		return clientName;
	}
	string getClientName()
	{
		return clientName;
	}

};

class OrderHistory
{
private:
	friend class Order;
	friend class Client;
	Client* client;
	vector<Order> ordershistory;
	vector<Client> clientNames;
public:
	 OrderHistory() {}

	~OrderHistory() {}

	void addOrder(Order& orders)
	{
		
		ordershistory.emplace_back(orders);
	}
	void statusOrder()
	{
		if (ordershistory.empty())
		{
			cout << "�� �� ����� �� ���������. ������� ��������� ���������." << endl;
		}
		else
		{
			
		}
	}
	void displayHistory()
	{
		if (ordershistory.empty())
		{
			cout << "�� �� ����� �� ���������. ������ ��������� �������." << endl;
		}
		else
		{
			cout << "������ ���������: " << endl;
			for (auto& order : ordershistory)
			{
					if (order.promoActive == true)
					{
						cout << "|------------------------------------------|" << endl;
						cout << " ���������� �볺��� " << order.getClientName() << ":" << endl;
						order.displayOrder();
						cout << " ";
						order.promoPrice();
						cout << "|------------------------------------------|" << endl;
					}

					if (order.promoActive == false)
					{
						cout << "|------------------------------------------|" << endl;
						cout << " ���������� �볺��� " << order.getClientName() << ":" << endl;
						order.displayOrder();
					}
				cout << endl;
			}
		} 
	}
};
