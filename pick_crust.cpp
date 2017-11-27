#include <fstream>
#include <iostream>

using namespace std;

    void pick_crust()
    {
    
    ifstream fin;
    fin.open("botn.txt");
    string str;
    
    string crust;
    
    int input = 0;
    
    for(int i = 0; i<4; i++)
    {
        getline(fin, str);
        cout << i+1 << "." << str << endl;
    }
    cout << endl;
    cout << "Choose crust(1-4): ";
    cin >> input;
    
    switch (input)
    {
        case 1: crust = "classic";
            break;
        case 2: crust = "Italian";
            break;
        case 3: crust = "Thin crust";
            break;
        case 4: crust = "Deep dish";
            break;
    }
    fin.close();
    
}
