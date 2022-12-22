template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode *> children;

    // Constructor
    TreeNode(T data)
    {
        this->data = data;
    }
};
