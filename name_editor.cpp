#include<iostream>
#include<string>
#include<cctype>
using namespace std;

//creating function//
string capitalize_name(string name)
{
    bool capatilize_nextletter=true;//true for first letter

    //access each char of string name//
    for(char& ch : name)//ch is the char or space at each position
    {
        //captalizing only if it is first letter and a alphabet //
        if(capatilize_nextletter && isalpha(ch))
        {
            ch=toupper(ch);//setting to upper case//
            capatilize_nextletter=false;
        }else{
            ch=tolower(ch);
        }

        //for space//
        if(isspace(ch))
        {
            capatilize_nextletter=true;
        }
    }
    return name;

}

//to check if only alphabets are present //
bool valid_name(const string& name)//const so that it won't get edited//
{
    for(char ch: name)
    {
        if(!isalpha(ch)&&!isspace(ch))//when ch is neither alphabet nor space//
        {
            cout<<"enter only alphabets..!";
            return false;
        }
    }
    return true;
}

//creating a function to edit spaces//
string trim_space(string name)
{
    //name. returns size which is stored in size_t datatyped var//
    size_t start_index = name.find_first_not_of(" ");
    //find_first_not_of returns a pointer pointing first index which is not space//
    //cout<<endl<<"start_index: "<<name[start_index];//
    size_t end_index = name.find_last_not_of(" ");
    //find_first_not_of returns a pointer pointing last index which is not space//
    //cout<<endl<<"end_index: "<<name[end_index];//

    /*substr(start, length) extracts a portion of the string starting from start
    and having a length of end - start + 1*/
    return name.substr( start_index , end_index - start_index + 1 );

}

//creating a function to edit spaces between name//
string trim_between_spaces(string name)
{
    string trimed_name="";
    bool space_found=false;
    for(char ch: name)
    {
        //if the char is not space then simply add alphabet to result//
        if(ch!=' ')
        {
            trimed_name+=ch;
            space_found=false;

        }else
        {
            //when ch is a space//
            //if it is valid i.e single space between name//
            if(!space_found)//!space_found indicates the space is the first space found which is valid//
            {
                //add space//
                trimed_name+=ch;
            space_found=true;
            }//for else part when space_found is true it will simply increament ch//
        }
    }
    return trimed_name;
    /*this function will not edit tailing space thus call trim_space function afterwards to
    trim tailing spaces*/
}

int main()
{
    string name;
    while(true)
    {
        cout<<endl<<"enter name: ";
        getline(cin,name);
        if(valid_name(name))
            {
                //to convert the inputed name in proper formate i.e. first letter captial//
                string edited_name = trim_space(trim_between_spaces(capitalize_name(name)));
                cout<<endl<<edited_name;
                //clearing string//
                name.clear();
            }
            }

    return 0;
}

