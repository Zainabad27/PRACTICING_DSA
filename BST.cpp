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

node *insert(node *root, int val)
{
    if (root == nullptr)
    {
        return new node(val);
    }
    if (root->data > val)
    {
        root->left = insert(root->left, val);
    }
    if (root->data < val)
    {
        root->right = insert(root->right, val);
    }
    return root;
}
void p_traversal(node *root)
{
    if (root == nullptr)
    {
        return;
    }

    cout << root->data << " ";
    p_traversal(root->left);
    p_traversal(root->right);
}
void i_traversal(node *root)
{
    if (root == nullptr)
    {
        return;
    }

    i_traversal(root->left);
    cout << root->data << " ";
    i_traversal(root->right);
}
node *make_bst_tree()
{
    vector<int> v = {4, 2, 8, 1, 7, 9, 5, 3, 6};

    node *root = nullptr;
    for (int i = 0; i < v.size(); i++)
    {
        root = insert(root, v[i]);
    }
    return root;
}
bool search_in_binary_tree(node *root, int value)
{
    if (root == nullptr)
    {
        return false;
    }
    else if (root->data == value)
    {
        return true;
    }
    if (value > root->data)
    {
        return search_in_binary_tree(root->right, value);
    }
    else
    {

        return search_in_binary_tree(root->left, value);
    }
}
node *delete_from_BST(node *root, node *key)
{
    if (key->data > root->data)
    {
        root->right = delete_from_BST(root->right, key);
    }
    else if (key->data < root->data)
    {
        root->left = delete_from_BST(root->left, key);
    }
    else
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            return nullptr;
        }
        else if (root->left == nullptr || root->right == nullptr)
        {
            if (root->left == nullptr)
            {
                node *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr)
            {
                node *temp = root->left;
                delete root;
                return temp;
            }
        }
        if (root->left != nullptr && root->right != nullptr)
        {
            // to be written
        }
    }
}



int main()
{

    node *root = make_bst_tree();
    p_traversal(root);
    cout << "\n";

    cout << search_in_binary_tree(root, 9);

    return 0;
}