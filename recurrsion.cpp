#include <iostream>
#include <vector>
using namespace std;
int factorial(int n)
{
    if (n == 1 || n == 0)
    {
        return 1;
    }
    return n * factorial(n - 1);
}
int total = 0;
void sum(int n)
{
    if (n == 0)
    {
        return;
    }
    total = total + n;
    sum(n - 1);
}
int fabonacci(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    cout << n;
    return fabonacci(n - 1) + fabonacci(n - 2);
}
// function to check if the array is sorted or not?
bool issorted(vector<int> arr, int size)
{ // base condition.
    if (size <= 1)
    {
        return true;
    }
    if (arr[size - 1] < arr[size - 2])
    {
        return false;
    }
    return issorted(arr, size - 1);
}
int b_search(vector<int> arr, int target, int start, int end)
{
    int mid = (start + end) / 2;
    if (start > end)
    {
        return -1;
    }
    if (target == arr[mid])
    {
        return mid;
    }
    else if (target > arr[mid])
    {
        return b_search(arr, target, mid + 1, end);
    }
    return (b_search(arr, target, start, mid - 1));
}
void all_subset(vector<int> &arr, vector<int> &ans, int i = 0)
{
    if (i == arr.size())
    {
        for (auto z : ans)
        {
            cout << z << " ";
        }
        cout << endl;
        return;
    }
    ans.push_back(arr[i]);
    all_subset(arr, ans, i + 1);
    ans.pop_back();
    all_subset(arr, ans, i + 1);
}
void permutations(vector<int> &arr, vector<int> &ans, int i = 0)
{
    if (i == arr.size())
    {
        for (auto z : ans)
        {
            cout << z << " ";
        }
        cout << endl;
        return;
    }
    ans.push_back(arr[i]);
    permutations(arr, ans, i + 1);
}
int exponential(int base, int power)
{
    if (base == 1 || power == 0)
    {
        return 1;
    }

    return base * (exponential(base, power - 1));
}
int fibbonacci(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }

    return fibbonacci(n - 1) + fibbonacci(n - 2);
}
int growth(int pair, int month)
{
   if(month==1){
    return pair=pair*2;
   }

   return growth(pair+1,month-1);
   
}
int main()
{
    //cout << exponential(9, 3);
    cout<<growth(2,5);

    return 0;
}