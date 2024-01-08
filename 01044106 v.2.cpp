#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include "menu.h"
#include "client.h"
using namespace std;

int main()
{
    system("chcp 1251>nul");

    string input, promocode, clientName;

    Menu menu;
    ConcreteMediator mediator;
    OrderHistory history;
    Promocodes* promoChain = new NewYearPromocode;
    Client client(&mediator, history, promoChain, clientName);

    menu.addProduct(espresso);
    menu.addProduct(americano);
    menu.addProduct(latte);
    menu.addProduct(cappucino);
    menu.addProduct(irish_coffe);

    menu.addProduct(tiramisu);
    menu.addProduct(cake);
    menu.addProduct(mini_eclairs);

    do
    { 
        cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Для отримання меню товарів введіть 'Menu', для перегляду доступних промокодів 'Promocode', для перегляду історії заказів 'History', для завершення програми 'Exit'." << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
        cin >> input;

        if (input == "Menu")
        {
            Order order;
            order.setClientName();
            menu.displayMenu(menu);

            do 
            {
                cout << "Для оформлення замовлення введіть 'Order', для повернення в головне меню 'General'." << endl;
                cin >> input;

                if (input == "Order") 
                {
                    client.placeOrder(&order);
                    break;
                }
                else if (input == "General")
                {
                    break;
                }
                else 
                {
                    cout << "Помилка. Некоректний вибір." << endl;
                }
            } while (true);
        }
        else if (input == "Promocode")
        {
            cout << "Доступний промокод: NewYear2024, дає знижку 15% на замовлення." << endl;
        }
        else if (input == "History")
        {
            history.displayHistory();
        }
        else if (input == "Exit")
        {
            cout << "Завершення програми." << endl;
        }
        else
        {
            cout << "Помилка. Некоректний вибір." << endl;
        }
    } while (input != "Exit");
    delete promoChain;
    return 0;
}