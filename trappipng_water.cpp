#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;

int trapping_water(vector<int> v)
{
    vector<int> lmax;
    vector<int> rmax;
    int max_ele_left = v[0];
    int max_ele_right = v[v.size() - 1];
    int water = 0;
    int j = v.size() - 1;
    for (int i = 0; i < v.size(); i++)
    {

        if (i == 0)
        {
            lmax.push_back(v[0]);
        }
        else
        {
            if (v[i] > max_ele_left)
            {
                max_ele_left = v[i];
            }
            lmax.push_back(max_ele_left);
        }

        // filling right max elements for every bar.

        if (j == v.size() - 1)
        {
            rmax.push_back(v[j]);
        }
        else
        {
            j--;
            if (v[j] > max_ele_right)
            {
                max_ele_right = v[j];
            }
            rmax.push_back(max_ele_right);
        }
    }
    // reversing rmax because it is
    vector<int> right_max;
    for (int i = rmax.size() - 1; i >= 0; i--)
    {
        right_max.push_back(rmax[i]);
    }

    for (int i = 0; i < v.size(); i++)
    {
        water += min(lmax[i], right_max[i]) - v[i];
    }

    return water;
}

void opt_water_tap(vector<int> v)
{
    int lmax = 0;
    int rmax = v.size() - 1;
    int water=0;
    for(int i=0;i<v.size();i++){

        water+=min(v[lmax],v[rmax])-v[i];

    }
}
int main()
{
    vector<int> v = {10, 0, 0, 0, 0, 10};
    cout << "The amount of water is " << trapping_water(v) << " Liters";
    cout << "\n";
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i]; j++)
        {
            cout << "*";
        }
        cout << "\n";
    }

    return 0;
}