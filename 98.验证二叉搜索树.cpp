/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */
#include <limits.h>
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
    bool isValidBST(TreeNode *root, long long m = 2147483648L, long long n = (-2147483648L - 1))
    {
        // 前序
        // if (root == nullptr)
        // {
        //     return true;
        // }
        // if (root->val < m && root->val > n)
        // {
        //     return isValidBST(root->left, root->val, n) &&
        //            isValidBST(root->right, m, root->val);
        // }
        // return false;

        // 中序
        // if (root == nullptr)
        // {
        //     return true;
        // }
        // if (!isValidBST(root->left))
        // {
        //     return false;
        // }
        // if (root->val <= pre)
        // {
        //     return false;
        // }
        // pre = root->val;
        // return isValidBST(root->right);

        // 后序
        long long min = 2147483648L;
        long long max = (-2147483648L - 1);
        dfs(root, min, max);
        return max != 2147483648L;
    }

    void dfs(TreeNode *node, long long &min, long long &max)
    {
        if (node == nullptr)
        {
            min = 2147483648L;
            max = (-2147483648L - 1);
            return;
        }

        long long leftMin, leftMax;
        long long rightMin, rightMax;
        dfs(node->left, leftMin, leftMax);

        if (node->val <= leftMax)
        {
            min = (-2147483648L - 1);
            max = 2147483648L;
            return;
        }

        dfs(node->right, rightMin, rightMax);
        if (node->val >= rightMin)
        {
            min = (-2147483648L - 1);
            max = 2147483648L;
            return;
        }

        min = leftMin < node->val ? leftMin : node->val;
        max = rightMax > node->val ? rightMax : node->val;
        return;
    }

private:
    long long pre = (-2147483648L - 1);
};
// @lc code=end
