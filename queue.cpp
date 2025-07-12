#include <iostream>
#include <stack>
#include <queue>
using namespace std;
class mystack
{
    queue<int> q1, q2;
    int stack_size = 0;

public:
    void push(int val)
    {
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(val);
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }
    int top()
    {
        return q1.front();
    }
    void pop()
    {
        q1.pop();
    }
};

class myqueue
{
    stack<int> st1, st2;

public:
    void push(int val)
    {
        while (!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
        st1.push(val);
        while (!st2.empty())
        {
            st1.push(st2.top());
            st1.pop();
        }
    }
};
int main()
{
    return 0;
}