#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int absolute(int n)
{
    if (n < 0)
        return n * -1;

    return n;
}

int main()
{
    int min = 1;

    vector<int> nums = {-2, -2, -2};

    unordered_set<int> us;

    for (int i = 0; i < nums.size(); i++)
    {
        bool minPresent = false;

        minPresent = (us.end() != us.find(nums[i])) && (*(us.find(nums[i])) == min);
        

        if (nums[i] == min || minPresent)
            min++;
        else
            us.insert(nums[i]);
    }

    cout
        << "\n\n\n\n"
        << min
        << " is the answer\n\n\n";

    return 0;
}