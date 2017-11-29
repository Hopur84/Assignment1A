#include <iostream>
#include <fstream>
#include "Order.h"
using namespace std;

int main()
{
    Order order;
    int input;
    ofstream fout;
    bool process = false;

    order.customer_order();
    while(process == false)
{
    cout << "1. pick a crust" << endl << "2. Set size" << endl << "3. pick topping" << endl << "4. Process order" << endl;
    cin >> input;

    switch(input)
    {
    case 1:
        order.pick_crust();
        break;
    case 2:
        order.set_size();
        break;
    case 3:
        order.pick_topping();
        break;
    case 4:
        fout.open("orders.txt", ios::app);
        fout << order;
        fout.close();
        process = true;
        break;
    default:
        break;

    }
}
order.send_order();


    return 0;
}
