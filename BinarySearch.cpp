#include <iostream>
#include <vector>

int BinarySearch(std::vector<int> nums, int val)
{

    int st = 0;
    int end = nums.size() - 1;

    while (st <= end)
    {
        int mid = (st + end) / 2;

        if (nums[mid] == val)
            return mid;
        if (nums[mid] > val)
        {
            end = mid - 1;
        }
        else
        {
            st = mid + 1;
        }
    }

    return -1;
}

int main()
{

    std::vector<int> nums = {1, 2, 35, 66, 84, 9999};
    int ans = BinarySearch(nums, 777);

    std::cout << "ANS: " << ans<<"\n";
    // if(ans==-1) throw new __EXCEPTION__();
    std::cout << "Value: " << nums[ans];

    return 0;
}