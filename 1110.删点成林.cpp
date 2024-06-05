/*
 * @lc app=leetcode.cn id=1110 lang=cpp
 *
 * [1110] 删点成林
 */
#include <vector>
#include <algorithm>
#include <iostream>
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
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
    {
        if (root == nullptr)
        {
            return res;
        }

        dfs(root, to_delete);
        if (find(to_delete.begin(), to_delete.end(), root->val) == to_delete.end())
        {
            res.push_back(root);
        }
        return res;
    }
    void dfs(TreeNode *root, vector<int> &to_delete, TreeNode *prev = nullptr)
    {
        if (root == nullptr)
        {
            return;
        }
        dfs(root->left, to_delete, root);
        dfs(root->right, to_delete, root);
        if (find(to_delete.begin(), to_delete.end(), root->val) != to_delete.end())
        {
            std::cout << root->val << " is deleted" << std::endl;
            if (root->left != nullptr)
            {
                res.push_back(root->left);
            }
            if (root->right != nullptr)
            {
                res.push_back(root->right);
            }
            if (prev != nullptr)
            {
                if (prev->left == root)
                {
                    prev->left = nullptr;
                }
                else
                {
                    prev->right = nullptr;
                }
            }

            return;
        }
    }

private:
    vector<TreeNode *> res;
};
// @lc code=end
