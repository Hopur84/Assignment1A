#ifndef ORDER_H
#define ORDER_H
#include <iostream>
#include <fstream>
using namespace std;

class Order
{
    public:

        Order();
        void pick_topping();
        void send_order();
        void pick_crust();
        void customer_order();
        friend ostream& operator <<(ostream& out, const Order& order);
        void set_size();





    protected:

    private:
        double Size;
        string location;
        string customer;
        string crust;
        string topping_list[10];
        string toppings[10];
        int price;

};

#endif // ORDER_H
