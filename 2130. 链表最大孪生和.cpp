#include<vector>
using namespace std;

//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
// --------------------------------------------------------
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> nums;
        while (head!=nullptr)
        {
          nums.push_back(head->val);
          head = head->next;
        }
        int left = 0;
        int right = nums.size();
        int res = 0;
        while (left<right)
        {
          res = res>(nums[left]+nums[right])? res: (nums[left]+nums[right]);
          ++left;
          --right;
        }
        return res;
    }
};

//----------------------------------------------------------

class Solution {
public:
    int pairSum(ListNode* head) {
      ListNode* slow = head;
      ListNode* fast = head;
      ListNode* pre = nullptr;

      while (fast!=nullptr && fast->next != nullptr)
      {
        fast = fast->next->next;
        ListNode* nextSlow = slow->next;
        slow->next = pre;
        pre = slow;
        slow = nextSlow;
      }
      int res = 0;

      while (slow!=nullptr)
      {
        res = res> (slow->val+pre->val) ?  res : (slow->val+pre->val);
        pre= pre->next;
        slow = slow->next; 
      }
      return res;
    }
};