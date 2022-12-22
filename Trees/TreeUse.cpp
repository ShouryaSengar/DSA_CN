#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

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

int main()
{
    TreeNode<int> *root = new TreeNode<int>(1);
    TreeNode<int> *child1 = new TreeNode<int>(2);
    TreeNode<int> *child2 = new TreeNode<int>(3);
    root->children.push_back(child1);
    root->children.push_back(child2);
    printTree(root);
    // TODO: delete the tree
}