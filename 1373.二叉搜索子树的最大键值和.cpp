/*
 * @lc app=leetcode.cn id=1373 lang=cpp
 *
 * [1373] 二叉搜索子树的最大键值和
 */

#include <iostream>
using namespace std;
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
    int maxSumBST(TreeNode *root)
    {
        int mx = -40001;
        int mn = 40001;
        int sum = 0;
        int res = 0;
        dfs(root, mx, mn, sum, res);
        return res;
    }

    void dfs(TreeNode *node, int &mx, int &mn, int &sum, int &res)
    {
        if (node == nullptr)
        {
            mx = -40001;
            mn = 40001;
            sum = 0;
            return;
        }

        int leftMax, leftMin, lSum;
        int rightMax, rightMin, rSum;
        dfs(node->left, leftMax, leftMin, lSum, res);
        dfs(node->right, rightMax, rightMin, rSum, res);
        if (node->val <= leftMax || node->val >= rightMin)
        {
            mx = 40001;
            mn = -40001;
            sum = 0;
            return;
        }


        sum = lSum + rSum + node->val;
        res = sum > res ? sum : res;
        mn = leftMin < node->val ? leftMin : node->val;
        mx = rightMax > node->val ? rightMax : node->val;
        return;
    }
};
// @lc code=end
