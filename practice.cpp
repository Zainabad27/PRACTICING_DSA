#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <list>
#include <deque>
using namespace std;

struct customer
{
    int customer_id;
    string name;
};
struct item
{
    int item_id;
    string item_name;
    int quantity;
};
vector<customer> v;
vector<item> i;
void get_userdata()
{ 
    // takes the data from the user and stores it in vector V(which is of customer type).
    int user_input;
    int id;
    string user_name;
    do
    {
        cout << "To enter the user data, press 1." << endl;
        cin >> user_input;
        if (user_input == 1)
        {

            cout << endl
                 << endl
                 << "Enter the customer id" << endl;
            cin >> id;
            cout << "Enter your name: " << endl;
            cin >> user_name;
            v.push_back({id, user_name});
        }
        else
        {
            break;
        }

    } while (user_input != 0);
}
void get_item()
{ 
    // takes the data of the  item and stores it in deque i(which is of item type).
    int user_input;
    int id;
    string itemname;
    int qntity;
    do
    {
        cout << "To enter the item data, press 1." << endl;
        cin >> user_input;
        if (user_input == 1)
        {

            cout << endl
                 << endl
                 << "Enter the item id" << endl;
            cin >> id;
            cout << "Enter your item name: " << endl;
            cin >> itemname;
            cout<<"Enter the quantity of that item"<<endl;
            cin>>qntity;
            i.push_back({id,itemname,qntity});
        }
        else
        {
            break;
        }

    } while (user_input != 0);
}

int main()
{
    get_userdata();
    get_item();

    // for (auto c : v)
    // {
    //     cout << c.customer_id << " " << c.name << endl
    //          << endl
    //          << endl;
    // }
    return 0;
}