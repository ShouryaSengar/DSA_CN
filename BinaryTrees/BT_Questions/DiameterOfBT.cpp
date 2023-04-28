/*
    Yor are given a BT. You are supposed to return the Diameter of the BT.
    i.e. the length of the longest path between ant two end nodes in a tree.
*/
#innclude <bits/stdc++.h>
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
    // Recursive Approach O(n^2)
    // Bcoz we r calling height of BT every time along with daimeterOfBinaryTree
    if(root == NULL)
    {
        return 0;
    }
    
    int opt1 = height(root->left) + height(root->right);
    int opt2 = diameterOfBinaryTree(root->left);
    int opt3 = diameterOfBinaryTree(root->right);
    
    return max(opt1, max(opt2, opt3));
}

//But if we retunr height and diameter together then O(n) complexity
pair<int, int> heightDiameter(BinaryTreeNode<int>* root) {
    if(root == NULL)
    {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    pair<int, int> leftAns = heightDiameter(root->left);
    pair<int, int> rightAns = heightDiameter(root->right);
    int lh = leftAns.first;
    int ld = leftAns.second;
    int rh = rightAns.first;
    int rd = rightAns.second;

    int height = 1 + max(lh, rh);
    int diameter = max(lh+rh, max(ld, rd));

    pair<int,int> p;
    p.first = height;
    p.second = diameter;
    return p;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << diameterOfBinaryTree(root) << endl;
    pair<int, int> p = heightDiameter(root);
    cout << "Height of BT: "<< p.first << " "<< "\nDiameter of BT: "<< p.second << endl;
}