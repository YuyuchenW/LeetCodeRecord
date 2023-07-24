  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* oddList = new ListNode();
        ListNode* evenList = new ListNode();
        ListNode* oddDp = oddList;
        ListNode* evenDp = evenList;

        int cnt = 1;

        while (head!= nullptr)
        {
            if (cnt%2)
            {
                oddList->next = head;
                oddList = oddList->next;
            }
            else{
                evenList->next = head;
                evenList = evenList->next;
            }
            
            ++cnt;
            head = head->next;
        }
        evenList ->next = nullptr;
        oddList->next = evenDp->next;
        return oddDp->next;
    }
};