#include "Order.h"


void Order::customer_order()
{
    cout << "Customer name:"; cin >> customer;
}

void Order::pick_crust()
{

    ifstream fin;
    fin.open("crust.txt");
    string str;

    int input = 0;

    for(int i = 0; i<4; i++)
    {
        getline(fin, str);
        topping_list[i] = str;
        cout << i+1 << "." << str << endl;
    }
    cout << endl;

    cin >> input;
    crust = topping_list[input-1];

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
        cout << "press 'Q' to go back" << endl << endl << "1.Meats" << endl << "2.Greens" << endl << "3.cheeses" << endl << "4.sauces and spices" << endl;
        cin >> input;
        switch(input)
        {
        case 1:
            fin.open("meats.txt", ios::app);
            if(fin.is_open())
            {
                cout << "press 'Q' to go back" << endl;
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
                if(input == 113)
                {
                    pick_topping();
                }
                toppings[number] = topping_list[input-1];
            }
            fin.close();
            break;
        case 2:
            fin.open("greens.txt", ios::app);
            if(fin.is_open())
            {
                cout << "press 'Q' to go back" << endl;
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
                if(input == 113)
                {
                    pick_topping();
                }
                toppings[number] = topping_list[input-1];
            }
            fin.close();
            break;
        case 3:
            fin.open("cheeses.txt", ios::app);
            if(fin.is_open())
            {
                cout << "press 'Q' to go back" << endl;
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

                if(input == 113)
                {
                    pick_topping();
                }
                toppings[number] = topping_list[input-1];
            }
            fin.close();
            break;
        case 4:
            fin.open("sauces_&_spices.txt", ios::app);
            if(fin.is_open())
            {
                cout << "press 'Q' to go back" << endl;
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
                if(input == 113)
                {
                    pick_topping();
                }
                toppings[number] = topping_list[input-1];
            }
            fin.close();
            break;
        case 113 :
            stop = true;
            break;
        default:
            cout << "error";
            break;
        }
        number++;
    }
}


void Order::current_order()
{
    cout << endl << endl << endl << "Crust: " << crust << endl << "Toppings:";
    for(int i = 0; i < 10; i++)
    {
        cout << " " << toppings[i];
    }
    cout << endl << "Price: ";
}
