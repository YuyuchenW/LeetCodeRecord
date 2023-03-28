#include <queue>
using namespace std;
// Definition for a Node.
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        queue<Node *> q;
        if (root != nullptr)
        {
            q.push(root);
        }
        while (!q.empty())
        {

            queue<Node *> tq = q;
            while (!tq.empty())
            {
                Node *curNode = tq.front();
                tq.pop();
                q.pop();
                if (curNode != nullptr)
                {
                    if (curNode->left != nullptr)
                    {
                        q.push(curNode->left);
                    }
                    if (curNode->right != nullptr)
                    {
                        q.push(curNode->right);
                    }
                    if (tq.empty())
                    {
                        curNode->next = nullptr;
                    }
                    else
                    {
                        curNode->next = tq.front();
                    }
                }
            }
        }
        return root;
    }
};