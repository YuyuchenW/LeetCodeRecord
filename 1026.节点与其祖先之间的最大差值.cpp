/*
 * @lc app=leetcode.cn id=1026 lang=cpp
 *
 * [1026] 节点与其祖先之间的最大差值
 */

#include <algorithm>
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
    int maxAncestorDiff(TreeNode *root)
    {
        int res = 0;
        dfs(root, root->val, root->val, res);
        return res;
    }

    void dfs(TreeNode *root, int m, int n, int &res)
    {
        if (root == nullptr)
        {
            return;
        }
        res = max(res, max(abs(m - root->val), abs(n - root->val)));
        if (root->val > m)
        {
            m = root->val;
        }
        if (root->val < n)
        {
            n = root->val;
        }
        dfs(root->left, m, n, res);
        dfs(root->right, m, n, res);
    }
};
// @lc code=end
