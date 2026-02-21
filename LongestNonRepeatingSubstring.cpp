#include <iostream>
#include <unordered_set>
#include <queue>
#include <string>

using namespace std;

int LongestNonRepeatingSubstring2(string s)
{
    // unordered_set<char> seen;

    vector<bool> seen(128, false);

    int length = 0;

    int start = 0;
    int end = 0;

    for (int end= start; end < s.size(); end++)
    {

        while (seen[s[end]])
        {
            seen[s[start]]=false;
            start++;
        }

        seen[s[end]] = true;

        

        length = max(length, end - start + 1);
    }


    return length;
}

int main()
{



    // cout << ans << "<=======this is the answer" << endl;

    return 0;
}