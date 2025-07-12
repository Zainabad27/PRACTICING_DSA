#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;
int first_non_rep(string str)
{
    unordered_multimap<char, int> m;
    for (int i = 0; i < str.size(); i++)
    {
        m.insert({str[i], i});
    }

    for (int i = 0; i < str.size(); i++)
    {
        if (m.count(str[i]) == 1)
        {
            return i;
        }
    }

    return -1;
}

int f_n_r(string str)
{
    queue<pair<char, int>> q1;
    q1.push({str[0], 0});
    for (int i = 1; i < str.length(); i++)
    {
        q1.push({str[i],i});
        if (q1.front().first == str[i])
        {
            q1.pop();
        }
    }
    if (q1.empty())
    {
        return -1;
    }
    else
    {
        return q1.front().second;
    }
}
int main()
{
    cout << f_n_r("level");
    return 0;
}