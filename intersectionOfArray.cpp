#include <iostream>
#include <vector>

std::vector<int> IntersectionArray(std::vector<int> &nums1, std::vector<int> &nums2)
{

    std::vector<int> ans;

    for (int i = 0; i < nums1.size(); i++)
    {
        for (int j = 0; j < nums2.size(); j++)
        {
            if (nums1[i] == nums2[j])
            {
                bool hasNum = false;
                for (int k : ans)
                {
                    if (k == nums1[i])
                        hasNum = true;
                }

                if (!hasNum)
                    ans.push_back(nums1[i]);
            }
        }
    }
}
int main()
{

    return 0;
}