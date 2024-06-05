/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include <vector>
#include <string>
using namespace std;
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
// class Solution
// {
// public:
//     vector<string> binaryTreePaths(TreeNode *root)
//     {
//         if (root == nullptr)
//         {
//             return {};
//         }
//         string str = to_string(root->val);

//         if (root->left == nullptr && root->right == nullptr)
//         {
//             return {str};
//         }

//         vector<string> res;

//         if (root->left)
//         {
//             dfs(root->left, str, res);
//         }
//         if (root->right)
//         {
//             dfs(root->right, str, res);
//         }

//         return res;
//     }
//     void dfs(TreeNode *root, string path, vector<string> &res)
//     {
//         if (root == nullptr)
//         {
//             return;
//         }
//         path += "->" + to_string(root->val);
//         if (root->left == nullptr && root->right == nullptr)
//         {
//             res.push_back(path);
//         }

//         dfs(root->left, path, res);
//         dfs(root->right, path, res);
//     }
// };
// @lc code=end
