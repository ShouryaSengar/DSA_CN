/*
Given a generic tree, find and return the node with second largest value in given tree.
Note: Return NULL if no node with required value is present.
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0
Sample Output 1 :
40
*/
#include <iostream>
#include <queue>
#include <vector>
#include <climits>
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

#include <utility>
pair<TreeNode<int> *, TreeNode<int> *> getSecondLargestNodeHelper(TreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<TreeNode<int> *, TreeNode<int> *> ans;
        ans.first = NULL;
        ans.second = NULL;
    }

    pair<TreeNode<int> *, TreeNode<int> *> ans;
    ans.first = root;
    ans.second = NULL;
    for (int i = 0; i < root->children.size(); i++)
    {
        pair<TreeNode<int> *, TreeNode<int> *> recAns = getSecondLargestNodeHelper(root->children[i]);
        if (recAns.first->data > ans.first->data)
        {
            if (recAns.second == NULL)
            {
                ans.second = ans.first;
                ans.first = recAns.first;
            }
            else
            {
                if (recAns.second->data > ans.first->data)
                {
                    ans.second = recAns.second;
                    ans.first = recAns.first;
                }
                else
                {
                    ans.second = ans.first;
                    ans.first = recAns.first;
                }
            }
        }
        else
        {
            if (recAns.first->data != ans.first->data && (ans.second == NULL || ans.second->data < recAns.first->data))
            {
                ans.second = recAns.first;
            }
        }
    }
    return ans;
}

TreeNode<int> *getSecondLargestNode(TreeNode<int> *root)
{
    return getSecondLargestNodeHelper(root).second;
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();

    TreeNode<int> *ans = getSecondLargestNode(root);

    if (ans != NULL)
    {
        cout << ans->data;
    }
    else
    {
        cout << INT_MIN;
    }
}