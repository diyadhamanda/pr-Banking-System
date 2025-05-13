// Banking System

#include <iostream>
using namespace std;

class Bank
{
protected:
    long int acc_no;
    string accountHolderName;
    char type;
    double balance;

public:
    void setAccount(long int acc_no, string accountHolderName, char type, double balance)
    {
        this->acc_no = acc_no;
        this->accountHolderName = accountHolderName;
        this->type = type;
        this->balance = balance;
    }
    void deposit(double depositAmount, double balance)
    {
        this->balance += depositAmount;
        cout << "New Balance is: " << this->balance << endl;
    }
    void withdraw(double withdrawAmount, double balance)
    {
        this->balance -= withdrawAmount;
        cout << "New Balance is: " << this->balance << endl;
    }
    void getBalance()
    {
        cout << "Current Balance: " << this->balance << endl;
    }
    void displayAccountInfo()
    {
        cout << endl;
        cout << "Account Number: " << this->acc_no << endl;
        cout << "Account Holder Name: " << this->accountHolderName << endl;
        cout << "Account Type: " << this->type << endl;
        cout << "Balance: " << this->balance << endl;
    }
    virtual void display() = 0;
};

class SavingAcc : public Bank
{
protected:
    float interestRate;

public:
    void calculateInterest(float interestRate, double balance)
    {
        cout<<"Your Balance: "<<this->balance<<endl;
        this->balance += this->balance * interestRate;
        cout << "Interest Applied. New balance is: " << this->balance << endl;
    }
    void display()
    {
        cout << "Interest Rate: " << this->interestRate << endl;
    }
};

class CheckingAcc : public Bank
{
protected:
    double overdraftLimit;

public:
    void checkOverdraft(double overdraftLimit, double withdrawAmount, double balance)
    {
        if ( withdrawAmount <= balance + overdraftLimit && this->balance > 0)
        {
            Bank::withdraw(withdrawAmount, balance);
        }
        else
        {
            cout << "Withdrawal amount exceed balance and over draft limit." << endl;
        }
    }
    void display()
    {
        cout << "Overdraft Limit: " << this->overdraftLimit << endl;
    }
};

class FixedAcc : public Bank
{
protected:
    int term;
    float interestRate;

public:
    void calcalculateInterest(float interestRate, double balance, int term)
    {
        cout<<"Enter term: ";
        cin>>term;
        
        cout<<"Your Balance: "<<this->balance<<endl;
        this->balance += this->balance * interestRate *term/12;
        cout << "Interest Applied. New balance is: " << this->balance << endl;
    }
    void display()
    {
        cout<<"Term "<<term<<" Months"<<endl;
    }
};

int main()
{

    long int acc_no;
    string accountHolderName;
    double balance;
    char type;
    int choice;

    cout << "Please Enter Detail for create your Account" << endl;
    cout << "Enter Account Number: ";
    cin >> acc_no;
    cout << "Enter Account Holder Name: ";
    cin >> accountHolderName;
    cout << "Enter Account Type (Saving = s, Checking = c, Fixed Deposit = f): ";
    cin >> type;
    cout << "Enter Balance: ";
    cin >> balance;


    if (type == 's' || type == 'S')
    {
        SavingAcc save;
        save.setAccount(acc_no, accountHolderName, type, balance);
        cout << "save Account create successfully." << endl;
        float interestRate=0.05;
        cout<<endl;
        
        do
        {
            cout <<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
            cout << "Enter 1 for Deposit" << endl;
            cout << "Enter 2 for Withdraw" << endl;
            cout << "Enter 3 for Calculate interest" << endl;
            cout << "Enter 4 Get Balance" << endl;
            cout << "Enter 5 for Display Account Information" << endl;
            cout << "Enter 0 for Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            cout <<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;

            switch (choice)
            {
            case 1:
                double depositAmount;

                cout << "Enter Amount you want to deposit: ";
                cin >> depositAmount;
                save.deposit(depositAmount, balance);
                break;

            case 2:
                double withdrawAmount;

                cout << "Enter Amount you want to withdraw: ";
                cin >> withdrawAmount;
                if (withdrawAmount < balance)
                {
                    save.withdraw(withdrawAmount, balance);
                }
                else
                {
                    cout << "Withdrawal Amount must be less than your account balance." << endl;
                }
                break;

            case 3:
                save.calculateInterest(interestRate,balance);
                break;

            case 4:
                save.getBalance();
                break;

            case 5:
                save.displayAccountInfo();
                break;

            default:
                cout << "Exit.";
                break;
            }
        } while (choice != 0);
    }
    else if(type == 'c' || type == 'C')
    {
        CheckingAcc check;
        check.setAccount(acc_no, accountHolderName, type, balance);
        cout << "Your Account create successfully." << endl;
        double overdraftLimit=5000;
        cout<<endl;
        do
        {
            cout <<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
            cout << "Enter 1 for Deposit" << endl;
            cout << "Enter 2 for Withdraw" << endl;
            cout << "Enter 3 for Get Balance" << endl;
            cout << "Enter 4 for Display Account Information" << endl;
            cout << "Enter 0 for Exit" << endl;
            cout << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            cout <<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
            switch (choice)
            {
            case 1:
                double depositAmount;

                cout << "Enter Amount you want to deposit: ";
                cin >> depositAmount;
                check.deposit(depositAmount, balance);
                break;

            case 2:
                double withdrawAmount;

                cout << "Enter Amount you want to withdraw: ";
                cin >> withdrawAmount;
                check.checkOverdraft(overdraftLimit,withdrawAmount,balance);
                break;

            case 3:
                check.getBalance();
                break;

            case 4:
                check.displayAccountInfo();
                break;

            default:
                cout << "Exit.";
                break;
            }
        } while (choice != 0);
    }
    else
    {
        FixedAcc fix;
        fix.setAccount(acc_no, accountHolderName, type, balance);
        cout << "Fixed Deposit Account create successfully." << endl;
        float interestRate=0.07;
        int term;
        cout<<endl;
        
        do
        {
            cout <<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
            cout << "Enter 1 for Deposit" << endl;
            cout << "Enter 2 for Withdraw" << endl;
            cout << "Enter 3 for Calculate interest" << endl;
            cout << "Enter 4 for Get Balance" << endl;
            cout << "Enter 5 for Display Account Information" << endl;
            cout << "Enter 0 for Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            cout <<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;

            switch (choice)
            {
            case 1:
                double depositAmount;

                cout << "Enter Amount you want to deposit: ";
                cin >> depositAmount;
                fix.deposit(depositAmount, balance);
                break;

            case 2:
            double withdrawAmount;
                {
                    cout<<"Withdrawal not allowed untill the end of the term."<<endl;
                }
                break;

            case 3:
                fix.calcalculateInterest(interestRate,balance,term);
                break;

            case 4:
                fix.getBalance();
                break;

            case 5:
                fix.displayAccountInfo();
                break;

            default:
                cout << "Exit.";
                break;
            }
        } while (choice != 0);
    }

    return 0;
}