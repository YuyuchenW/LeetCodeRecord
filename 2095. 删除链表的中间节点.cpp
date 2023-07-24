

  //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* res = head;
        ListNode*  low = head;
        ListNode* fast = head;
        ListNode* pre = low;

        while (fast != nullptr && fast->next != nullptr)
        {
            pre = low;
            low = low->next;
            fast = fast->next->next;
        }
        
        if (pre->next!= nullptr)
        {
            pre ->next = pre->next->next;
        }
        else{
            pre = nullptr;
        }
        return res;
        
    }
};