#include <iostream>
#include <vector>
using namespace std;
bool binary_search(vector<int> arr, int start, int end, int target)
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target)
        {
            return true;
        }
        else if (arr[mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return false;
}
bool rotated_array(vector<int> arr, int start, int end, int target)
{
    if (start > end)
    {
        return false;
    }

    int mid = start + (end - start) / 2;
    if (arr[mid] == target)
    {
        return true;
    }
    if (arr[start] < arr[mid]) // left region is sorted.
    {
        if (target >= arr[start] && target < arr[mid]) // if target is present in sorted array region.
        {                                              // binary searching in the right region.
            return binary_search(arr, start, mid - 1, target);
        }
        else
        {
            return rotated_array(arr, mid + 1, end, target);
        }
    }
    else
    {
        // if right region is sorted.
        if (target > arr[mid] && target <= arr[end])
        {
            // binary search in the left region.
            return binary_search(arr, mid + 1, end, target);
        }
        else
        {
            return rotated_array(arr, start, mid - 1, target);
        }
    }

    return false;
}
int peak_mountain_element(vector<int> arr)
{
    int st = 1;
    int end = arr.size() - 2;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
        {
            return arr[mid];
        }
        else if (arr[mid - 1] < arr[mid] && arr[mid] < arr[mid + 1])
        {
            st = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
}
int single_element(vector<int> arr)
{ /* we are tracking the pair of elements if the last element of a certain
     pair is at even index that means the single element appears before the mid else it appears after the mid.(think about it yourself.)*/
    int st = 0;
    int end = arr.size() - 1;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (mid == 0 && arr[mid] != arr[mid + 1])
        {
            return arr[0];
        }
        if (mid == end && arr[mid] != arr[end - 1])
        {
            return arr[end];
        }
        if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1])
        {
            return arr[mid];
        }
        else if (arr[mid] == arr[mid - 1]) // mid is on the last element of the pair so now we will check the index of the element
        {
            if (mid % 2 == 0)
            { // our last element of pair is at even index means single element is before the mid, so updating the end
                end = mid - 1;
            }
            else
            {
                st = mid + 1;
            }
        }
        else if (arr[mid] == arr[mid + 1])
        { // mid+1 is the last element of the pair
            if ((mid + 1) % 2 == 0)
            {
                end = mid - 1;
            }
            else
            {
                st = mid + 1;
            }
        }
    }
    return -1;
}
void book_allocation(vector<int> arr, int students)
{
    if (students > arr.size()) // not possible.
    {
        return;
    }
}
int main()
{
    // vector<int> v = {2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 8, 8, 9, 9, 10, 10};
    //     cout << rotated_array(v, 0, v.size() - 1, 77);
    //    cout << peak_mountain_element(v);
    //    cout<<single_element(v);
    vector<int> v = {10, 22, 33, 11, 34, 23};

    return 0;
}