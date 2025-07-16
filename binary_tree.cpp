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

void preorder_triversal(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->data << " ";
    preorder_triversal(root->left);
    preorder_triversal(root->right);
}
void inorder_triversal(node *root)
{
    if (root == nullptr)
    {
        return;
    }

    inorder_triversal(root->left);
    cout << root->data << " ";
    inorder_triversal(root->right);
}

void postorder_triversal(node *root)
{
    if (root == nullptr)
    {
        return;
    }
    postorder_triversal(root->left);
    postorder_triversal(root->right);
    cout << root->data << " ";
}
void level_order(node *root)
{
    queue<node *> q;

    q.push((root));
    while (q.size() > 0)
    {

        node *curr = q.front();
        q.pop();
        cout << curr->data << " ";
        if (curr->left != nullptr)
        {
            q.push((curr->left));
        }

        if (curr->right != nullptr)
        {
            q.push((curr->right));
        }
    }
}

int tree_height(node *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int leftht = tree_height(root->left);
    int righttht = tree_height(root->right);

    return (max(leftht, righttht) + 1);
}

int count_nodes(node *root)
{

    if (root == nullptr)
    {
        return 0;
    }
    int lnodes = count_nodes(root->left);
    int rnodes = count_nodes(root->right);

    return (lnodes + rnodes + 1);
}
int sum_nodes(node *root)
{

    if (root == nullptr)
    {
        return 0;
    }
    int sum_left = sum_nodes(root->left);
    int sum_right = sum_nodes(root->right);
    return (root->data + sum_left + sum_right);
}

bool isidentical(node *p, node *q)
{
    if (p != nullptr && q != nullptr)
    {
        if ((p->data != q->data))
        {
            return false;
        }
    }
    else if (p == nullptr && q != nullptr)
    {
        return false;
    }
    else if (p != nullptr && q == nullptr)
    {
        return false;
    }
    else if (p == nullptr && q == nullptr)
    {
        return true;
    }

    bool l_identical = isidentical(p->left, q->left);
    bool r_identical = isidentical(p->right, q->right);

    return (l_identical && r_identical);
}

bool isidentical_apna(node *p, node *q)
{
    if (p == nullptr || q == nullptr)
    {
        return p == q;
    }
    bool liden = isidentical_apna(p->left, q->left);
    bool riden = isidentical_apna(p->right, q->right);

    return (p->data == q->data && liden && riden);
}
bool subtree_present(node *treeR, node *subtreeR)
{
    if (subtreeR == nullptr)
    {
        return true;
    }
    if (treeR == nullptr)
    {
        return false;
    }
    if (treeR->data == subtreeR->data)
    {
        return isidentical(treeR, subtreeR);
    }

    bool Lpresent = subtree_present(treeR->left, subtreeR);
    bool Rpresent = subtree_present(treeR->right, subtreeR);

    return (Lpresent || Rpresent);
}

void levelorder(node *root)
{
    queue<node *> q;
    q.push(root);
    while (q.size() > 0)
    {
        node *curr = q.front();
        q.pop();
        cout << curr->data << endl;
        if (curr->left != nullptr)
        {
            q.push(curr->left);
        }
        if (curr->right != nullptr)
        {
            q.push(curr->right);
        }
    }
}
void top_view(node *root)
{
    queue<pair<int, node *>> q;
    map<int, int> m;

    q.push({0, root});
    m.insert({0, root->data});
    int counter = 1;

    while (q.size() > 0)
    {
        node *curr = q.front().second;
        int currhd = q.front().first;
        if (m.find(currhd) == m.end())
        {
            m.insert({currhd, curr->data});
        }
        q.pop();
        if (curr->left != nullptr)
        {
            q.push({currhd - 1, curr->left});
        }
        if (curr->right != nullptr)
        {

            q.push({currhd + 1, curr->right});
        }
    }
    for (auto it = m.begin(); it != m.end(); ++it)
    {
        cout << it->second << "\n";
    }
}

void k_th_level_BT(node *root, int k)
{
    queue<pair<int, node *>> q; // stores level of the node and the node,root level starts from 1.
    q.push({1, root});
    while (q.size() > 0)
    {
        node *curr = q.front().second;
        int currlvl = q.front().first;
        if (q.front().first == k)
        {
            cout << q.front().second->data << " ";
        }
        q.pop();
        if (curr->left != nullptr)
        {
            q.push({currlvl + 1, curr->left});
        }
        if (curr->right != nullptr)
        {
            q.push({currlvl + 1, curr->right});
        }
    }
}
// bool find_LCA(node *root, int p, int q)
// {
//     if (root == nullptr)
//     {
//         return false;
//     }
//     else if (root->data == p || root->data == q)
//     {
//         cout << root->data<<"\n";

//         return true;
//     }

//     bool find_lca_left = find_LCA(root->left, p, q);
//     bool find_lca_right = find_LCA(root->right, p, q);

//     if (find_lca_left && find_lca_right)
//     {
//         cout << root->data<<"\n";
//         return true;
//     }
//     else if(find_lca_left&&!find_lca_right){
//         return find_lca_left;
//     }

// }

node *findlca(node *root, int p, int q)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (root->data == p || root->data == q)
    {
        return root;
    }

    node *left = findlca(root->left, p, q);
    node *right = findlca(root->right, p, q);

    if (left && right)
    {
        return root;
    }
    else if (left != nullptr)
    {
        return left;
    }
    else
    {
        return right;
    }
}

int findindx(int number, vector<int> inorder, int left, int right)
{

    for (int i = 0; i < inorder.size(); i++)
    {
        if (inorder[i] == number)
        {
            return i;
        }
    }

    return -1;
}

// int indx = 0;
// node *build_tree(vector<int> &preorder, vector<int> &inorder, int &preidx, int l, int r)
// {
//     if (l > r)
//     {
//         return nullptr;
//     }

//     node *root = new node(preorder[preidx]);
//     preidx++;
//     int inidx = findindx(preorder[preidx], inorder, l, r);
//     root->left = build_tree(preorder, inorder, preidx, l, inidx - 1);
//     root->right = build_tree(preorder, inorder, preidx, inidx + 1, r);
//     return root;
// }
int sumtree(node *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int leftsum = sumtree(root->left);
    int rightsum = sumtree(root->right);

    root->data += leftsum + rightsum;

    return root->data;
}
vector<string> ans;
string str;
string treepath(node *root)
{

    if (root == nullptr)
    {
        return "null";
    }

    string leftpath = to_string(root->data) + "---->" + treepath(root->left);
    string rightpath = to_string(root->data) + "---->" + treepath(root->right);
    ans.push_back(leftpath);
    ans.push_back(rightpath);

    return rightpath;
}

int max_width_of_tree(node *root)
{
    queue<pair<int, node *>> q;

    q.push({0, root});
    int max_lvl = 0;

    while (q.size() > 0)
    {
        node *curr = q.front().second;
        int curr_lvl = q.front().first;
        q.pop();

        if (curr->left != nullptr)
        {
            q.push({curr_lvl + 1, curr->left});
        }
        if (curr->right != nullptr)
        {
            q.push({curr_lvl + 1, curr->right});
        }
        if (curr->left == nullptr && curr->right == nullptr)
        {
            if (curr_lvl > max_lvl)
            {
                max_lvl = curr_lvl;
            }
        }
    }

    return pow(2, max_lvl);
}

int width_cbt(node *root)
{
    queue<pair<node *, int>> q;
    q.push({root, 0});
    int max_width = 0;

    while (q.size() > 0)
    {
        int currlvlsize = q.size();
        int stindx = q.front().second;
        int endindx = q.back().second;
        max_width = max(max_width, endindx - stindx + 1);

        for (int i = 0; i < currlvlsize; i++)
        {
            auto curr = q.front();
            q.pop();
            if (curr.first->left)
            {
                q.push({curr.first->left, curr.second * 2 + 1});
            }
            if (curr.first->right)
            {
                q.push({curr.first->right, curr.second * 2 + 2});
            }
        }
    }
    return max_width;
}
int main()
{
    vector<int> tree = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    node *root = createtree(tree);

    cout << max_width_of_tree(root);

    return 0;
}