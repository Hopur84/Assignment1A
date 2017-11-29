#include "Order.h"



ostream& operator <<(ostream& out, const Order& order)
{
    out << "Customer: " << order.customer << endl;
    out << "Crust: " << order.crust << endl << "Toppings:";
    for(int i = 0; i < 10; i++)
    {
        out << " " << order.toppings[i];
    }
    out << "price: " << order.price << endl;
}


Order::Order()
{
    crust = "Classic";
    price = 1000;
    Size = 1;
}

void Order::set_size()
{
    int input;
    bool stop = false;

    while(stop == false)
    {
        cout << "0. Cancel" << endl << "1. Large" << endl << "2. mid" << endl << "3. small" << endl;
        cin >> input;
        switch(input)
    {
        case 0:
            stop = true;
            break;
        case 1:
            Size = 2;
            stop = true;
            break;
        case 2:
            Size = 1;
            stop = true;
            break;
        case 3:
            Size = 0.5;
            stop = true;
        default:

            break;
        }
    }
}

void Order::customer_order()
{
    cout << "Customer name: ";
    cin >> customer;
}

void Order::pick_crust()
{

    ifstream fin;
    fin.open("crust.txt");
    string str;

    int input = 0;
    cout << "0. Cancel" << endl;
    for(int i = 0; i<4; i++)
    {
        getline(fin, str);
        topping_list[i] = str;
        cout << i+1 << "." << str << endl;
    }
    cout << endl;

    cin >> input;

    if(input !=0)
    {
    crust = topping_list[input-1];
    }
    else{}
    fin.close();

}

void Order::pick_topping()
{
    ifstream fin;
    string str;
    int input;
    int number = 0;
    bool stop = false;

    while(stop == false)
    {
        cout << "press '0' to go back" << endl << endl << "1.Meats: " << 150*Size << "kr"
             << endl << "2.Greens: " << 100*Size << "Kr" << endl << "3.cheeses: " << 200*Size << "kr"
             << endl << "4.sauces and spices: " << 120*Size << "kr" << endl;
        cin >> input;
        switch(input)
        {
        case 1:
            fin.open("meats.txt", ios::app);
            if(fin.is_open())
            {
                cout << "0. Cancel" << endl;
                for(int i = 0; i < 7; i++)
                {
                    if(!fin.eof())
                    {
                        cout << i+1 << ".";
                        getline(fin, str);
                        topping_list[i] = str;
                        cout << str << endl;
                    }
                }
                cout << endl;
                cin >> input;
                if(input == 0)
                {
                    pick_topping();
                }
                else
                {
                    price+= 150*Size;
                }
                toppings[number] = topping_list[input-1];
            }
            fin.close();
            break;
        case 2:
            fin.open("greens.txt", ios::app);
            if(fin.is_open())
            {
                cout << "0. Cancel" << endl;
                for(int i = 0; i < 7; i++)
                {
                    if(!fin.eof())
                    {
                        cout << i+1 << ".";
                        getline(fin, str);
                        topping_list[i] = str;
                        cout << str << endl;
                    }
                }
                cout << endl;
                cin >> input;
                if(input == 0)
                {
                    pick_topping();
                }
                else
                {
                    price+=100*Size;
                }
                toppings[number] = topping_list[input-1];
            }
            fin.close();
            break;
        case 3:
            fin.open("cheeses.txt", ios::app);
            if(fin.is_open())
            {
                cout << "0. Cancel" << endl;
                for(int i = 0; i < 4; i++)
                {
                    if(!fin.eof())
                    {
                        cout << i+1 << ".";
                        getline(fin, str);
                        topping_list[i] = str;
                        cout << str << endl;
                    }
                }
                cout << endl;

                cin >> input;

                if(input == 0)
                {
                    pick_topping();
                }
                else
                {
                    price+=200*Size;
                }
                toppings[number] = topping_list[input-1];
            }
            fin.close();
            break;
        case 4:
            fin.open("sauces_&_spices.txt", ios::app);
            if(fin.is_open())
            {
                cout << "0. Cancel" << endl;
                for(int i = 0; i < 7; i++)
                {
                    if(!fin.eof())
                    {
                        cout << i+1 << ".";
                        getline(fin, str);
                        topping_list[i] = str;
                        cout << str << endl;
                    }
                }
                cout << endl;
                cin >> input;
                if(input == 0)
                {
                    pick_topping();
                }
                else
                {
                    price+=120*Size;
                }
                toppings[number] = topping_list[input-1];
            }
            fin.close();
            break;
        case 0 :
            stop = true;
            break;
        default:
            break;
        }
        number++;
    }
}


void Order::send_order()
{
    fstream fout;
    cout << endl << endl << endl << "Crust: " << crust << endl << "Toppings:";
    for(int i = 0; i < 10; i++)
    {
        cout << " " << toppings[i];
    }
    cout << endl << "Price: " << price;

}
