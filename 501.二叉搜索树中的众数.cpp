/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<int> findMode(TreeNode *root)
    {
        vector<int> res;
        int cnt = 0;
        int pre = __INT_MAX__;
        int mx = 0;
        dfs(root, res, cnt, pre, mx);

        return res;
    }

    void dfs(TreeNode *root, vector<int> &res, int &cnt, int &pre, int &mx)
    {
        if (root == nullptr)
            return;

        dfs(root->left, res, cnt, pre, mx);
        if (pre == __INT_MAX__)
        {
            pre = root->val;
            cnt = 1;
            mx = 1;
            res.push_back(root->val);
        }
        else if (pre == root->val)
        {
            ++cnt;
            if (cnt == mx)
            {
                res.push_back(root->val);
            }
            else if (cnt > mx)
            {
                res.clear();
                mx = cnt;
                res.push_back(root->val);
            }
        }
        else
        {
            pre = root->val;
            cnt = 1;
            if (cnt == mx)
            {
                res.push_back(root->val);
            }
        }
        dfs(root->right, res, cnt, pre, mx);
    }
};
// @lc code=end
