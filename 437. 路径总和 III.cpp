#include<deque>
#include<stdint.h>
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
    int dfs(TreeNode* nd, int64_t target)
    {
        if (nd == nullptr)
        {
            return 0;
        }
        
        int cnt = 0;
        if (nd->val == target)
        {
            cnt++;
        }
        
        cnt += dfs(nd->left,target- (nd->val));
        cnt += dfs(nd->right, target- (nd->val));
        return cnt;
    }
    int pathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
        {
            return 0;
        }

        return dfs(root,targetSum) + pathSum(root->left,targetSum) + pathSum(root->right, targetSum);
        
    }
}; 