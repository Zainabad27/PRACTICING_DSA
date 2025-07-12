#include <iostream>
using namespace std;
struct Node
{
    int val;
    Node *left;
    Node *right;
    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int ans = 0;

    int height(Node *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int l_height = height(root->left);
        int r_height = height(root->right);

        int dia = l_height + r_height;

        if (dia >= ans)
        {
            ans = dia;
        }

        return (max(l_height, r_height) + 1);
    }
};

int main()
{

    return 0;
}