#include <iostream>
using namespace std;
void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
}
void insert_element(int arr[], int &size, int capacity, int index, int element)
{
    if (size >= capacity){
        cout << "can't insert because the capacity is already full" << endl;
        return;
    }
    for (int i = size; i >= index; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[index] = element;
    size++;
}
int main()
{
    int const capacity = 10;
    int size = 11;
    int arr[capacity] = {1, 2, 3, 4, 5, 6, 7};
    insert_element(arr, size, 10, 4, 1234);
    //display(arr,size);
    return 0;
}