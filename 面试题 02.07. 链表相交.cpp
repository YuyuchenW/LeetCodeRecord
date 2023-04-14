#include<stack>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        std::stack<ListNode*> stA;
        std::stack<ListNode*> stB;
        ListNode* res;
        while (headA!=nullptr || headB!=nullptr)
        {
            if (headA)
            {
                stA.push(headA);
            }
            if (headB)
            {
                stB.push(headB);
            }
        }
        while (!stA.empty() && !stB.empty())
        {
            if (stA.top() == stB.top())
            {
                res = stA.top();
                stA.pop();
                stB.pop();
            }
            break;
        }
        return res;
    }
};