/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
        {
            return false;
        }
        bool res = false;
        dfs(root, targetSum, res);
        return res;
    }

    void dfs(TreeNode *root, int targetSum, bool &flag)
    {
        if (root == nullptr)
            return;
        targetSum -= root->val;
        if (targetSum == 0 && root->left == nullptr && root->right == nullptr)
            flag = true;
        // if (targetSum == 0)
        // {
        //     return;
        // }

        dfs(root->left, targetSum, flag);
        dfs(root->right, targetSum, flag);
    }
};
// @lc code=end
