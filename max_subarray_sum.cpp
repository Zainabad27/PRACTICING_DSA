#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
void max_subarray(vector<int> arr, int tar)
{
    // arr={9,4,20,3,10,5}
    int count = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < arr.size(); j++)
        {
            sum += arr[j];

            if (sum == tar)
            {
                count++;
                break;
            }
        }
    }
    cout << count;
}
void max_subarray_optimized(vector<int> arr, int tar)
{
    int count = 0;

    vector<int> prefix_sum;
    prefix_sum.push_back(arr[0]);
    unordered_map<int, int> m;

    for (int i = 1; i < arr.size(); i++)
    {
        prefix_sum.push_back(prefix_sum[i - 1] + arr[i]);
    }

    for (int i = 0; i < prefix_sum.size(); i++)
    {
        if (prefix_sum[i] == tar)
        {
            count++;
        }
        m[prefix_sum[i]]++;

        if (m.find(prefix_sum[i] - tar) != m.end())
        {
            count += m[prefix_sum[i] - tar];
        }
    }

    cout << count;
}

void prefix_sum(vector<int>& arr, int tar)
{
    int count = 0;
    int sum = 0;
    unordered_map<int, int> m;

    m[0] = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];

        if (m.find(sum - tar) != m.end())
        {
            count += m[sum - tar];

            
        }
        m[sum]++;
    }
    cout << "The Count is: " << count;
}

int main()
{
    vector<int> arr;
    arr = {9, 4, 20, 3, 10, 5};
   
    prefix_sum(arr, 33);

    return 0;
}