#ifndef ORDER_H
#define ORDER_H
#include <iostream>
#include <fstream>
using namespace std;

class Order
{
    public:

        void pick_topping();
        void current_order();
        void pick_crust();
        void customer_order();




    protected:

    private:
        string customer;
        string crust;
        string topping_list[10];
        string toppings[10];
        int price;
};

#endif // ORDER_H
