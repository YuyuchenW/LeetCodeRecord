/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 */
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
class Solution
{
public:
    // int minDepth(TreeNode *root)
    // {
    //     if (root == nullptr)
    //         return 0;
    //     int res = __INT_MAX__;
    //     FindDepth(root, 0, res);
    //     return res;
    // }

    // void FindDepth(TreeNode *root, int cnt, int &res)
    // {
    //     if (root == nullptr)
    //     {
    //         return;
    //     }
    //     ++cnt;
    //     if (root->left == nullptr && root->right == nullptr)
    //     {
    //         res = res > cnt ? cnt : res;
    //         return;
    //     }

    //     FindDepth(root->left, cnt, res);
    //     FindDepth(root->right, cnt, res);
    // }
    int minDepth(TreeNode *root)
    {
        int res = 0;
        if (!root)
        {
            return res;
        }

        deque<TreeNode *> dq;
        dq.push_back(root);
        bool flag = true;
        while (!dq.empty() && flag)
        {
            int n = dq.size();
            for (; n > 0; --n)
            {
                TreeNode* tmp = dq.front();
                dq.pop_front();
                if (!tmp->left && !tmp->right)
                {
                    flag = false;
                    break;
                }
                if (tmp->left)
                {
                    dq.push_back(tmp->left);
                }
                if (tmp->right)
                {
                    dq.push_back(tmp->right);
                }
            }
            ++res;
        }
        return res;
    }
};

// @lc code=end
