#include <iostream>
#include <vector>

#include <stack>
using namespace std;

template <typename T>

class Mystack
{
private:
    int head = -1;
    vector<T> container;

public:
    void pushback(T value)
    {
        container.push_back(value);
        head++;
    }
};

int absolute(int num)
{
    if (num < 0)
        return (num * -1);
    return num;
}

bool sameSign(int a, int b)
{
    if ((a * b) < 0)
        return false;
    else
        return true;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
vector<int> asteroidCollision(vector<int> asdteroids)
{

    stack<int> ans;
    ans.push(asdteroids[0]);

    for (int i = 1; i < asdteroids.size(); i++)
    {
        if (!sameSign(ans.top(), asdteroids[i]))
        {
            //     int stVal = absolute(ans.top());
            //     int asteroidVal = absolute(asdteroids[i]);
            //     if(asteroidVal>stVal){
            //         ans.pop();

            //     }

            while (i < asdteroids.size())
            {
                if (ans.size() == 0)
                {
                    ans.push(asdteroids[i]);
                    i++;
                    continue;
                }

                int stVal = absolute(ans.top());
                int astdVal = absolute(asdteroids[i]);
                if (astdVal > stVal)
                {
                    ans.pop();
                    ans.push(asdteroids[i]);
                    i++;
                }
                else if (astdVal == stVal)
                {
                    ans.pop();
                    i++;
                }
                else
                {
                    i++;
                }
            }
        }
        else
        {
            ans.push(asdteroids[i]);
        }
    }

    vector<int> final_ans;
    for (int i = 0; i < ans.size(); i++)
    {
        final_ans.push_back(ans.top());
        ans.pop();
    }

    int st = 0;
    int end = final_ans.size() - 1;

    while (st < end)
    {
        swap(final_ans[st], final_ans[end]);
        st++;
        end--;
    }



    return final_ans;
}
int main()
{

    return 0;
}