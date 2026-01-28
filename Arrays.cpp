#include <iostream>
#include <vector>

void InsertIntoAnArray(int Arr[10], int value, int indx, int &LastFilledIndx)
{
    for (int i = 0; i <= LastFilledIndx; i++)
    {
        std::cout << "i: " << i << " Value: " << Arr[i] << "\n";
    }

    int currIndx = LastFilledIndx;

    // if (currIndx == Arr.Length() - 1)
    //     return;
    for (int i = LastFilledIndx; i >= indx; i--)
    {

        if (currIndx == indx)
        {
            Arr[currIndx + 1] = Arr[currIndx];

            Arr[currIndx] = value;
            LastFilledIndx++;
            break;
        }
        Arr[currIndx + 1] = Arr[currIndx];
        currIndx--;
    }

    std::cout << "\n\n\n\n";

    for (int i = 0; i <= LastFilledIndx + 1; i++)
    {
        std::cout << "i: " << i << " Value: " << Arr[i] << "\n";
    }
}

void Deletion(int Arr[10], int DeletionIndx, int &LastFilledIndx)
{

    int currIndx = DeletionIndx;

    for (int i = currIndx; i < LastFilledIndx; i++)
    {

        Arr[currIndx] = Arr[currIndx + 1];

        currIndx++;
    }

    LastFilledIndx--;
}

void rotate(std::vector<int> &nums, int k)
{

    std::vector<int> ans;


    for (int i = nums.size() - k; i < nums.size(); i++)
    {
        ans.push_back(nums[i]);

      
    }

    for (int i = 0; i < nums.size() - k; i++)
    {
        ans.push_back(nums[i]);
   
    }

    nums = ans;
}

void Update(int Arr[10], int indx, int value)
{

    Arr[indx] = value;
}

int main()
{
    using namespace std;

    int Arr[10] = {1, 2, 3, 4, 5, 6, 7};

    int LastIndx = 6;
    // InsertIntoAnArray(Arr, 12, 0, LastIndx);

    vector<int> nums = {1, 2, 3, 4, 56, 7, 89, 99};
    for (int i : nums)
    {
        cout << i << "\n";
    }

    rotate(nums, 3);

    cout<<"\n\n\n\n";

    
    for (int i : nums)
    {
        cout << i << "\n";
    }
}
