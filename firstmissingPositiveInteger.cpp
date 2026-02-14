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

int firstMissingPositive(vector<int> nums)
{
     int n = nums.size();


    
    for(int i=0;i<n;i++){
         if (nums[i] < 0)
        {
            nums[i] = 0;
        }

    }

    for (int i = 0; i < n; i++)
    {

        
        if (absolute(nums[i]) >= 1 && absolute(nums[i]) <= n)
        {

            int value = absolute(nums[i]);
            int index = value - 1;


            if(nums[index]>0){

            nums[index] = nums[index] * -1;



            }
            else if(nums[i]==0){
                nums[index]=-1;
            }


        }
    }

    for (int i = 0; i < n; i++)
    {
        if (nums[i] >= 0)
            return i + 1;
    }

    return n + 1;
}

int main()
{

    vector<int> nums = {3,4,0,2};

    int ans = firstMissingPositive(nums);

    cout << ans;

    return 0;
}