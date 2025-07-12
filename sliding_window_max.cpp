#include <iostream>
#include <vector>
using namespace std;
vector<int> slid_wind_max(vector<int> arr)
{
    vector<int> ans;
    int first, second, third;
    for (int i = 0; i < arr.size() - 2; i++)
    {
        first = i;
        second = first + 1;
        third = second + 1;
        ans.push_back(max(arr[first], max(arr[second], arr[third])));
    }
    for(int i: ans){
        cout<<i<<" ";
    }
    return ans;
}

int main()
{
    vector<int> arr={1,2,1,4,15,6,7,-8,9,10,-11,82,3,14,15};
    slid_wind_max(arr);
    return 0;
}