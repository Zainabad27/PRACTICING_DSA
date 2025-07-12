#include <iostream>
#include <vector>
using namespace std;
vector<int> result_mat;
void colsum()
{
    int mat[3][3] = {{199, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int rows = 3;
    int cols = 3;

    int max_col_total = 0;

    for (int i = 0; i < cols; i++)
    {
        int current_col_sum = 0;
        for (int j = 0; j < rows; j++)
        {
            current_col_sum += mat[j][i];
        }

        if (current_col_sum > max_col_total)
        {
            max_col_total = current_col_sum;
        }
    }
    cout << "Total is: " << max_col_total;
}
void diagonalsum()
{
    int mat[5][5] = {{199, 2, 3, 7, 3}, {4, 5, 2, 4, 6}, {7, 8, 2, 6, 9}, {12, 32, 34, 55, 77}, {21, 3, 4, 78, 7}};
    // int mat[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int rows, cols;
    rows = cols = 5; // always a square matrix.
    int primary_diagonal_sum = 0;
    for (int i = 0; i < rows; i++)
    {
        primary_diagonal_sum += mat[i][i];
    }
    int secondary_diagonal_sum = 0;
    int j = cols;
    for (int i = 0; i < rows; i++)
    {

        if (i != j - 1 - i)
        {
            secondary_diagonal_sum += mat[i][j - 1 - i];
        }
    }
    cout << primary_diagonal_sum + secondary_diagonal_sum;
}
void matrix_product()
{
    int mat1[2][2] = {{199, 2}, {4, 5}};
    int mat2[2][2] = {{1, 2}, {3, 4}};
    int mat3[2][2];

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                mat3[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}
void matrix_sum()
{
    int mat1[2][2] = {{1, 2}, {3, 4}};
    int mat2[2][2] = {{5, 6}, {7, 4}};
    int result_mat[2][2];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            result_mat[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}
void matrix_subtraction()
{
    int mat1[2][2] = {{1, 2}, {3, 4}};
    int mat2[2][2] = {{5, 6}, {7, 4}};
    int result_mat[2][2];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            result_mat[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}
bool search_2darray(int mat[][4], int rows, int cols, int target)
{
    // int mat[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    //  for(int i=0;i<rows;i++){
    //      for(int j=0;j<cols;j++){
    //          cout<<mat[i][j]<<" ";
    //      }
    //      cout<<endl;
    //  }

    for (int i = 0; i < rows; i++)
    {
        if (target <= mat[i][0])
        {
            if (mat[i][0] == target)
            {
                cout << "your index is: " << i << "," << 0 << endl;
                return true;
            }
            else
            {
                for (int k = 0; k < cols; k++)
                {
                    if (mat[i - 1][k] == target)
                    {
                        cout << "your index is: " << "(" << i - 1 << "," << k << ")" << endl;
                        return true;
                    }
                }
            }
        }
    }
    for (int i = 0; i < cols; i++)
    {
        if (target == mat[rows - 1][i])
        {
            cout << "your index is: " << "(" << rows - 1 << "," << i << ")" << endl;
            return true;
        }
    }
    cout << "not found." << endl;
    return false;
}
bool binary_search(int mat[][4], int target_row, int total_cols, int target)
{
    int scol = 0;
    int ecol = total_cols - 1;
    while (scol <= ecol)
    {
        int mcol = (scol + ecol) / 2;
        if (target == mat[target_row][mcol])
        {
            return true;
        }
        else if (target > mat[target_row][mcol])
        {
            scol = mcol + 1;
        }
        else
        {
            ecol = mcol - 1;
        }
    }
    return false;
}

bool binary_search_2darray(int mat[][4], int rows, int cols, int target)
{
    int srow = 0;
    int erow = rows - 1;

    while (srow <= erow)
    {
        int mrow = (srow + erow) / 2;
        if (target >= mat[mrow][0] && target <= mat[mrow][cols - 1])
        {
            return binary_search(mat, mrow, cols, target);
        }
        else if (target < mat[mrow][0])
        {
            erow = mrow - 1;
        }
        else
        {
            srow = mrow + 1;
        }
    }
    return false;
}
bool search_matrix(int mat[][5], int target, int rows, int cols)
{
    int row = rows - 1;
    int col = 0;
    while (row >= 0 && col <= cols - 1)
    {
        if (target == mat[row][col])
        {
            return true;
        }
        else if (target < mat[row][col])
        {
            row--;
        }
        else
        {
            col++;
        }
    }
    return false;
}
void spiral_matrix(vector<vector<int>>& mat,vector<int>& result)
{

    int rows = mat.size(), cols = mat[0].size();
    int f_row = 0, f_col = 0, l_row = rows - 1, l_col = cols - 1;

    //vector<int> result;
    while (f_row <= l_row && f_col <= l_col)
    {

        for (int i = f_col; i <= l_col; i++)
        {
            result.push_back(mat[f_row][i]);
        }
        
        for (int i = f_row; i <= l_row; i++)
        {
            result.push_back(mat[i][l_col]);
        }
        
        for (int i = l_col; i >= f_col; i--)
        {
            result.push_back(mat[l_row][i]);
        }
       
        for (int i = l_row; i >= f_row; i--)
        {
            result.push_back(mat[i][f_col]);
        }
        f_row++;f_col++;l_col--; l_row--;
    }
    cout << "The size of the vector is: " << result.size();
}

int main()
{ // use of some other functions ignore these please.
    // int mat[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    //  cout<<mat[2][0];
    // cout << binary_search_2darray(mat, 3, 4, 22);
    //  int mat[5][5]={{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    //  cout<<search_matrix(mat,15,5,5);

    vector<vector<int>> mat = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    spiral_matrix(mat,result_mat);
    for (int i : result_mat)
    {
        cout << i << " " << endl;
    }

    return 0;
}