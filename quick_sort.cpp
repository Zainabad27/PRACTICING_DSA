#include <iostream>
#include <vector>
using namespace std;
int partition(vector<int> &arr, int start, int end)
{

    int indx = start - 1;

    for (int i = start; i < end; i++)
    {
        if (arr[i] < arr[end])
        {
            indx++;
            swap(arr[indx], arr[i]);
        }
    }
    indx++;
    swap(arr[indx], arr[end]);
    return indx;
}

void quick_sort(vector<int> &arr, int st, int end)
{
    if (st < end)
    {
        int idx = partition(arr, st, end);
        quick_sort(arr, st, idx - 1);
        quick_sort(arr, idx + 1, end);
    }
}
int main()
{
    vector<int> arr = {4, 3, 6, 8, 9, 2, 1, 5};

     quick_sort(arr, 0, arr.size() - 1);

    for (int i : arr)
    {
        cout << i << " ";
    }
    return 0;
} 