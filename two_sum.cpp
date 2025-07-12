#include <iostream>
using namespace std;
bool two_sum(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (i < size - 1)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (arr[i] + arr[j] == target)
                {
                    return true;
                }
            }
        }
    }
    return false;
}
int main()
 {
   
    return 0;
  
}