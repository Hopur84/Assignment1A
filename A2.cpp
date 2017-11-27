#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string str ;
    ofstream fout;
    fout.open("A2.txt", ios::app);
    int check = 1;

    while(check == 1)
    {
        getline(cin, str);
        if(str[0] == '\\')
        {
            check = 0;
        }
        else
        {
            fout << str << endl;
        }

    }
    fout.close();
    return 0;
}

//hehe
