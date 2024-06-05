/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
 */
#include <vector>
#include <deque>
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
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> res;
        if (root == nullptr)
        {
            return res;
        }

        deque<TreeNode *> dq;
        dq.push_back(root);

        while (!dq.empty())
        {
            vector<int> tmp;
            int n = dq.size();
            for (; n > 0; --n)
            {
                TreeNode *nd = dq.front();
                tmp.push_back(nd->val);
                dq.pop_front();
                if (nd->left)
                {
                    dq.push_back(nd->left);
                }
                if (nd->right)
                {
                    dq.push_back(nd->right);
                }
            }
            res.push_back(tmp);
        }

        reverse(res.begin(),res.end());
        return res;
    }
};
// @lc code=end
