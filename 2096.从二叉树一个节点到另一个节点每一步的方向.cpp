/*
 * @lc app=leetcode.cn id=2096 lang=cpp
 *
 * [2096] 从二叉树一个节点到另一个节点每一步的方向
 */
#include <string>
#include <unordered_map>
#include <algorithm>
#include <functional>
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
    string getDirections(TreeNode *root, int startValue, int destValue)
    {
        unordered_map<TreeNode *, TreeNode *> map;
        TreeNode *start = nullptr;
        TreeNode *dest = nullptr;

        function<void(TreeNode *)> dfs = [&](TreeNode *node)
        {
            if (node->val == startValue)
            {
                start = node;
            }
            if (node->val == destValue)
            {
                dest = node;
            }
            if (node->left)
            {
                map[node->left] = node;
                dfs(node->left);
            }
            if (node->right)
            {
                map[node->right] = node;
                dfs(node->right);
            }
        };

        dfs(root);

        function<string(TreeNode *)> getPath = [&](TreeNode *node)
        {
            string res;
            while (node != root)
            {
                TreeNode *parent = map[node];
                if (parent->left == node)
                {
                    res += "L";
                }
                else
                {
                    res += "R";
                }
                node = parent;
            }
            reverse(res.begin(), res.end());
            return res;
        };

        string p1 = getPath(start);
        string p2 = getPath(dest);
        int i = min(p1.size(), p2.size());
        int j = 0;
        for (; j < i; ++j)
        {
            if (p1[j] != p2[j])
            {
                break;
            }
        }

        string res(p1.size() - j, 'U');
        res += p2.substr(j, p2.size() - j);
        return res;
    }
};
// @lc code=end
