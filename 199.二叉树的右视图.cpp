/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
 */
#include <vector>
#include <deque>

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

// 深度优先搜索
// class Solution
// {
// public:
//     vector<int> rightSideView(TreeNode *root)
//     {
//         vector<int> ans;
//         dfs(root, 1, ans);
//         return ans;
//     }
//     void dfs(TreeNode *node, int depth, vector<int> &ans)
//     {
//         if (node == nullptr)
//         {
//             return;
//         }
//         if (ans.size() < depth)
//         {
//             ans.push_back(node->val);
//         }
//         dfs(node->right, depth + 1, ans);
//         dfs(node->left, depth + 1, ans);
//         return;
//     }
// };

// BFS
class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> res;
        if (root == nullptr)
        {
            return res;
        }
        deque<TreeNode *> dq;
        dq.push_back(root);
        while (!dq.empty())
        {
            int s = dq.size();
            for (; s > 0; --s)
            {
                TreeNode *cur = dq.front();
                dq.pop_front();
                if (s == 1)
                {
                    res.push_back(cur->val);
                }
                if (cur->left)
                {
                    dq.push_back(cur->left);
                }

                if (cur->right)
                {
                    dq.push_back(cur->right);
                }
            }
        }
        return res;
    }
};
// @lc code=end
