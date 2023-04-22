/*
You are given the root node of a binary tree.Print its preorder traversal.

Input Format:
The first and the only line of input will contain the node data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.
Output Format:
The only line of output prints the preorder traversal of the given binary tree.

Sample Input 1:
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
Sample Output 1:
PreOrder Traversal:
1 2 4 5 3 6 7
PostOrder Traversal:
4 5 2 6 7 3 1
InOrder Traversal:
4 2 5 1 6 3 7
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

void preOrder(BinaryTreeNode<int> *root) {
	// Write your code here
	if (root == NULL)
	{
		return;
	}
	// Root -> left -> right
	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);
}

void postOrder(BinaryTreeNode<int> *root) {
	// Write your code here
	if (root == NULL)
	{
		return;
	}
	// left -> right -> Root
	postOrder(root->left);
	postOrder(root->right);
	cout << root->data << " ";
}

void inOrder(BinaryTreeNode<int> *root) {
	// Write your code here
	if (root == NULL)
	{
		return;
	}
	//  left -> Root -> right
	inOrder(root->left);
	cout << root->data << " ";
	inOrder(root->right);
}

int main() {
	BinaryTreeNode<int>* root = takeInput();
	cout << "PreOrder Traversal:" << endl;
	preOrder(root);
	cout << "\nPostOrder Traversal:" << endl;
	postOrder(root);
	cout << "\nInOrder Traversal:" << endl;
	inOrder(root);
}