/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
 */
#include<vector>
#include<deque>
#include<algorithm>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if (root == nullptr)
        {
            return res;
        }
        deque<TreeNode *> dq;
        dq.push_back(root);
        bool flag = false;
        while (!dq.empty())
        {
            int size = dq.size();
            vector<int> temp;
            for (;size>0; --size)
            {
                TreeNode *node = dq.front();
                dq.pop_front();
                temp.push_back(node->val);
                if (node->left)
                {
                    dq.push_back(node->left);
                }
                if (node->right)
                {
                    dq.push_back(node->right);
                }
            }
            if(flag)
            {
                reverse(temp.begin(), temp.end());
            }
            res.push_back(temp);
            flag = !flag;
        }
        return res;
    }
};
// @lc code=end
