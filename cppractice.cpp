#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

void email_seprator()
{
    string email;
    cout << "Enter your email(firstname.lastname@gmail.com): " << endl;
    getline(cin, email);
    int pos_1 = email.find(".");
    int pos_2 = email.find("@", pos_1 + 1);
    string fname, lname, lpart;
    fname = email.substr(0, pos_1);
    lname = email.substr(pos_1 + 1, pos_2 - pos_1 - 1);
    lpart = email.substr(pos_2 + 1);
    cout << "First name: " << fname << endl
         << "Last name: " << lname << endl
         << "Last part: " << lpart << endl;
}
void bmi_calculation()
{
    float height, weight;
    cout << "Enter you height(inches): " << endl;
    cin >> height;
    while (cin.fail())
    {
        cout << "invalid input." << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> height;
    }
    cout << "Enter your weight(pounds): " << endl;
    cin >> weight;
    while (cin.fail())
    {
        cout << "invalid input." << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> weight;
    }
    double bmi = ((weight / (height * height)) * 703);
    if (bmi < 18.5)
    {
        cout << "Under weight" << endl;
    }
    else if (bmi >= 18.5 || bmi <= 24.5)
    {
        cout << "NORMAL>" << endl;
    }
    else if (bmi >= 25.0 || bmi <= 29.9)
    {
        cout << "overweight" << endl;
    }
    else
    {
        cout << "obese" << endl;
    }
}
void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
void bubble_sort(vector<int> &arry)
{
    for (int i = 0; i < arry.size() - 1; i++)
    {
        for (int j = 0; j < arry.size() - 1 - i; j++)
        {
            if (arry[j] > arry[j + 1])
            {
                swap(arry[j], arry[j + 1]);
            }
        }
    }
}
void element_freq(vector<int> &arr)
{
    // arr={1,3,2,4,2,1,4,2,5,6,5,4,3,2,3,6}
    bubble_sort(arr);
    int freq = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == arr[i + 1])
        {
            freq++;
        }
        if (arr[i] != arr[i + 1])
        {
            // last element of that type detected.
            cout << "Element: " << arr[i] << " |frequency: " << freq << endl;
            freq = 1;
        }
    }
}
void histogram(vector<int> arr)
{
    // arr={1,4,9,7,2,5,3,6};
    for (int i = 0; i < arr.size(); i++)
    {
        cout << "Element: " << arr[i] << "   ";
        for (int j = 0; j < arr[i]; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void calculate_student_score()
{

    vector<vector<vector<int>>> score = {
        // Student 0
        {{10, 20}, {15, 25}, {20, 30}, {18, 27}, {14, 21}},
        // Student 1
        {{12, 22}, {17, 26}, {21, 31}, {19, 28}, {13, 20}},
        // Student 2
        {{11, 19}, {16, 24}, {19, 29}, {20, 30}, {15, 23}},
        // Student 3
        {{13, 21}, {18, 27}, {22, 32}, {17, 26}, {16, 24}},
        // Student 4
        {{14, 23}, {19, 28}, {20, 30}, {16, 25}, {17, 26}},
        // Student 5
        {{15, 25}, {20, 29}, {18, 27}, {21, 31}, {18, 27}},
        // Student 6
        {{16, 24}, {21, 30}, {19, 28}, {22, 32}, {19, 29}}};

    for (int i = 0; i < 7; i++)
    {
        int total_score_student = 0;
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                total_score_student += score[i][j][k];
            }
        }
        cout << "Score of " << i + 1 << " student: " << total_score_student << endl;
    }
}
int oddsum(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i = i + 2)
    {
        sum += i;
    }
    return sum;
}
int evensum(int n)
{
    int sum = 0;
    for (int i = 2; i <= n; i = i + 2)
    {
        sum += i;
    }
    return sum;
}
int sum(int n)
{
    if (n == 0)
    {
        return n;
    }
    else
    {
        return (n + sum(n - 1));
    }
}
int exp(int base, int power)
{
    if (base == 1 || power == 0)
    {
        return 1;
    }
    else
    {
        return base * exp(base, power - 1);
    }
}
bool ispalindrome(string content, int st, int end)
{
    if (st >= end) // base condition
        return true;

    if (toupper(content[st]) != toupper(content[end]))
    {
        return false;
    }
    else
    {
        return ispalindrome(content, st + 1, end - 1);
    }
}

struct car
{
    string brandname;
    double pricenew;
    string color;
    double odometer;

    double getprice()
    {
        double p= (pricenew * (1 - (odometer / 600000)));
        if(p<0){
            cout<<"This car is not for sale now.(too old)"<<endl;
            return 0;
        }
        return p;
    }
    void updatemilage(double dis_traveled)
    {
        if (dis_traveled < 0)
        {
            cout << "Invalid value for distance. " << endl;
            return;
        }

            odometer += dis_traveled;
        
    }
    void car_details()
    {
        cout << "Brand: " << brandname << endl
             << "Color: " << color << endl
             << "Price of New Car: " << pricenew << endl
             << "Price Now: " << getprice() << endl
             << "Distance traveled: " << odometer << endl;
    }
};
int main()
{
    car c1;
    c1.brandname = "Honda Civic";
    c1.color = "Black";
    c1.pricenew = 4500000;
    c1.odometer = 0;
    cout << c1.getprice();
    c1.updatemilage(543666922);
    cout << endl;
    cout << c1.getprice();
    return 0;
}