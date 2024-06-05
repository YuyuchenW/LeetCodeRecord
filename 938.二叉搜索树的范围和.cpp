/*
 * @lc app=leetcode.cn id=938 lang=cpp
 *
 * [938] 二叉搜索树的范围和
 */
#include <iostream>

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
    int rangeSumBST(TreeNode *root, int low, int high, int sum = 0)
    {
        if (root == nullptr)
        {
            return sum;
        }

        if (root->val < low)
        {
            sum = rangeSumBST(root->right, low, high, sum);
            return sum;
        }
        if (root->val > high)
        {
            sum = rangeSumBST(root->left, low, high, sum);
            return sum;
        }

        sum += root->val;

        sum = rangeSumBST(root->left, low, high, sum);
        sum = rangeSumBST(root->right, low, high, sum);
        return sum;
    }
};
// @lc code=end
