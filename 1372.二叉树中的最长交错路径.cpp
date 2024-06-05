/*
 * @lc app=leetcode.cn id=1372 lang=cpp
 *
 * [1372] 二叉树中的最长交错路径
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
    int longestZigZag(TreeNode *root)
    {
        int res = 0;
        dfs(root->left, res, 0, true);
        dfs(root->right, res, 0, false);
        return res-1;
    }

    void dfs(TreeNode *node, int &res, int depth, bool isLeft)
    {
        if (!node)
        {
            res = res > depth ? res : depth;
            return;
        }
        if (isLeft)
        {
            dfs(node->right, res, depth + 1, false);
        }
        else
        {
            dfs(node->left, res, depth + 1, true);
        }
        return;
    }
};
// @lc code=end
