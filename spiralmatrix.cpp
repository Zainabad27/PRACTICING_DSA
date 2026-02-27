#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> ans;
    int startingrow = 0;
    int lastrow = matrix.size() - 1;

    int startingcol = 0;
    int lastcol = matrix[0].size() - 1;

    int row = 0;
    int col = 0;

    while (startingcol != lastcol && startingrow != lastrow)
    {

        // loop that runs forward
        while (col <= lastcol)
        {
            ans.push_back(matrix[row][col]);
            col++;
        }

        row++;
        startingrow++;
        // loop that runs downwards

        while (row <= lastrow)
        {
            ans.push_back(matrix[row][col]);
            row++;
        }
        col--;
        lastcol--;

        // loop that runs backward
        while (col >= startingcol)
        {
            ans.push_back(matrix[row][col]);
            col--;
        }

        row--;
        lastrow--;

        // loop that runs upward
        while (row >= startingrow)
        {
            ans.push_back(matrix[row][col]);
            row--;
        }
        col++;
        startingcol++;
    }

    return ans;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

    vector<int> ans = spiralOrder(matrix);

    cout << "Resultant answer.\n";
    for (int i : ans)
    {
        cout << i << " ";
    }

    return 0;
}