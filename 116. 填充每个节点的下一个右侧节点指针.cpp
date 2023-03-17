#include <stdio.h>
#include <deque>
using namespace std;
// Definition for a Node.
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        deque<Node *> dq;
        dq.emplace_back(root);
        while (dq[0] != nullptr)
        {
            deque<Node *> dq_son;
            for (int i = 0; i < dq.size() - 1; ++i)
            {
                dq[i]->next = dq[i + 1];
                dq_son.push_back(dq[i]->left);
                dq_son.push_back(dq[i]->right);
                dq.pop_front();
            }
            dq[dq.size() - 1]->next = NULL;
            dq.pop_front();
            dq_son.push_back(dq[dq.size() - 1]->left);
            dq_son.push_back(dq[dq.size() - 1]->right);
            dq = dq_son;
        }
        return root;
    }
};