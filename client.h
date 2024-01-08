#pragma once
#include <thread>
#include <chrono>
#include "promocodes.h"
#include "order.h"

class OrderHistory;
class Client;

OrderHistory ordersHistory;
Order orders;
Promocodes* promoChain;

class Mediator
{
public:
     Mediator() {}

    ~Mediator() {}

    virtual void orderPlaced(Client* client, Order* order) = 0;
    virtual void orderStatus1(Client* client, Order* order) = 0;
    virtual void orderStatus2(Client* client, Order* order) = 0;
    virtual void orderStatus3(Client* client, Order* order) = 0;
};

class Client
{
private:
    friend class OrderHistory;
    OrderHistory& history;
    Promocodes* promoChain;
    Mediator* mediator;
    string name;
public:
     Client(Mediator* mediator, OrderHistory& history, Promocodes* promoChain, string& name) : mediator(mediator), history(history), promoChain(promoChain), name(name) {}

    ~Client() {}

    double placeOrder(Order* order)
    {
        Order* currentOrder = order;
        double totalPrice = 0.0;
        string input, choice, promocode;
        bool addToOrder = false;

        do
        {
            if (!addToOrder)
            {
                do
                {
                    cout << "��� ���������� ������ ����� ������: " << endl;
                    cin >> input;

                    if (input == "Confirm")
                    {
                        cout << "���������� ���������." << endl;
                        order->displayOrder();
                        break;
                    }

                    try
                    {
                        int productNumber = stoi(input);

                        if (productNumber >= 1 && productNumber <= 8)
                        {
                            switch (productNumber)
                            {
                            case 1:
                                order->addProduct(espresso);
                                break;
                            case 2:
                                order->addProduct(americano);
                                break;
                            case 3:
                                order->addProduct(latte);
                                break;
                            case 4:
                                order->addProduct(cappucino);
                                break;
                            case 5:
                                order->addProduct(irish_coffe);
                                break;
                            case 6:
                                order->addProduct(tiramisu);
                                break;
                            case 7:
                                order->addProduct(cake);
                                break;
                            case 8:
                                order->addProduct(mini_eclairs);
                                break;
                            default:
                                cout << "������������ ����� ������. ��������� �� ���." << endl;
                                addToOrder = false;
                                break;
                            }
                            addToOrder = true;
                        }

                        else
                        {
                            cout << "������������ ����� ������. ��������� �� ���." << endl;
                            addToOrder = false;
                        }
                    }
                    catch (const invalid_argument&)
                    {
                        cout << "�������, ����� ������ �� ���� ������ �����." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        addToOrder = false;
                    }
                }while(!addToOrder);
            }

            cout << "������ �������� �� ����? 'Yes'/'No'." << endl;
            cin >> choice;

            if (choice == "Yes")
            {
                addToOrder = false;
            }
            else if (choice == "No")
            {
                
                do 
                {
                    cout << "���� ��������? 'Yes'/'No'" << endl;
                    cin >> choice;

                    if (choice == "Yes")
                    {
                        cout << "������ ��������: ";
                        cin >> promocode;

                        totalPrice = order->OrderPrice();
                        order->displayOrder();

                        if (promoChain != nullptr)
                        {
                            promoChain->enterPromocode(*order, promocode);
                        }
                        mediator->orderPlaced(this, order);
                        mediator->orderStatus1(this, order);
                        mediator->orderStatus2(this, order);
                        mediator->orderStatus3(this, order);
                        
                        history.addOrder(*order);
                        break;
                    }
                    if (choice == "No")
                    {
                        totalPrice = order->OrderPrice();
                        order->displayOrder();
                        history.addOrder(*order);
                        mediator->orderPlaced(this, order);
                        mediator->orderStatus1(this, order);
                        mediator->orderStatus2(this, order);
                        mediator->orderStatus3(this, order);
                        break;
                    }
                    else
                    {
                        cout << "�������. ����������� ���." << endl;
                    }
                    
                } while (choice != "Yes" && choice != "No");
                break;
            } 
            else
            {
                cout << "������� ����������� ���." << endl;
                addToOrder = true;
            }
        } while (true);
        return totalPrice;
    }
};

class ConcreteMediator : public Mediator
{
public:
     ConcreteMediator() {}

    ~ConcreteMediator() {}

    void orderPlaced(Client* client, Order* order) override
    {
        cout << "�볺�� " << order->getClientName() << " �������� ����������" << endl;
    }
    void orderStatus1(Client* client, Order* order) override
    {
        this_thread::sleep_for(chrono::seconds(3));
        cout << "������ ���������� " << order->getClientName() << " - ���������� ��������." << endl;
    }
    void orderStatus2(Client* client, Order* order) override
    {
        this_thread::sleep_for(chrono::seconds(4));
        cout << "������ ���������� " << order->getClientName() << " - ���������� �������������." << endl;
    }
    void orderStatus3(Client* client, Order* order) override
    {
        this_thread::sleep_for(chrono::seconds(5));
        cout << "������ ���������� " << order->getClientName() << " - ���������� ����������." << endl;
    }
};