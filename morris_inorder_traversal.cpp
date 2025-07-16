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

void morris_inorder_traversal(node *root)
{
    node *curr = root;
    while (curr != nullptr)
    {
        if (curr->left == nullptr)
        {
            cout << curr->data << " ";
            curr = curr->right;
        }
        else
        {
            // find ip
            node *ip = curr->left;
            while (ip->right != nullptr && ip->right != curr)
            {
                ip = ip->right;
            }
            if (ip == nullptr)
            {
                ip->right = curr;
                curr = curr->left;
            }
            else
            {
                ip->right = nullptr;
                cout << curr->data << " ";
                curr = curr->right;
            }
        }
    }
}
queue<node *> q;
void queue_filler(node *root)
{

    if (root == nullptr)
    {
        return;
    }
    q.push(root);

    queue_filler(root->left);
    queue_filler(root->right);
}
node *flatten_binary_tree(node *root)
{
    queue_filler(root);
    while (q.size() > 1)
    {
        node *curr = q.front();
        q.pop();
        curr->left = nullptr;
        curr->right = q.front();
    }
    node *last = q.front();
    last->left = nullptr;
    last->right = nullptr;

    return root;
}

void flatten_tree(node *root,node* prev)
{
    if (root == nullptr)
    {
        return;
    }
    flatten_tree(root->left,root);
    flatten_tree(root->right,root);

    root->right=prev;
    root->left=nullptr;
    cout<<root->data<<" ";
}

int main()
{
    // vector<int> tree = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    vector<int> tree = {10, 20, 40, -1, -1, -1, 30, 50, 70, -1, -1, -1, 60, -1, -1};

    node *root = createtree(tree);
    // node *l = flatten_binary_tree(root);
    // while (l != nullptr)
    // {
    //     cout << l->data << " ";
    //     l = l->right;
    // }
    cout<<"\n\n\n\n\n\n\n";
    flatten_tree(root,nullptr);
    return 0;
}