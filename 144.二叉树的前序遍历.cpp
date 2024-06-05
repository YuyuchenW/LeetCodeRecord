/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */

#include <stack>
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> res;
        stack<TreeNode *> s;
        TreeNode *cur = root;
        while (!s.empty() || cur)
        {
            if (cur != nullptr)
            {
                res.push_back(cur->val);
                s.push(cur->right);
                s.push(cur->left);
                cur = nullptr;
            }
            else
            {
                cur = s.top();
                s.pop();
            }
        }
        return res;
        // dfs(root, res);
        // return res;
    }
    void dfs(TreeNode *root, vector<int> &res)
    {
        if (root == nullptr)
            return;

        res.push_back(root->val);
        dfs(root->left, res);
        dfs(root->right, res);
    }
};
// @lc code=end
