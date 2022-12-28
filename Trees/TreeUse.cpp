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
        return 0;
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

/*TREE TRAVERSAL'S*/
void preOrder(TreeNode<int> *root)
{
    // ROOT -> LEFT -> RIGHT
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    for (int i = 0; i < root->children.size(); i++)
    {
        preOrder(root->children[i]);
    }
}
void postOrder(TreeNode<int> *root)
{
    // LEFT -> RIGHT -> ROOT
    if (root == NULL)
    {
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        postOrder(root->children[i]);
    }
    cout << root->data << " ";
}
void inOrder(TreeNode<int> *root)
{
}

/*
Deleting a Tree methods:
1. by postOrder recursive traversal
2. by calling destructor
*/
void deleteTree(TreeNode<int> *root)
{
    // Similar to PostOrder
    for (int i = 0; i < root->children.size(); i++)
    {
        deleteTree(root->children[i]);
    }
    delete root;
}
// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
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
    cout << "Number of nodes: " << numNodes(root) << endl;
    int k;
    cin >> k;
    cout << "Level " << k << " elements : ";
    printAtLevelK(root, k);
    cout << endl;

    bool exit = 0;
    while (!exit)
    {
        cout << "\nSelect the following TREE TRAVERSAL method's : "
             << "\n1. Preorder traversal"
             << "\n2. Postorder traversal"
             << "\n3. Inorder traversal"
             << "\n4. Exit" << endl;
        int option;
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "PreOrder : ";
            preOrder(root);
            cout << endl;
            break;

        case 2:
            cout << "PostOrder : ";
            postOrder(root);
            cout << endl;
            break;

        case 3:
            cout << "InOrder : ";
            inOrder(root);
            cout << endl;
            break;

        case 4:
            exit = 1;
            cout << endl;
            break;

        default:
            cout << "INVALID INPUT";
            cout << endl;
            break;
        }
    }

    // TODO: delete the tree
    // deleteTree(root);
    delete root; // by destructor
}