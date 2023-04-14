
// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode * fast = head;

        ListNode *low = new ListNode(-1, head);
        ListNode * result = low;
        while (fast!=nullptr)
        {
            if (fast->val == val)
            {
                fast = fast->next;
                low ->next = fast;
            }
            else
            {
                low = low->next;
                fast = fast->next;
            }
        }
        low ->next = fast;
        return result->next;
    }
};