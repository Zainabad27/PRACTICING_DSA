#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct bank_account
{

    string cus_name;
    string cus_password;
    string acc_id;
    int transaction_pin;
    double balance;
    double loan_taken;

    void set_pin()
    {
        int p;
        cout << "Set your 4 digit pin(XXXX)" << endl;
        cin >> p;
        while (cin.fail() || p < 1000 || p > 9999)
        {
            if (cin.fail())
            {
                cout << "Invalid input type." << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                cin >> p;
            }
            else if (p < 1000 || p > 9999)
            {
                cout << "Please Enter 4 Digits only" << endl;
                cin >> p;
            }
        }
        transaction_pin = p;
    }

    void change_pin()
    {
        int p;
        cout << "Enter the previous pin: " << endl;
        cin >> p;
        if (p == transaction_pin)
        {
            int new_p;
            cout << "Set yout $ digit pin(XXXX)" << endl;
            cin >> new_p;
            while (cin.fail() || new_p < 1000 || new_p > 9999)
            {
                if (cin.fail())
                {
                    cout << "Invalid input type." << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cin >> new_p;
                }
                else if (new_p < 1000 || new_p > 9999)
                {
                    cout << "Please Enter 4 Digits only" << endl;
                    cin >> new_p;
                }
              
            }
            transaction_pin = new_p;
        }
        else
        {
            cout << "Incorrect pin." << endl;
            return;
        }
    }

    bool login(string n, string p)
    {

        if (p == cus_password && n == cus_name)
        {
            cout << "Login successfull." << endl;
            return true;
        }
        else
        {
            cout << "Incorrect credentials" << endl;
            return false;
        }
    }
    void add_balance(double amount, int p)
    {
        if (amount < 0)
        {
            cout << "Invalid amount to input.\n";
            return;
        }
        if (p == transaction_pin)
        {
            balance += amount;
            cout << "Amount added to your account\n";
        }
        else
        {
            cout << "incorrect pin\n";
            return;
        }
    }

    void check_balance(int p)
    {
        if (p == transaction_pin)
        {
            cout << "Your current balance: " << balance << '\n';
        }
    }
};

void acc_id_generator(vector<bank_account> account_store){
    

}
int main()
{
    bank_account b1;
    b1.cus_name = "zain abad";
    b1.cus_password = "27135789";
    b1.set_pin();
    b1.add_balance(93322.2, 1234);
    b1.check_balance(1234);

    return 0;
}