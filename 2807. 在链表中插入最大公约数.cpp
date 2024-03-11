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
    ListNode *insertGreatestCommonDivisors(ListNode *head)
    {
        if (head->next == nullptr)
        {
            return head;
        }
        ListNode *dump = head;
        ListNode *next = nullptr;
        int c = 0;
        while (dump->next != nullptr)
        {
            next = dump->next;
            c = measure(dump->val, next->val);
            dump->next = new ListNode(c);
            dump->next->next = next;
            dump = dump->next;
        }
        return head;
    }

    int measure(int a, int b)
    {
        if (a < b)
        {
            int c = a;
            a = b;
            b = c;
        }

        int c = a % b;
        while (c != 0)
        {
            a = b;
            b = c;
            c = a % b;
        }
        return c;
    }
};