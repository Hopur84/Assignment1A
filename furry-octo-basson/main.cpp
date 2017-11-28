#include <iostream>
#include <fstream>
#include "Order.h"
using namespace std;

int main()
{
    Order order1;
    int input;
    ofstream fout;
    bool process = false;

    order1.customer_order();
    while(process == false)
{
    cout << "1. pick a crust" << endl << "2. pick toppings" << endl << "3. Process order" << endl;
    cin >> input;



    if(input == 1)
    {
        order1.pick_crust();
    }
    else if (input == 2)
    {
        order1.pick_topping();
    }
    else if(input == 3)
    {
    process = true;
    }
    else
    {
        cout << "error";
    }
}
    order1.current_order();


    return 0;
}
