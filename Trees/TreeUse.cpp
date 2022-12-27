#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

TreeNode<int> *takeInputLevelWise() // Easy for user to pass input
{
    // Using Queue
    int rootData;
    cout << "Enter root data :)" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> pendingNodes;

    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter number of cildren of " << front->data << endl;
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cout << "Enter " << i << "th child of " << front->data << endl;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData); // We wan't the node to be survie
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}
void printTreeLevelWise(TreeNode<int> *root)
{
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (!pendingNodes.empty())
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << ":";
        for (int i = 0; i < front->children.size(); i++)
        {
            TreeNode<int> *currentNode = front->children[i];
            pendingNodes.push(currentNode);
            if (i + 1 == front->children.size())
            {
                cout << currentNode->data;
            }
            else
            {
                cout << currentNode->data << ",";
            }
        }
        cout << endl;
    }
}
TreeNode<int> *takeInput()
{
    // ! Taking input the tough way (Recurive) DFS
    int rootData;
    cout << "Enter data :)" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    int n;
    cout << "Enter number of children of " << rootData << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = takeInput();
        root->children.push_back(child);
    }
    return root;
}
void printTree(TreeNode<int> *root)
{
    if (root == NULL) // Edge Case not a Base Case
    {
        return;
    }

    cout << root->data << ": ";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data;
        if (i != root->children.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << endl;

    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]); // No base case required for generic tree
    }
}

int numNodes(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    int ans = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += numNodes(root->children[i]);
    }
    return ans;
}

void printAtLevelK(TreeNode<int> *root, int k)
{
    if (root == NULL)
    {
        return;
    }
    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        printAtLevelK(root->children[i], k - 1);
    }
}

int main()
{
    // TreeNode<int> *root = new TreeNode<int>(1);
    // TreeNode<int> *child1 = new TreeNode<int>(2);
    // TreeNode<int> *child2 = new TreeNode<int>(3);
    // root->children.push_back(child1);
    // root->children.push_back(child2);
    // TreeNode<int> *root = takeInput();
    TreeNode<int> *root = takeInputLevelWise();
    printTree(root);
    int k;
    cin >> k;
    cout << "Level " << k << " elements : ";
    printAtLevelK(root, k);
    // TODO: delete the tree
}