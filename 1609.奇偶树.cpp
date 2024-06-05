/*
 * @lc app=leetcode.cn id=1609 lang=cpp
 *
 * [1609] 奇偶树
 */
#include<deque>
#include<vector>
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
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        deque<TreeNode*> dq;
        bool res = true;
        bool flag = true;

        dq.push_back(root);
        while (!dq.empty())
        {
            int s = dq.size();
            vector<int> vec;
            for(;s>0;--s)
            {
                TreeNode* node = dq.front();
                vec.push_back(node->val);
                dq.pop_front();

                if(node->left)
                {
                    dq.push_back(node->left);
                }
                if (node->right)
                {
                    dq.push_back(node->right);
                }
            }
            if (!checkVec(vec,flag))
            {
                return false;
            }
            flag = !flag;
        }
        return true;
    }


    bool checkVec(vector<int>& vec,bool flag)
    {
        for (size_t i = 0; i < vec.size()-1; i++)
        {
            
            if(flag)
            {
                if (vec[i]%2 == 0)
                {
                    return false;                    
                }
                
                if(vec[i] >=vec[i+1])
                {
                    
                    return false;
                }
            }
            else{
                if (vec[i]%2 != 0)
                {
                    return false;                    
                }
                if (vec[i] <=vec[i+1])
                {
                    return false;
                }
                
            }
        }
        if (flag)
        {
            if(vec[vec.size()-1]%2 == 0)
            {
                return false;
            }
        }else{
            if(vec[vec.size()-1]%2 != 0)
            {
                return false;
            }
        }
        
        return true;
        
    }
};
// @lc code=end

