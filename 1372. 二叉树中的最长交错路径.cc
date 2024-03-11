
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
public:
    int ans = 0;
    void dfs(TreeNode *nd, bool flag, int path)
    {
        if (nd == nullptr)
        {
            return;
        }
        ans = ans > path ? ans : path;
        if (flag)
        {
            dfs(nd->left, false, path + 1);
            dfs(nd->right, true, 1);
        }
        else
        {
            dfs(nd->left, false, 1);
            dfs(nd->right, true, path + 1);
        }
    }
    int longestZigZag(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        dfs(root->left,false,1);
        dfs(root->right,true,1);        
        return ans;
    }
};