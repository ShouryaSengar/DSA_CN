/*
For a given preorder and inorder traversal of a Binary Tree of type integer stored in an array/list, 
create the binary tree using the given two arrays/lists. You just need to construct the tree and return the root.
Note:
Assume that the Binary Tree contains only unique elements. 

Input Format:
The first line of input contains an integer N denoting the size of the list/array. 
It can also be said that N is the total number of nodes the binary tree would have.
The second line of input contains N integers, all separated by a single space. It represents the preorder-traversal of the binary tree.
The third line of input contains N integers, all separated by a single space. It represents the inorder-traversal of the binary tree.

Output Format:
The given input tree will be printed in a level order fashion where each level will be printed on a new line. 
Elements on every level will be printed in a linear fashion. A single space will separate them.

Constraints:
1 <= N <= 10^4
Where N is the total number of nodes in the binary tree.
Time Limit: 1 sec

Sample Input 1:
7
1 2 4 5 3 6 7 
4 2 5 1 6 3 7 
Sample Output 1:
1 
2 3 
4 5 6 7 
*/
#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

BinaryTreeNode<int> *takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void printLevelATNewLine(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        BinaryTreeNode<int> *first = q.front();
        q.pop();
        if (first == NULL) {
            if (q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL) {
            q.push(first->left);
        }
        if (first->right != NULL) {
            q.push(first->right);
        }
    }
}

/*
    Logic:
    1. In preOrder (Root) -> (leftSuBTree) -> (rightSubTree),
       i.e firstElement will be root
    2. In inOrder (leftSuBTree) -> (Root) -> (rightSubTree),
       i.e Need to Find root in inOrder
    3. Now we can calculate the start and end point of leftSubTree and
       rightSubTree in both inOrder and preOrder Traveral.
*/
BinaryTreeNode<int>* helper(int *preorder, int preStart, int preEnd, int *inorder, int inStart, int inEnd)
{
    // Check if either the pre-order or in-order traversal range is empty
    if (preStart > preEnd or inStart > inEnd)
    {
        return NULL; //indicate that the current subtree is empty
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(preorder[preStart]);

    // Find the index of the root node in the in-order traversal array
    int inRootINDEX = 0;
    for (int i = inStart; i <= inEnd; ++i)
    {
        if (inorder[i] == root->data)
        {
            inRootINDEX = i;
            break;
        }
    }
    int lps = preStart + 1;         //left(Pre-Order)Start
    int lis = inStart;              //left(In-Order)Start
    int lie = inRootINDEX - 1;      //left(In-Order)End
    //No. of node in in range of Inorder and preoreder will be same
    int lpe = (lie - lis) + lps;    //left(Pre-Order)End

    int ris = inRootINDEX + 1;      //right(In-Order)Start
    int rie = inEnd;                //right(In-Order)End
    int rpe = preEnd;               //right(Pre-Order)End
    int rps = lpe + 1;              //right(Pre-Order)Start

    BinaryTreeNode<int> *leftChild = helper(preorder, lps, lpe, inorder, lis, lie);
    BinaryTreeNode<int> *rightChild = helper(preorder, rps, rpe, inorder, ris, rie);
    root->left = leftChild;
    root->right = rightChild;

    return root;
}
/*
    Intuition:
    To use the pre-order traversal to identify the root node of the current subtree and,
    Then use the in-order traversal to find the left and right subtrees of the root node.
*/
BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    // Write your code here
    int preStart = 0;
    int preEnd = preLength - 1;
    int inStart = 0;
    int inEnd = inLength - 1;
    return helper(preorder, preStart, preEnd, inorder, inStart, inEnd);
}

int main() {
    int size;
    cin >> size;
    int *pre = new int[size];
    int *in = new int[size];
    for (int i = 0; i < size; i++) cin >> pre[i];
    for (int i = 0; i < size; i++) cin >> in[i];
    BinaryTreeNode<int> *root = buildTree(pre, size, in, size);
    printLevelATNewLine(root);
}