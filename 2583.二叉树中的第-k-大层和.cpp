/*
 * @lc app=leetcode.cn id=2583 lang=cpp
 *
 * [2583] 二叉树中的第 K 大层和
 */
#include <deque>
#include <set>

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
    long long kthLargestLevelSum(TreeNode *root, int k)
    {
        long long res = 0;
        multiset<long long> st;
        deque<TreeNode *> dq;
        dq.push_back(root);
        while (!dq.empty())
        {
            int s = dq.size();
            long long  tmp = 0;

            for (; s > 0; --s)
            {
                TreeNode *nd = dq.front();
                tmp += nd->val;
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
            st.insert(tmp);
        }
        if (k > st.size())
        {
            return -1;
        }
        int i = st.size() - k;
        for(auto& it : st)
        {
            if (i==0)
            {
                res = it;
            }
            --i;
        }
        return res;
    }
};
// @lc code=end
