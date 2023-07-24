
// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    int m_res;
public:
    void getMaxDepth(int res, TreeNode* nd)
    {
        if (nd ==nullptr)
        {
            m_res = m_res> res ? m_res :res;
            return;
        }
        ++ res;
        getMaxDepth(res, nd->left);
        getMaxDepth(res, nd->right);
    }
    int maxDepth(TreeNode *root)
    {
       m_res = 0;
        getMaxDepth(0,root);
        return m_res;
    }
};