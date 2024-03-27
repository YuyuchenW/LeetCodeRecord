#include <stack>
#include <unordered_set>
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
class FindElements
{
public:
    FindElements(TreeNode *root)
    {
        stack<TreeNode *> st;

        if (root)
        {
            root->val = 0;
            st.push(root);
        }

        while (!st.empty())
        {
            TreeNode *node = st.top();
            st.pop();

            if (node->right)
            {
                node->right->val = 2 * node->val + 2;
                m_set.emplace(node->right->val);
                st.push(node->right);
            }
            if (node->left)
            {
                node->right->val = 2 * node->val + 1;
                m_set.emplace(node->left->val);
                st.push(node->right);
            }
        }
    }

    bool find(int target)
    {
        return m_set.find(target) != m_set.end();
    }

private:
    std::unordered_set<int> m_set;
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */