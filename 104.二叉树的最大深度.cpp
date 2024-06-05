/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    int maxDepth(TreeNode *root)
    {
        int res = 0;
        if (root == nullptr)
        {
            return res;
        }

        deque<TreeNode *> dq;
        dq.push_back(root);
        while (!dq.empty())
        {
            int n = dq.size();
            for(;n>0;--n)
            {
                TreeNode* nd = dq.front();
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
            ++res;
        }
        return res;

    }
};
// @lc code=end
