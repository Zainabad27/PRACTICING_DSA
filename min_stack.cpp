#include <iostream>
#include <stack>

using namespace std;
class min_stack
{
    stack<int> st;
    int min_val;

public:
    void push(int val)
    {
        if (st.empty())
        {
            st.push(val);
            min_val = val;
        }
        else
        {
            if (val >= min_val)
            {
                st.push(val);
            }
            else
            {
                st.push(2 * val - min_val);
                min_val = val;
            }
        }
    }
    void pop()
    {
        if (st.top() < min_val)
        {
            min_val = 2 * min_val - st.top();
            st.pop();
        }
        else
        {
            st.pop();
        }
    }

    int top()
    {
        if (st.top() < min_val)
        {
            return min_val;
        }
        else
        {
            return st.top();
        }
    }
    int get_min()
    {
        return min_val;
    }
};
int main()
{

    return 0;
}