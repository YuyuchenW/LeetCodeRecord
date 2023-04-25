#include<deque>
#include<vector>
using namespace std;

//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int maxAncestorDiff(TreeNode *root)
    {
        deque<TreeNode*> dq;
        vector<vector<int>> vec(1,vector<int>(1,root->val));
        dq.push_back(root);
        while (!dq.empty())
        {
            
        }
        

    }
};