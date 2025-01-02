
//incomplete code//

#include<iostream>
using namespace std;
int main(){
    cout<<"Calculator\n\n";
    int a,choice,b,result;
    cout<<"Enter the first variable: ";
    cin>>a;
    cout<<"\n1. add\n2. subtract\n3. multiply\n4. divide\n5. Exit";
    cout<<endl<<"Enter the choice: ";
    cin>>choice;
    cout<<endl<<"Enter the second variable: ";
    cin>>b;
        switch(choice){
        case 1:{
            result=a+b;
            cout<<endl<<result;
            break;
        }
        case 2:{
            result=a-b;
            cout<<endl<<result;
            break;
        }
        case 3:{
            result=a*b;
            cout<<endl<<result;
            break;
        }
        case 4:{
            result=a/b;
            cout<<endl<<result;
            break;
        }
        case 5:{
            return 0;
        }
        default :
        cout<<endl<<"Entered incorrect choice!";
    }

    return 0;
}

