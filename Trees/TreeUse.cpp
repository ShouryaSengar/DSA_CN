#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

int main()
{
    TreeNode<int> *root = new TreeNode<int>(1);
    TreeNode<int> *child1 = new TreeNode<int>(2);
    TreeNode<int> *child2 = new TreeNode<int>(3);
    root->children.push_back(child1);
    root->children.push_back(child2);
}