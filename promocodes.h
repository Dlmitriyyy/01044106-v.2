#pragma once
#include <string>
#include "order.h"

class Promocodes
{
public:
     Promocodes() {}

    virtual void enterPromocode(Order& order, string& promocode) = 0;
    virtual ~Promocodes() {}
};

class NewYearPromocode : public Promocodes
{
public:
     NewYearPromocode() {}
     
     ~NewYearPromocode() {}

    void enterPromocode(Order& order, string& promocode) override
    {
        if (promocode == "NewYear2024")
        {
            cout << "Застосована знижка 15%" << endl;
            order.promoPrice();
        }
        else
        {
            order.promoActive = false;
            cout << "Помилка. Такого промокоду не існує." << endl;
        }
    }
};
