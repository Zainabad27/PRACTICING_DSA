#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;
// sum of repetetive elements.
void sum_repetetive_elements()
{

  int sum = 0;
  vector<int> a = {1, 1, 1, 2, 2, 3, 4, 5, 5, 5, 5, 5};
  map<int, int> m;
  m = {{1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}};

  for (int i = 0; i < a.size(); i++)
  {
    m[a[i]]++;
  }
  for (auto pair : m)
  {
    if (pair.second > 1)
    {
      sum += pair.first;
    }
  }
  cout << sum;
}

vector<int> two_sum(vector<int> arr, int target)
{
  vector<int> ans;
  unordered_map<int, int> m;
  for (int i = 0; i < arr.size(); i++)
  {
    int first = arr[i];
    int second = target - first;
    if (m.find(second) != m.end())
    {
      ans.push_back(i);
      ans.push_back(m[second]);
      return ans;
    }
    m[first] = i;
  }
}

void findmrvals(vector<vector<int>> mat)
{

  // int repeated;
  // int missing;
  // for (int k = 1; k <= mat.size() * mat.size(); k++)
  // {
  //   int counter = 0;
  //   bool found=false;
  //   for (int i = 0; i < mat.size(); i++)
  //   {
  //     for (int j = 0; j < mat[0].size(); j++)
  //     {
  //       if (mat[i][j] == k)
  //       {
  //         counter++;
  //         found=true;
  //       }
  //       if (counter > 1)
  //       {
  //         repeated = k;
  //         break;
  //       }

  //     }
  //   }
  //   if(!found){
  //     missing=k;

  //   }
  // }
  // cout<<"Repeated: "<<repeated<<endl<<"Missing: "<<missing<<endl;

  // optimized approach.

  unordered_map<int, int> m;
  for (int i = 1; i <= mat.size() * mat.size(); i++)
  {
    m[i] = 0;
  }
  for (int i = 0; i < mat.size(); i++)
  {
    for (int j = 0; j < mat[0].size(); j++)
    {
      m[mat[i][j]]++;
    }
  }

  for (auto it = m.begin(); it != m.end(); ++it)
  {
    if (it->second == 0)
    {
      cout << "Missing: " << it->first << endl;
    }
    else if (it->second > 1)
    {
      cout << "Repeated: " << it->first << endl;
    }
  }
}
void s_approach(vector<vector<int>> v)
{
  int a;
  int act_sum = 0;
  int idl_sum = 0;
  vector<int> ans;
  set<int> s;
  for (int i = 0; i < v.size(); i++)
  {
    for (int j = 0; j < v.size(); j++)
    {
      act_sum += v[i][j];

      if (s.find(v[i][j]) != s.end())
      {
        a = v[i][j];
        ans.push_back(a);
      }
      s.insert(v[i][j]);
    }
  }
  for (int i = 1; i <= v.size() * v.size(); i++)
  {
    idl_sum += i;
  }
  // act_sum=idl_sum +a-b
  // idl_sum-act_sum+a=b
  int b = idl_sum + a - act_sum;
  ans.push_back(b);

  for (int i : ans)
  {
    cout << i << " ";
  }
}
// arr={1,24,5,35,7,6,54,4,8,7,5,2};
// target=8;
int repeating_alement(vector<int> arr)
{
  unordered_map<int, int> m;
  for (int i = 0; i < arr.size(); i++)
  {
    if (m.find(arr[i]) != m.end())
    {
      return arr[i];
    }
    m[arr[i]] = 1;
  }

  return -1;
}

void three_sum(vector<int> arr)
{
  set<vector<int>> s;

  for (int i = 0; i < arr.size(); i++)
  {
    unordered_map<int, int> m;
    for (int j = i + 1; j < arr.size(); j++)
    {
      int tar = -arr[i] - arr[j];
      if (m.find(tar) != m.end())
      {
        vector<int> ans = {arr[i], arr[j], tar};
        sort(ans.begin(), ans.end());
        s.insert(ans);
      }

      m[arr[j]] = j;
    }
  }
}
void three_sum2(vector<int> arr)
{
  vector<int> ans;
  sort(arr.begin(), arr.end());
  for (int i = 0; i < arr.size(); i++)
  {
    if (i > 0 && arr[i] == arr[i - 1])
      continue;
    int j = i + 1;
    int k = arr.size() - 1;
    while (j < k)
    {
      if (arr[i] + arr[j] + arr[k] > 0)
        k--;
      else if (arr[i] + arr[j] + arr[k] < 0)
        j++;
      else
      {
        ans.push_back(arr[i]);
        ans.push_back(arr[j]);
        ans.push_back(arr[k]);
        k--;
        j++;
        while (j < k && arr[j] == arr[j - 1])
          j++;
      }
    }
  }
}
void four_sum(vector<int> arr, int tar)
{
  for (int i = 0; i < arr.size(); i++)
  {
    for (int j = i + 1; j < arr.size(); j++)
    {
      int x = j + 1;
      int y = arr.size() - 1;

      int sum = arr[i] + arr[j] + arr[x] + arr[y];
      while (x < y)
      {
        if (sum > tar)
          y--;
        else if (sum < tar)
          x++;
        else
        {
        }
      }
    }
  }
}

void four_sum2(vector<int> arr, int tar)
{
  vector<int> ans;
  for (int i = 0; i < arr.size(); i++)
  {
    for (int j = i + 1; j < arr.size(); j++)
    {
      int x = j + 1;
      int y = arr.size() - 1;
      int sum = arr[i] + arr[j] + arr[x] + arr[y];

      while (x < y)
      {
        if (sum > tar)
          y--;
        else if (sum < tar)
          x++;
        else
        {
          ans.push_back(arr[i]);
          ans.push_back(arr[j]);
          ans.push_back(arr[x]);
          ans.push_back(arr[y]);
          y--;
          x++;
        }
      }
    }
  }
}

int main()
{
  vector<int> arr = {3, -2, 0, 1, 2, 3, 4, 5, 6, 8, 9};
  vector<int> r;

  for (int i : r)
  {
    cout << i << " ";
  }
}