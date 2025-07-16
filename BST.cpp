#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <cmath>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
    node()
    {
    }
};
static int indx = -1;
node *createtree(vector<int> tree)
{
    indx++;

    node *new_node = new node();

    if (tree[indx] == -1)
    {
        return nullptr;
    }

    new_node->data = tree[indx];
    new_node->left = createtree(tree);
    new_node->right = createtree(tree);
    return new_node;
}

node *insert(int val)
{
    node *new_node = new node(val);
    return new_node;
}
void makeBST(vector<int> v)
{
   
}
int mai()
{
    return 0;
}