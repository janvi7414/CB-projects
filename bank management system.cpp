#include<iostream>
#include<fstream>
using namespace std;


//creating class for acc holder//
class bank_account{

//'acc_number' for existing account's details and 'number' for inputed details//
private:
    int acc_number;
    string acc_name;
    double acc_balance;
    bool flag=0;

public:
    void input();
    void setflag();
    void write_details();//to paste details in the txt file//
    create_acc(int number,string name,double initialbalance);
    deposit(double amount);
    withdraw(double amount);
    showbalance();

};


void bank_account::setflag()
{
    flag=1;
}

void bank_account::write_details()
{
    std::fstream acc_file("Bank accounts.txt",ios::in|ios::out|ios::app);

    if(!acc_file.is_open())
    {
        cerr<<"error in opening the file..!";
        return ;
    }

    acc_file.seekg(0,ios::end);
    acc_file<<endl<<acc_number<<","<<acc_name<<","<<acc_balance<<";";
    /*, to separate details of same acc and ; to separate different
    accounts details*/
    acc_file.close();
}
void bank_account::input()
{
    int entered_acc_number;
    string entered_acc_name;
    cout<<"Enter acc no.: ";
    cin>>entered_acc_number;
    cout<<"Enter name of acc holder: ";
    cin.ignore();
    getline(cin,entered_acc_name);
    if(flag)
    {
        double entered_balance;
        cout<<"Enter initial balance: ";
        cin>>entered_balance;
    }

    //assigning values to private members//
    acc_number=entered_acc_number;
    acc_name=entered_acc_name;

    write_details();

}

int main()
{
    int choice;
    while(true)
    {
        cout<<endl<<"---------Bank Management system---------"<<endl;
        cout<<"1. Create Bank acc\n2. Deposit\n3. Withdraw\n4. Check Balance\n5. Exit\n";
        cout<<endl<<"Enter your choice: ";
        cin>>choice;
        bool flag = 0;

        switch(choice){
            case 1:
            {
                bank_account obj;
                //setting flag to execute balance enquiry function for this case only//
                obj.setflag();
                obj.input();

              break;
            }
            case 2:
            {
                bank_account obj;
                obj.input();

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
