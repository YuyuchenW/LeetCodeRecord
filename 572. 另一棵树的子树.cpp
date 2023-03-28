
#include <queue>
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

using namespace std;
class Solution
{
public:
    bool checkSub(TreeNode *node1, TreeNode *node2)
    {
        queue<TreeNode *> q1, q2;
        q1.push(node1);
        q2.push(node2);
        while (!q1.empty() && !q2.empty())
        {
            TreeNode *curNode1 = q1.front();
            TreeNode *curNode2 = q2.front();
            if (curNode1->val != curNode2->val)
            {
                return false;
            }
            q1.pop();
            q2.pop();
            if (curNode1 != nullptr && curNode1->left != nullptr)
            {
                q1.push(curNode1->left);
            }
            if (curNode1 != nullptr && curNode1->right != nullptr)
            {
                q1.push(curNode1->right);
            }
            if (curNode2 != nullptr && curNode2->left != nullptr)
            {
                q2.push(curNode2->left);
            }
            if (curNode2 != nullptr && curNode2->right != nullptr)
            {
                q2.push(curNode2->right);
            }
            if (q1.size() != q2.size())
            {
                return false;
            }
        }
        
        return q1.empty()^q2.empty();
    }
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *curNode = q.front();
            if (curNode->val = subRoot->val)
            {
                if (checkSub(curNode, subRoot))
                {
                    return true;
                }
            }
            q.pop();
            if (curNode != nullptr && curNode->left != nullptr)
            {
                q.push(curNode->left);
            }
            if (curNode != nullptr && curNode->right != nullptr)
            {
                q.push(curNode->right);
            }
        }
        return false;
    }
};