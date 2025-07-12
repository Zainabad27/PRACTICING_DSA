#include <iostream>
using namespace std;
int main()
{
    int counter=0;
    int num;
    int min, max, mid;
    bool found = false;
    int const size = 10;
    int arr[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "Enter the number: ";
    cin >> num;
    min = 0;
    max = size - 1;
    mid = (0 + (size - 1)) / 2;

    while(min<=max)
    {   counter++;
        if (num == arr[mid]){
            found = true;
            break;
        }
        else if (num > arr[mid])
        {
            min = mid+1;
            mid = (min + max) / 2;
        }
        else{
            max=mid-1;
            mid = (min + max) / 2;

        }
    }

    if (found)
        cout << "yes, it is present in the array." << endl<<counter;

    else
    {
        cout << "not found";
    }
    return 0;
}