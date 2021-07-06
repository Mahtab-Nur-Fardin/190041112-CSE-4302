#include<iostream>
#include<string>

using namespace std;

class BankAccount
{
private:
    int account_no;
    string name;
    string account_type;
    float current_balance;
    float minimum_balance = 500.00;

public:
    BankAccount():name(""),account_type(""),current_balance(0.0)
    {
    }
    BankAccount(int acc_no, string holder_name, string type, float balance ) : account_no(acc_no), name(holder_name), account_type(type), current_balance(balance)
    {
    }

    void show_info()
    {
        cout<<"Account No: " << account_no << endl;;
        cout<<"Name: " << name << endl;
        cout<<"Account Type : " << account_type << endl;
        cout<<"Current Balance : " << current_balance << endl;
    }
    void showBalance()
    {
        cout<<"Current Balance : " << current_balance << endl;
    }
    void deposit()
    {
        int dammount;
        cout<<"\n Enter Deposit Ammount = ";
        cin >> dammount;
        current_balance += dammount;
    }
    void withdrawal()
    {
        float wammount;
        cout << "\n Enter Withdrawal Ammount = ";
        cin >> wammount;
        if( wammount > current_balance){
            cout << "\n Cannot Withdraw Ammount!" << endl;
        }

        else if( current_balance - wammount < minimum_balance){
            cout << "ERROR! You need minimum 500.00 taka in your account!" << endl;
        }
        else {
            current_balance -= wammount;
        }

    }

    void get_info()
    {
        int acc_no;
        string n, t;
        float b;

        cout << "Enter account no: ";
        cin >> acc_no;
        account_no = acc_no;

        cout << "Enter name: ";
        cin >> n;
        name = n;

        cout << "Enter account type: ";
        cin >> t;
        account_type = t;

        cout << "Enter balance: ";
        cin >> b;
        current_balance = b;
    }
    void giveInterest(float rate)
    {
        float interest_bal;
        interest_bal = current_balance * (rate/100);
        interest_bal -= interest_bal * 0.1;
        current_balance += interest_bal;
    }
    void giveInterest()
    {
        float interest_bal;
        interest_bal = current_balance * 0.03;
        interest_bal -= interest_bal * 0.1;
        current_balance += interest_bal;
    }

    ~BankAccount()
    {
        cout << "Account of Mr." << name << " with account no " << account_no << " is destroyed with a balance BDT "<< current_balance << endl;
    }


};

int main()
{
    BankAccount b1(001,"X","savings",1000);
    b1.show_info();
    BankAccount b2;
    b2.get_info();
    b2.showBalance();

}
