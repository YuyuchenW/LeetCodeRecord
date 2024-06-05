/*
 * @lc app=leetcode.cn id=1123 lang=cpp
 *
 * [1123] 最深叶节点的最近公共祖先
 */
#include <vector>
#include <iostream>
#include <unordered_set>
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
    TreeNode *lcaDeepestLeaves(TreeNode *root)
    {
        int maxDepth = -1;
        dfs(root, maxDepth, 0);
        return res;
    }

    int dfs(TreeNode *root, int &maxDepth, int depth)
    {
        if (root == nullptr)
        {
            maxDepth = maxDepth > depth ? maxDepth : depth;
            return depth;
        }

        int leftDepth = dfs(root->left, maxDepth, depth + 1);
        int rightDepth = dfs(root->right, maxDepth, depth + 1);

        if (leftDepth == rightDepth && leftDepth == maxDepth)
        {
            res = root;
        }

        return leftDepth > rightDepth ? leftDepth : rightDepth;
    }

private:
     TreeNode * res = nullptr;
};
// @lc code=end
