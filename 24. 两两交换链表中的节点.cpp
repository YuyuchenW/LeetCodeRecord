// Definition for singly-linked list.
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
    ListNode* swapPairs(ListNode* head) {
        if (head==nullptr || head->next == nullptr)
        {
            return head;
        }
        
        ListNode* left = new ListNode(0,head);
        ListNode* result = left;
        while (left->next!=nullptr&& left->next->next!=nullptr)
        {
            ListNode* temp_1 = left ->next;
            ListNode* temp_2 = left->next->next->next;

            left -> next = left->next->next;
            left ->next->next = temp_1;
            left->next->next->next = temp_2;
            left = left->next->next;
        }
        return result->next;
    }
};