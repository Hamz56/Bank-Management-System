/*following is the code for bank management system
it contains a base class named account that stores information about customer.
then there is a derived class named current account that deposits and winthdraws current balance.
and another derived class that deposits and withdraws saving balance
*/

#include <iostream>
#include <string.h>
#include<fstream>
using namespace std;

//class to concatenate and display the title of project using operator overloading
class AddString {

public:
    char str[100];

    // No Parameter Constructor
    AddString() {}

    // Parametrized constructor
    AddString(char str[])
    {
        strcpy(this->str, str);
    }

    // Overload Operator+ to concatenate the strings
    AddString operator+(AddString& S2)
    {
        // Object to return the copy
        // of concatenation
        AddString S3;

        // Use strcat() to concat two specified string
        strcat(this->str, S2.str);

        // Copy the string to string to be return
        strcpy(S3.str, this->str);

        return S3;
    }
};

// BANK MANAGEMENT SYSTEM CODE


class account
{
    string members;
    int x;
    int y;
    int z;

public:
    string cust_name;
    string acc_no;
    string acc_type;
public:

    void get_accinfo()
    {


    /////////////////////
        cout << "\n\nEnter Customer Name :- ";
        cin.ignore();
        getline(cin,cust_name);   //getline is used to enter any string value including blank space.

        cout << "Enter Account Number :- ";
        cin.ignore();                           //ignore is used to ignore or clear one or more characters from the input buffer
        getline(cin,acc_no);
        cout << "Enter Account Type :- ";
        cin.ignore();
        getline(cin,acc_type);


    }
    void display_accinfo()
    {
        cout << "\n\nCustomer Name :- " << cust_name;      //displaying customer info
        cout << "\nAccount Number :- " << acc_no;
        cout << "\nAccount Type :- " << acc_type;
    }

    friend string memb1(account);         //using friend function to display names of the members of this project
    friend string memb2(account);
    friend string memb3(account);

  account(int x = 0, int y = 0,int z = 0) { this->x = x; this->y = y; this->z = z;}    //using this pointer to display roll numbers of group members
  account &setX(int a) { x = a; return *this; }
  account &setY(int b) { y = b; return *this; }
  account &setz(int c) { z = c; return *this; }

   void print()
 {
  cout << " ROLL NO: " << x <<"," << " ROLL NO: " << y <<" AND "<< " ROLL NO : " << z << endl;
   }
};


string memb1(account m1)
{
    m1.members="HAMZA AFZAL";
    return m1.members;
}
string memb2(account m2)
{
    m2.members="XXXXXXX";
    return m2.members;
}
string memb3(account m3)
{
    m3.members="YYYYYYYYY ";
    return m3.members;
}


class current_account : public account               //derived class for current account     (inheritance)
{
    static float balance;
public:
void get_data();

    void disp_currbal()
    {

        cout << "\nBalance = " << balance;
    }
    void deposit_currbal()
    {
        float deposit;
        cout << "\nEnter amount to Deposit : ";
        cin >> deposit;
        balance =  deposit;
    }
    void withdraw_currbal()
    {
        float penalty, withdraw;
        cout << "\n\nBalance = " << balance;
        cout << "\nEnter amount to be withdraw :-";
        cin >> withdraw;
        balance = balance - withdraw;
        if (balance < 500)
        {
            penalty = (500 - balance) / 10;
            balance = balance - penalty;
            cout << "\nBalance after deducting penalty : " << balance;
        }
        else if(withdraw > balance)
        {
            cout << "\n\nYou have to take permission for Bank Overdraft Facility\n";
            balance = balance + withdraw;
        }
        else
            cout << "\nAfter Withdrawall your Balance will be revealed : " << balance;
    }
};
//////////////////////////////////////////




///////////////////////////////////////////////

class saving_account : public account             //derived class for saving account      (inheritance)
{
protected:
    static float saving_bal;
public:
    void prev_record();
void getdata();
    void disp_savbal()
    {
        cout << "\nBalance = " << saving_bal;
    }
    void deposit_savbal()
    {
        float deposit, interest;
        cout << "\nEnter amount to Deposit :- ";
        cin >> deposit;
        saving_bal = saving_bal + deposit;
        interest = (saving_bal * 2) / 100;
        saving_bal = saving_bal + interest;
    }
    void withdraw_savbal()
    {
        float withdraw;
        cout << "\nBalance = " << saving_bal;
        cout << "\nEnter amount to be withdrawn :-";
        cin >> withdraw;
        saving_bal = saving_bal - withdraw;
        if (withdraw > saving_bal)
        {
            cout << "\n\nYou have to take permission for Bank Overdraft Facility\n";
            saving_bal = saving_bal + withdraw;
        }
        else
            cout << "\nAfter Withdrawal your Balance will be revealed : " << saving_bal;
    }
};
void saving_account::getdata()
        {
            saving_account s1;
            ofstream oFile;
            oFile.open("customer.txt",ios::binary|ios::app);
            s1.get_accinfo();



        }
void saving_account::prev_record()
{
    cout<<"saving account";
    saving_account s1;
                    ifstream inFile;
                    inFile.open("customer.txt",ios::binary);
                    if(!inFile)
                    {
                        cout<<"\nFile not Found";
                    }
                    while(inFile.read((char*)&s1,sizeof(s1)))
                    {
                        cout<<"\n==============================\n";

                    s1.display_accinfo();
                    s1.disp_savbal();
                    }
                    cin.ignore();
                    cin.get();
                    }

float current_account::balance;
float saving_account::saving_bal;

int main()           //driver code
{

    char str1[] = "=============BANK ";
    char str2[] = "MANAGEMENT SYSTEM==============";

    // Declaring and initializing the class
    // with above two strings
    AddString a1(str1);
    AddString a2(str2);
    AddString a3;

    // Call the operator function
    a3 = a1 + a2;
    cout << " " << a3.str;

    current_account c1;
    saving_account s1;

    account mm;

    cout<<"\n MADE BY "<<memb1(mm)<<","<<memb2(mm)<<" AND "<<memb3(mm)<<endl;

    account obj1(0,0);
    obj1.setX(25).setY(0).setz(00);
    obj1.print();
    ///////////////////////////////////
  
    cout<<"\n                    WELCOME HERE           ";
    cout << "\n\nEnter S for saving customer, C for current a/c customer \n\n";
    char type;
    cin >> type;
int choice;

   if (type == 's' || type == 'S')
    {///////////////////
            saving_account s1;
            ofstream oFile;
            oFile.open("customer.txt",ios::binary|ios::app);
          // s1.get_accinfo();
            oFile.write((char*)&s1,sizeof(s1));
            oFile.close();
            cout<<"Customer record has been created"<<endl;
            cin.ignore();
            cin.get();
        /////////////////
        while (1)
        {

            cout <<"\n .......MAIN MENU.......";
            cout << "\nChoose Your Choice\n";
            cout << "1)   Deposit\n";
            cout << "2)   Withdraw\n";
            cout << "3)   Display Balance\n";
            cout << "4)   Display with full Details\n";
            cout << "5)   Display saved full Details\n";
            cout << "6)   Delete All\n";
            cout << "7)   Exit\n";

            cin >> choice;
            switch (choice)
            {
            case 1: s1.deposit_savbal();
                    cin.get();
                    break;
            case 2: s1.withdraw_savbal();
                cin.get();
                break;
            case 3: s1.disp_savbal();
                cin.get();
                break;
            case 4:
                {

                    s1.display_accinfo();
                    s1.disp_savbal();
                    cin.get();
                }
                break;

                case 5:
                {
                    ifstream inFile;
                    inFile.open("customer.txt",ios::binary);
                    if(!inFile)
                    {
                        cout<<"\nFile not Found";
                    }
                    while(inFile.read((char*)&s1,sizeof(s1)))
                    {
                        cout<<"\n==============================\n";

                    s1.display_accinfo();
                    s1.disp_savbal();
                    }
                    cin.get();
                }
                break;

                 case 6:
                {
                    ifstream inFile;
                    inFile.open("customer.txt",ios::binary);
                    if(!inFile)
                    {
                        cout<<"\nFile not Found";
                    }
                ofstream oFile;
                oFile.open("temp.txt",ios::out);
                inFile.seekg(0,ios::beg);
                oFile.close();
                inFile.close();
                remove("customer.txt");
                rename("temp.txt","customer.txt");
                cout<<"\nSuccessfully Deleted";
                cin.ignore();
                cin.get();
                }
                break;

            case 7: goto end;
            default: cout << "\n\nEntered choice is invalid,\"TRY AGAIN\"";
            }
        }
    }
    else
    {
        {
                        current_account c1;
            ofstream oFile;
            oFile.open("customer.txt",ios::binary|ios::app);
            c1.get_accinfo();
            oFile.write((char*)&c1,sizeof(c1));
            oFile.close();
            cout<<"Customer record has been created"<<endl;
            cin.ignore();
            cin.get();

            while (1)
            {
                cout <<"\n .......MAIN MENU.......";
                cout << "\nChoose Your Choice\n";
                cout << "1)   Deposit\n";
                cout << "2)   Withdraw\n";
                cout << "3)   Display Balance\n";
                cout << "4)   Display with full Details\n";
                cout << "5)   Display saved full Details\n";
                cout << "6)   Delete All\n";
                cout << "7)   Exit\n";

                cin >> choice;
                switch (choice)
                {
                case 1: c1.deposit_currbal();
                    cin.get();
                    break;
                case 2: c1.withdraw_currbal();
                    cin.get();
                    break;
                case 3: c1.disp_currbal();
                    cin.get();
                    break;
                case 4: c1.display_accinfo();
                    c1.disp_currbal();
                    cin.get();
                    break;
                  case 5:
                {
                    ifstream inFile;
                    inFile.open("customer.txt",ios::binary);
                    if(!inFile)
                    {
                        cout<<"\nFile not Found";
                    }
                    while(inFile.read((char*)&c1,sizeof(c1)))
                    {
                        cout<<"\n==============================\n";

                    c1.display_accinfo();
                    c1.disp_currbal();
                    }
                    cin.get();
                }
                break;
                 case 6:
                {
                    ifstream inFile;
                    inFile.open("customer.txt",ios::binary);
                    if(!inFile)
                    {
                        cout<<"\nFile not Found";
                    }
                ofstream oFile;
                oFile.open("temp.txt",ios::out);
                inFile.seekg(0,ios::beg);
                oFile.close();
                inFile.close();
                remove("customer.txt");
                rename("temp.txt","customer.txt");
                cout<<"\nSuccessfully Deleted";
                cin.ignore();
                cin.get();
                }
                break;

                case 7: goto end;
                default: cout << "\n\nEntered choice is invalid,\"TRY AGAIN\"";
                }
            }
        }
    }
end:
    return 0;
}
