#include <vector>
using namespace std;

// Definition for a binary tree node.
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
    void insertNums(vector<int> &nums, TreeNode *tn)
    {
        if (tn == nullptr)
        {
            
            return;
        }
        if(tn->left ==nullptr && tn->right == nullptr)
        {
            nums.push_back(tn->val);
            return;
        }
        insertNums(nums, tn->left);
        insertNums(nums, tn->right);
    }
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        vector<int> nums1;
        vector<int> nums2;
        insertNums(nums1,root1);
        insertNums(nums2,root2);
        return nums1 == nums2;
    }
};