#include <iostream>
#include <vector>

using namespace std;

void bubble_sort(int arr[], int size)
{

      for (int i = 0; i < size - 1; i++)
      {

            bool sorted = true;
            for (int j = 0; j < size - i - 1; j++)
            {
                  if (arr[j] > arr[j + 1])
                  {
                        sorted = false;
                        swap(arr[j], arr[j + 1]);
                  }
            }
            if (sorted)
            {
                  break;
            }
      }
}
void selection_sort(int arr[], int size)
{
      for (int i = 0; i < size - 1; i++)
      {
            int smallest = i;
            for (int j = i + 1; j < size; j++)
            {

                  if (arr[j] < arr[smallest])
                  {
                        smallest = j;
                  }
            }
            swap(arr[i], arr[smallest]);
      }
}
void sort(int arr[], int size)
{ // sorting 0s, 1s and 2s
      int count_0 = 0, count_1 = 0, count_2 = 0;
      for (int i = 0; i < size; i++)
      {
            if (arr[i] == 0)
            {
                  count_0++;
            }
            else if (arr[i] == 1)
            {
                  count_1++;
            }
            else
            {
                  count_2++;
            }
      }
      for (int i = 0; i < count_0; i++)
      {
            arr[i] = 0;
      }
      for (int i = count_0; i < count_0 + count_1; i++)
      {
            arr[i] = 1;
      }
      for (int i = count_0 + count_1; i < count_0 + count_1 + count_2; i++)
      {
            arr[i] = 2;
      }
}
void sort_by_dnf(int arr[], int size)
{ // sorting 0s, 1s and 2s
      int mid, high;
      int low = 0;
      mid = 0;
      high = size - 1;
      while(mid<=high)
      {
            if (arr[mid] == 0)
            {
                  swap(arr[low],arr[mid]);
                  low++;
                  mid++;
            }
            else if (arr[mid] == 1)
            {
                  //swap(arr[mid],arr[i]);
                  mid++;
            }
            else if (arr[mid] == 2)
            {
                  swap(arr[mid],arr[high]);
                  high--;
                  
            }
      }
}
int main()
{
      // int arr[5] = {1, 2, 3, 5, 4};
      int arry[10] = {2, 2, 2, 2, 0, 0, 1, 2, 1, 1};
      // bubble_sort(arr, 5);
      // selection_sort(arry, 10);
      // for (int i : arry)
      // {
      //       cout << i << " ";
      // }
      sort_by_dnf(arry, 10);
      for (int i : arry)
      {
            cout << i << " ";
      }

      return 0;
}