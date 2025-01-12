#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

//uncomment to verify lines//
//creating class for acc holder//
class bank_account{

//'acc_number' for existing account's details and 'number' for inputed details//
private:
    int acc_number;
    string acc_name;
    double acc_balance;
    bool flag=0;
    int entered_acc_number;
    string entered_acc_name;
    double entered_acc_balance;
    double entered_withdraw_amt;
    double entered_deposit_amt;

public:
    void input();
    void setflag();
    bool verify();//returns 1 if details are not matched or not present in the text file//
    void write_details();//to paste details in the txt file//
    void withdraw(bool is_valid);
    void deposite(bool is_valid);
    void check_balance(bool is_valid);

};


void bank_account::setflag()
{
    flag=1;
}

void bank_account::deposite(bool is_valid)
{
    if(is_valid)
    {
        cout<<endl<<"enter amount to deposit: ";
        cin>>entered_deposit_amt;
        acc_balance=acc_balance+entered_deposit_amt;
        cout<<endl<<"amount withdrawn successfully";
        cout<<endl<<"balance: "<<acc_balance;
        return ;
    }
    cerr<<"unable to deposit an amount..!";
    return ;
}

void bank_account::withdraw(bool is_valid)
{
    if(is_valid)
    {
        cout<<endl<<"enter amount to withdraw: ";
        cin>>entered_withdraw_amt;
        acc_balance=acc_balance-entered_withdraw_amt;
        cout<<endl<<"amount withdrawn successfully";
        cout<<endl<<"balance: "<<acc_balance;
        return ;
    }
    cerr<<"unable to withdraw an amount..!";
    return ;
}

void bank_account::check_balance(bool is_valid)
{

    if(is_valid)
    {
        cout<<endl<<"balance: "<<acc_balance;
        return ;
    }
    cerr<<"unable to show balance..!";
    return ;
}

//to save details in text file//
void bank_account::write_details()
{

    //open file in write mode//
    fstream acc_file("Bank accounts.txt",ios::app);

    //check for error in opening//
    if(!acc_file.is_open())
    {
        cerr<<endl<<"error in opening the file for saving details..!";
        return ;
    }

    //setting pointer to the end of the text file by using app mode simply//
    //saving data in the next line//
    acc_file<<endl;
    //saving entered data//
    acc_file<<entered_acc_number<<","<<entered_acc_name<<","<<entered_acc_balance<<";";
    cout<<endl<<"details successfully stored in the file";

    acc_file.close();
}


bool bank_account::verify()
{
    std::fstream acc_file("Bank accounts.txt",ios::in);

    if(!acc_file.is_open())
    {
        cerr<<"error in opening the file for verification..!";
        return 1;
    }


    string line;

   while(getline(acc_file,line))
   {
       string temp;//used to extract acc no. as a string and then to convert it into int//
       stringstream ss(line);//line stringstream for accessing each line of text file//

       //HERE SEQUENCE OF EXTRACTING MEMBERS IS FIXED//

       //to extract acc number using temp string//
       getline(ss,temp,',');
       //converting string temp into int acc_number//
       acc_number=stoi(temp);
       /*to verify//
       cout<<endl<<"acc number: "<<acc_number;*/

       //to extract acc holder name//
       getline(ss,acc_name,',');
       /*to verify
       cout<<endl<<"name: "<<acc_name;*/

       //to extract acc balance using temp string//
       getline(ss,temp,',');
       //converting string temp into double acc_balance//
       acc_balance=stod(temp);
       /*to verify
       cout<<endl<<"balance: "<<acc_balance;*/


       //to check if acc no. exists in the txt file//
       if(entered_acc_number==acc_number)
       {
           //cout for case 1 only//
           if(flag)
           {
               cout<<endl<<"account already exists";
               acc_file.close();
               return 1;
           }

           //for cases other than case 1 matching acc name as well//
           if(entered_acc_name==acc_name)
           {
               cout<<endl<<"login successfull";
               acc_file.close();
               return 1;//details matched//
           }
           //if acc no. matched but not the acc holder's name//
           cerr<<endl<<"invalid acc holder's name..!";
           acc_file.close();
           return 0;
       }
   }

/*to verify
   cout<<endl<<"acc number does not exist ";*/
   acc_file.close();
   return 0;

}


void bank_account::input()
{
    cout<<"Enter acc no.: ";
    cin>>entered_acc_number;
    cout<<"Enter name of acc holder: ";
    cin.ignore();
    getline(cin,entered_acc_name);

    //calling as well as obtaining result of verify function//
    /*if verify returns 0 i.e. acc no. is not already present it is
    saved in text file*/
    //verify inside input is called only for case 1//
    if(flag)
    {
        cout<<"Enter initial balance: ";
        cin>>entered_acc_balance;
        if(!verify())
            {
                write_details();
            }
    }

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
                obj.deposite(obj.verify());
                break;
            }
            case 3:
                {
                    bank_account obj;
                    obj.input();
                    obj.withdraw(obj.verify());
                    break;
                }
            case 4:
                {
                    bank_account obj;
                    obj.input();
                    obj.check_balance(obj.verify());
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
