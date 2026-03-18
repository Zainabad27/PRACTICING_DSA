#include <iostream>
#include <stack>
using namespace std;

// string reversal using stack

string reverse(string words)
{
    stack<char> st;

    for (char word : words)
    {
        st.push(word);
    }
    for (int i = 0; i < words.size(); i++)
    {
        words[i] = st.top();
        st.pop();
    }



   return words;
}
int main()
{

    string rev=reverse("zain");

    cout<<rev<<"\n";

    return 0;
}