#include <iostream>
#include <vector>
using namespace std;
bool is_prime(int n)
{
    for (int i = 2; i * i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

void num_of_primes(int n)
{
    vector<bool> primes(n, true);
    for (int i = 2; i < primes.size(); i++)
    {
        for (int j = i * 2; j <= n; j = j + i)
        {
            primes[j] = false;
        }
    }
    for (int i = 2; i < n; i++)
    {
        if (primes[i])
        {
            cout << i << " ";
        }
    }
}

string is_armstrong(int n)
{
    int real_n = n;
    int dig;
    int total_sum = 0;
    while (n != 0)
    {
        dig = n % 10;
        total_sum += (dig * dig * dig);

        n = n / 10;
    }

    if (total_sum == real_n)
    {
        return "yes lil bro";
    }
    return "no big bro";
}
int euclid_algorithm(int a, int b)
{

    if (a == 0)
    {
        return b;
    }
    else if (b == 0)
    {
        return a;
    }

    while (a != 0 && b != 0)
    {
        if (a > b)
        {
            a = a % b;
        }
        else if (a < b)
        {
            b = b % a;
        }
        else
        {
            a == a - b;
        }
    }
    if (a == 0)
    {
        return b;
    }
    else if (b == 0)
    {
        return a;
    }
}
int gcd_recurrsion(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    else if (b == 0)
    {
        return a;
    }
    if (a > b)
    {
        return gcd_recurrsion(a % b, b);
    }
    else if (b > a)
    {
        return gcd_recurrsion(a, b % a);
    }
    else
    {
        return gcd_recurrsion(a - b, b);
    }
}
int rever_integer(int n)
{

    string num;
    while (n != 0)
    {
        num += to_string(n % 10);
        n=n/10;
    }
    return stoi(num);
}
int main()
{
    // cout << is_armstrong(153);
    // cout<<euclid_algorithm(100,20000);
    // cout << gcd_recurrsion(20, 10);
    cout<<rever_integer(4321);

    return 0;
}