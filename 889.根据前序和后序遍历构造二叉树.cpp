/*
 * @lc app=leetcode.cn id=889 lang=cpp
 *
 * [889] 根据前序和后序遍历构造二叉树
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
    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
    {
        int n = preorder.size();
        if (n == 0)
        {
            return nullptr;
        }
        TreeNode *root = new TreeNode(preorder[0]);
        if (n == 1)
        {
            return root;
        }
        int index = 0;
        for (; index < n; ++index)
        {
            if (preorder[1] == postorder[index])
            {
                break;
            }
        }
        vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + index + 2);
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + index+1);
        vector<int> rightPreorder(preorder.begin() + index + 2, preorder.end());
        vector<int> rightPostorder(postorder.begin() + index+1, postorder.end());

        root->left = constructFromPrePost(leftPreorder, leftPostorder);
        root->right = constructFromPrePost(rightPreorder, rightPostorder);
        return root;
    }
};
// @lc code=end
