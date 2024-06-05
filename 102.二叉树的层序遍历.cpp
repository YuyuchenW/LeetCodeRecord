/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 */
#include <deque>
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
    vector<vector<int>> levelOrder(TreeNode *root)
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
            int size = dq.size();
            vector<int> temp;
            for (int i = 0; i < size; ++i)
            {
                TreeNode *node = dq.front();
                dq.pop_front();
                temp.push_back(node->val);
                if (node->left != nullptr)
                {
                    dq.push_back(node->left);
                }
                if (node->right != nullptr)
                {
                    dq.push_back(node->right);
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};
// @lc code=end
