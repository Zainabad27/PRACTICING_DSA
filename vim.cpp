
#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int totalElements = matrix.size() * matrix[0].size();
    vector<int> ans;
    int startingrow = 0;
    int lastrow = matrix.size() - 1;

    int startingcol = 0;
    int lastcol = matrix[0].size() - 1;

    int row = 0;
    int col = 0;

    while (startingcol <= lastcol || startingrow <= lastrow)
    {
        if (ans.size() == totalElements)
            return ans;

        // loop that runs forward
        while (col <= lastcol)
        {
            ans.push_back(matrix[row][col]);
            col++;
        }
        col--;

        row++;
        startingrow++;
        // loop that runs downwards

        // we have to put some condition here so that if we are in the last iteration our loop breaks here bro.
        if (ans.size() == totalElements)
            return ans;

        while (row <= lastrow)
        {
            ans.push_back(matrix[row][col]);
            row++;
        }
        row--;

        col--;
        lastcol--;

        if (ans.size() == totalElements)
            return ans;

        // loop that runs backward
        while (col >= startingcol)
        {
            ans.push_back(matrix[row][col]);
            col--;
        }
        col++;

        row--;
        lastrow--;

        if (ans.size() == totalElements)
            return ans;
        // loop that runs upward
        while (row >= startingrow)
        {
            ans.push_back(matrix[row][col]);
            row--;
        }
        row++;

        col++;
        startingcol++;
    }

    return ans;
}

int main()
{
    // vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    vector<vector<int>> matrix = {{1, 2, 3}, {5, 6, 7}, {9, 8, 7}};

    vector<int> ans = spiralOrder(matrix);

    cout << "Resultant answer.\n";
    for (int i : ans)
    {
        cout << i << " ";
    }

    return 0;
}