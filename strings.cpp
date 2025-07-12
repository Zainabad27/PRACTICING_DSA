#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;
void reverse_string(string abc)
{
    int st = 0;
    int end = abc.length() - 1;
    while (st <= end)
    {
        swap(abc[st++], abc[end--]);
    }
    cout << abc << endl;
}
bool is_palindrome(string s)
{
    int low = 0, high = s.length() - 1;

    while (low < high)
    {
        if (!isalnum(s[low]))
        {
            low++;
            continue;
        }
        if (!isalnum(s[high]))
        {
            high--;
            continue;
        }
        if (tolower(s[low]) != tolower(s[high]))
        {
            cout << s << endl
                 << "0 for no" << endl;
            cout << "1 for yes: ";
            return false;
        }
        low++;
        high--;
    }
    cout << s << endl
         << "0 for no" << endl;
    cout << "1 for yes: ";
    return true;
}
void remove_occurance(string s, string part)
{
    int word_length = part.length();
    bool occur = false;
    for (int i = 0; i < s.length(); i++)
    {
        occur = true;
        for (int j = 0; j < word_length; j++)
        {
            if (s[i + j] != part[j])
            {
                occur = false;
            }
        }
        if (occur)
        {
            for (int j = 0; j < word_length; j++)
            {
                s[i + j] = ' ';
            }
        }
    }
    cout << s << endl;
}
void remove_part(string s, string part)
{
    while (s.length() > 0 && s.find(part) < s.length())
    {
        if (s.find(part) < s.length())
        {
            s.erase(s.find(part), part.length());
        }
    }
    cout << s << endl;
}
bool is_same_freq(int freq1[], int freq2[])
{
    for (int i = 0; i < 26; i++)
    {
        if (freq1[i] != freq2[i])
        {
            return false;
        }
    }

    return true;
}
bool permutation_in_string(string s, string per_part)
{

    int freq[26] = {0};

    for (int i = 0; i < per_part.length(); i++)
    { // count the frequencies in permutation part
        freq[per_part[i] - 'a']++;
    }
    int wind_size = per_part.length();
    for (int i = 0; i < s.length(); i++)
    {
        int freq_wind[26] = {0};
        int wind_indx = 0;
        int indx = i;
        while (wind_indx < wind_size && indx < s.length())
        {
            freq_wind[s[indx] - 'a']++;
            wind_indx++;
            indx++;
        }
        if (is_same_freq(freq, freq_wind))
        {
            return true;
        }
    }
    return false;
}
string reverse_string(string s, int size)
{
    int num_words = 1;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            num_words++;
        }
    }

    vector<string> list;
    int j = 0;

    for (int i = 0; i < num_words; i++)
    {
        string word;

        while (s[j] != ' ' && j < s.length())
        {
            word += s[j];
            j++;
        }
        if (s[j] == ' ')
        {
            j++;
        }
        list.push_back(word);
    }
    string result;
    for (int i = num_words - 1; i >= 0; i--)
    {
        cout << list[i] << " ";
        result += list[i];
        result += " ";
    }
    return result;
}
void compress_array(vector<char> arr)
{
    // char character_count='0';
    // char current=arr[0];

    int insert_at = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        int character_count = 0;
        char current = arr[i];

        while (i < arr.size() &&arr[i] == current)
        {
            character_count++;
            i++;
        }
        i--;
        // becuase i is getting increment at both while and for loop so we cancel out one of them.
        if (character_count == 1)
        {
            arr[insert_at] = current;

            insert_at++;
        }
        else if(character_count != 1)
            {
                arr[insert_at] = current;

                insert_at++;
                string str = to_string(character_count);
                for(char i: str){
                arr[insert_at] = i;

                insert_at++;
            }
            }

        // current=arr[i];
    }
    arr.resize(insert_at);
    for (char i : arr)
    {
        cout << i << " ";
    }
}
int main()
{
    vector<char> arry = {'a', 'a', 'a', 'a', 'c', 'c','c','c','c', 'c', 'c', 'f', 'f', 'f'};
    compress_array(arry);

    return 0;
}