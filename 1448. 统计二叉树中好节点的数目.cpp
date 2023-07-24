
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
    void dfs(int & cnt, TreeNode *tn , int pathNum)
    {
        if (tn == nullptr)
        {
            return;
        }
        if (tn->val >= pathNum)
        {
            ++ cnt;
            pathNum = tn->val;
        }
        dfs(cnt, tn->left, pathNum);
        dfs(cnt, tn->right, pathNum);
    }
    int goodNodes(TreeNode *root)
    {
        int cnt = 0;
        int pathNum = root->val;
        dfs(cnt,root,pathNum);
        return cnt;
    }
};