#include<iostream>
#include<fstream>
using namespace std;


//creating class for acc holder//
class BankAccount{

//'acc_number' for existing account's details and 'number' for inputed details//
private:
    int acc_number;
    string acc_name;
    double acc_balance;

public:
    input_verify();
    create_acc(int number,string name,double initialbalance);
    deposit(double amount);
    withdraw(double amount);
    showbalance();

};

/*void BankAccount::input_verify()
{
    int number;
    string name;

    cout<<"Enter your acc number: ";
    cin>>number;
    cout<<"Enter your name: ";
    cin.ignore();
    getline(cin,name);

    //verifying data//
    ifstream acc_File("Bank accounts.txt");

}*/

int main()
{
    int choice;
    while(true)
    {
        cout<<endl<<"---------Bank Management system---------"<<endl;
        cout<<"1. Create Bank acc\n2. Deposit\n3. Withdraw\n4. Check Balance\n5. Exit\n";
        cout<<endl<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 1:
            {

              break;
            }
            case 2:
            {

                break;
            }
            case 3:
                {
                    break;
                }
            case 4:
                {
                    break;
                }
            case 5:
                {
                   return 0;
                }
            default:
                {
                    cout<<"enter valid choice..!";
                }
        }
    }

    return 0;
}
