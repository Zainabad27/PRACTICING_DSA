#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int find_celeb(vector<vector<int>> mat)
{
    vector<int> celeb_indx;

    int nrow = mat.size();
    int ncol = mat[0].size();
    for (int i = 0; i < nrow; i++)
    {
        bool know = false;
        int count = 0;
        for (int j = 0; j < ncol; j++)
        {
            if (mat[i][j] == 1)
            {
                count++;
            }
            if (count > 1)
            {
                know = true;
                break;
            }
        }
        if (!know)
        {
            celeb_indx.push_back(i);
        }
    }
    if (celeb_indx.empty())
    {
        return -1;
    }
    else
    {
        bool celeb = true;
        for (int i = 0; i < celeb_indx.size(); i++)
        {
            for (int j = 0; j < nrow; j++)
            {
                if (mat[j][celeb_indx[i]] == 0)
                {
                    celeb = false;
                }
            }
            if (celeb)
            {
                return celeb_indx[i];
            }
        }
        return -1;
    }
}
int find_celeb_2(vector<vector<int>> mat)
{
    int n = mat.size();

    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        st.push(i);
    }
    int i, j;
    while (st.size() > 1)
    {
        i = st.top();
        st.pop();
        j = st.top();
        st.pop();
        if(mat[i][j]==0){
            //eliminate j
            st.push(i);

        }
        else{
            // eliminate i
            st.push(j);

        }
    }
    int count=0;
    for(int i=0;i<n;i++){
        if(mat[i][st.top()]==0){
            count++;
        }
        if(mat[st.top()][i]==1){
            count++;
        }

    }
    if(count>1){
        return -1;
    }
    return st.top();
}
int main()
{
    vector<vector<int>> mat = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 1, 0}};

    cout << find_celeb_2(mat);
    return 0;
}