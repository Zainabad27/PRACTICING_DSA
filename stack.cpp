#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;
bool valid_parenthesis(string s)
{
    //"{[()]}"
    if (s.size() % 2 != 0)
    {
        return false;
    }

    char b1, b2, b3, inb1, inb2, inb3;
    b1 = '[';
    b2 = '{';
    b3 = '(';
    inb1 = ']';
    inb2 = '}';
    inb3 = ')';

    int st = 0;
    int end = s.size() - 1;
    while (st <= end)
    {
        if (s[st] == b1)
        {
            if (s[end] != inb1)
            {
                return false;
            }
        }
        else if (s[st] == b2)
        {
            if (s[end] != inb2)
            {
                return false;
            }
        }
        else if (s[st] == b3)
        {
            if (s[end] != inb3)
            {
                return false;
            }
        }

        st++;
        end--;
    }
    return true;
}
bool validparenthesis(string s)
{
    if (s.size() % 2 != 0)
    {
        return false;
    }

    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(')
        {
            st.push(s[i]);
        }
        if (s[i] == '}')
        {
            if (st.top() != '{')
            {
                return false;
            }
            else
            {
                st.pop();
            }
        }
        else if (s[i] == ']')
        {
            if (st.top() != '[')
            {
                return false;
            }
            else
            {
                st.pop();
            }
        }
        else if (s[i] == ')')
        {
            if (st.top() != '(')
            {
                return false;
            }
            else
            {
                st.pop();
            }
        }
    }
    return true;
}

vector<int> stock_span(vector<int> stock)
{ // stock={43,66,64,83,55,100,20,203,98,27};
    vector<int> ans;
    int p_high = stock.size() - 1;

    for (int i = stock.size() - 1; i >= 0; i--)
    {
        while (stock[i] >= stock[p_high])
        {
            if (i == 0)
            {
                break;
            }
            p_high--;
        }
        if (i == 0)
        {
            ans.push_back(1);
            break;
        }
        ans.push_back(i - p_high);
        if (i > 0)
        {
            p_high = i - 1;
        }
    }

    vector<int> rans;
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        rans.push_back(ans[i]);
    }
    return rans;
}

void next_grt_element(vector<int> arr, vector<int> arr2)
{
    vector<int> rans;

    stack<int> st;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        while (st.size() > 0 && st.top() < arr[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            rans.push_back(-1);
            st.push(arr[i]);
        }
        else
        {
            rans.push_back(st.top());
            st.push(arr[i]);
        }
    }
}

vector<int> nxt_grt_element(vector<int> nums1, vector<int> nums2)
{
    stack<int> st;
    vector<int> rans;
    

}
int main()
{

    return 0;
}