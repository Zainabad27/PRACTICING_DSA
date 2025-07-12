#include <iostream>
using namespace std;
int main()
{
    int num;
    bool found = false;
    int const size = 10;
    int arr[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "Enter the number: ";
    cin >> num;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == num)
            found = true;
    }
    if(found)
        cout<<"yes, it is present in the array."<<endl;

    else{cout<<"not found";}
    return 0;
}