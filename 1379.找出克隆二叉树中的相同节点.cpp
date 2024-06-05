/*
 * @lc app=leetcode.cn id=1379 lang=cpp
 *
 * [1379] 找出克隆二叉树中的相同节点
 */
#include <vector>

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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        if (original == nullptr)
        {
            return nullptr;
        }

        return dfs(cloned, target->val);
    }

    TreeNode *dfs(TreeNode *node, int val)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        if (node->val == val)
        {
            return node;
        }
        TreeNode *left = dfs(node->left, val);
        TreeNode *right = dfs(node->right, val);
        return left ? left : right;
    }
};
// @lc code=end
