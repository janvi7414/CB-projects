#include<iostream>
#include<fstream>
using namespace std;

int main()
{

    ofstream acc_file_clr("Bank accounts.txt",ios::trunc);

    acc_file_clr.close();
    return 0;
}
