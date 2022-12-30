/*
Given a generic tree and an integer n. Find and return the node with next larger element in the tree i.e.
find a node with value just greater than n.
Note: Return NULL if no node is present with the value greater than n.

Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0
18
Sample Output 1 :
20
Sample Input 2 :
10 3 20 30 40 2 40 50 0 0 0 0
21
Sample Output 2:
30
*/
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode()
    {
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }
};

TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

TreeNode<int> *getNextLargerElement(TreeNode<int> *root, int x)
{
    // Write your code her

    if (root == NULL)
    {
        return NULL;
    }
    else if (root->children.size() == 0)
    {
        if (root->data > x)
        {
            return root;
        }
        else
        {
            return NULL;
        }
    }
    else
    {
        TreeNode<int> *ans = NULL;
        if (root->data > x)
        {
            ans = root;
        }
        for (int i = 0; i < root->children.size(); i++)
        {
            TreeNode<int> *smallAns = getNextLargerElement(root->children[i], x);
            if (ans == NULL or smallAns->data < ans->data)
            {
                ans = smallAns;
            }
        }
        return ans;
    }
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    int x;
    cin >> x;
    TreeNode<int> *ans = getNextLargerElement(root, x);

    if (ans != NULL)
    {
        cout << ans->data;
    }
}