#include <iostream>
#include <unordered_map>
#include <queue>
#include <string>

using namespace std;












//// i have to use found ////////////////////////////////////////////////////////////////////////////////////////////

int lengthOfLongestSubstring(string s)
{

    if (s.empty())
        return 0;
    // solvinng it by increasing sliding window concept with the help of
    // hashing to lookup inside the window.

    int stringSize = s.size();

    unordered_map<char, bool> seen;
    for (char c = 'a'; c <= 'z'; c++)
    {
        seen[c] = false;
    }
    for (char c = 'A'; c <= 'Z'; c++)
    {
        seen[c] = false;
    }
    for (char c = '0'; c <= '9'; c++)
    {
        seen[c] = false;
    }

    seen[' '] = false;
    queue<char> window;

    int start = 0;

    // populating the initial window.

    for (int i = start; i < stringSize; i++)
    {
        if (!seen[s[i]])
        {
            seen[s[i]] = true;
            window.push(s[i]);
        }
        else
        {
            // window.pop();
            break;
        }
    }


    if(s.size()==window.size()) return window.size();

    for (int i = 0; i < stringSize - (start+window.size() -1); i++)
    {
        if (!seen[s[start + window.size()]])
        {
            seen[s[start + window.size()]] = true;
            window.push(s[start + window.size()]);
        }
        else
        {
            window.pop();

            window.push(s[start + window.size()]);
            start++;
        }
    }

    return window.size();
}

int main()
{

    int ans = lengthOfLongestSubstring("aazqi");

    cout << ans << "<=======this is the answer" << endl;

    return 0;
}