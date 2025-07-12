#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct account_data
{
    int user_id;
    string name;
    string password;
};

class login_system
{
    string user_name, password;
    static int count;

public:
    vector<account_data> user_data;
    bool search_data(string name, string password)
    {
        bool data_found = false;
        string line;
        ifstream read_file("data.txt", ios::in);
        if (read_file.is_open())
        {
            while (getline(read_file, line))
            {
                
                if (line.find(name) != string::npos && line.find(password) != string::npos) // Name and password is found
                {
                    
                    
                        data_found = true;
                        break;
                    
                }
            }
            read_file.close();
        }
        else
        {
            cout << "File did not open." << endl;
        }
        return data_found;
    }

    void login()
    {
        bool found = false;
        cout << "Welcome to our login page." << endl;

        string username;
        string passwrd;

        cout << "Enter your username: " << endl;
        getline(cin, username);

        cout << "Enter your password: " << endl;
        getline(cin, passwrd);

        found = search_data(username, passwrd);

        if (found)
        {
            cout << "-------------Login succesfull-----------------" << endl;
        }
        else{
            cout<<"incorrect username or password."<<endl;

        }
    }

    void sign_in()
    {
        count++;
        cout << "Choose the username: " << endl;
        getline(cin, user_name);
        cout << "Choose a password for your account: " << endl;
        getline(cin, password);

        user_data.push_back({count, user_name, password});

        ofstream write("data.txt", ios::app);
        if (write.is_open())
        {
           
            write  << user_name << " ";
            write  << password << endl;
           
        }
        else
        {
            cout << "The file did not open." << endl;
        }

        write.close();
    }
};

int login_system::count = 0;

int main()
{
    login_system obj;
    obj.sign_in();
    obj.login();
    return 0;
}
