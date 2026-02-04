#include <iostream>
#include <vector>

using namespace std;

double Median(vector<int> &nums1, vector<int> &nums2)
{

    vector<int> ans;

    int m, n;

    n = nums1.size();
    m = nums2.size();

    int v1 = 0;
    int v2 = 0;
    for (int i = 0; i < n + m; i++)
    {
        if (v1 == n)
        {
            for (int j = v2; j < m; j++)
                ans.push_back(nums2[j]);

            break;
        }
        else if (v2 == m)
        {
            for (int j = v1; j < n; j++)
                ans.push_back(nums1[j]);

            break;
        }

        if (nums1[v1] < nums2[v2])
        {
            ans.push_back(nums1[v1]);
            v1++;
        }
        else if (nums2[v2] < nums1[v1])
        {
            ans.push_back(nums2[v2]);
            v2++;
        }
        else
        {
            ans.push_back(nums1[v1]);
            v1++;
            ans.push_back(nums2[v2]);
            v2++;
        }
    }
    int s = ans.size();

    if ((s % 2) == 0)
    {
        int pos1 = (s / 2) - 1;
        int pos2 = ((s + 2) / 2) - 1;

        double numa = ans[pos1];
        double numb = ans[pos2];
        double r = (double)(ans[pos1] + ans[pos2]) / 2;
        return r;
    }
    else
    {

        return (ans[((s + 1) / 2) - 1]);
    }
    
}

int main()
{

    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2, 4,5};

    double ans = Median(nums1, nums2);

    cout << "Merged Array Median is : " << "\n\n";

    cout << " " << ans << "\n";

    // cout << "ZA";
    return 0;
}