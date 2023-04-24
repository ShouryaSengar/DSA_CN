/*
    Yor are given a BT. You are supposed to return the Diameter of the BT.
    i.e. the length of the longest path between ant two end nodes in a tree.
*/
#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

BinaryTreeNode<int>* takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int height(BinaryTreeNode<int> *root) 
{
  if (root == NULL)
  {
    return 0;
  }
  else
  {
    return 1 +  max(height(root->left), height(root->right));
  }
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
	// Write Your Code Here.
    if(root == NULL)
    {
        return 0;
    }
    
    int opt1 = height(root->left) + height(root->right);
    int opt2 = diameterOfBinaryTree(root->left);
    int opt3 = diameterOfBinaryTree(root->right);
    
    return max(opt1, max(opt2, opt3));
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << diameterOfBinaryTree(root) << endl;
}