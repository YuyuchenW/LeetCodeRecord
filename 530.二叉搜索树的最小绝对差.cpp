/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
 */
#include <algorithm>

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
    int getMinimumDifference(TreeNode *root)
    {
        int res = INT_MAX;
        int pre = -1;
        dfs(root, pre, res);
        return res;
    }

    void dfs(TreeNode *node, int &pre, int &res)
    {
        if (node == nullptr)
        {
            return;
        }
        dfs(node->left, pre, res);
        if (pre == -1)
        {
            pre = node->val;
        }
        else
        {
            res = std::min(node->val - pre, res);
            pre = node->val;
        }
        dfs(node->right, pre, res);
    }
};
// @lc code=end
