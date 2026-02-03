#include <iostream>

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void BubbleSort(int arr[], int n)
{
    for (int i = 0; i < n-1; i++)
    {

        for (int j = 0; j < n - i-1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

void InserionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int curr = arr[i];

        int j = i - 1;

        while (j >= 0 && arr[j] > curr)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = curr;
    }
}
void SelectionSort(int Arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        int min = i;

        for (int j = i; j < n; j++)
        {
            if (Arr[j] < Arr[min])
            {
                // Swap(Arr[i], Arr[j]);
                min = j;
            }
        }

        swap(Arr[i], Arr[min]);
    }
}

void PrintArr(int Arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << i << " : " << Arr[i] << "\n";
    }
}

int main()
{

    int Arr[10] = {0, 0, 0, 0, 0, 2, 0, 0, 0, -1};
    PrintArr(Arr, 10);

    BubbleSort(Arr, 10);

    std::cout << "\n\nAfter Sorting." << "\n\n";

    PrintArr(Arr, 10);

    return 0;
}