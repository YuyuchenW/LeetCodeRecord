/*
 * @lc app=leetcode.cn id=2476 lang=cpp
 *
 * [2476] 二叉搜索树最近节点查询
 */
using namespace std;

#include <vector>
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
    vector<vector<int>> closestNodes(TreeNode *root, vector<int> &queries)
    {
        vector<vector<int>> res;
        vector<int> arr;
        dfs(root, arr);

        for (auto query : queries)
        {
            int left = low_bsearch(arr, query);
            int mx = left < arr.size() ? arr[left] : -1;
            if (left == arr.size() || query != arr[left])
            {
                --left;
            }
            int mn = left >= 0 ? arr[left] : -1;

            res.push_back({mn, mx});
        }
        return res;
    }

    void dfs(TreeNode *root, vector<int> &arr)
    {
        if (root == nullptr)
        {
            return;
        }

        dfs(root->left, arr);
        arr.push_back(root->val);
        dfs(root->right, arr);
        return;
    }

    int low_bsearch(vector<int> &arr, int target)
    {
        int left = 0, right = arr.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target)
            {
                return mid;
            }
            else if (arr[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
};
// @lc code=end
