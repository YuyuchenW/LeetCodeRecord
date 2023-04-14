// Definition for singly-linked list.
#include<unordered_set>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// class Solution {
// public:
//     ListNode *detectCycle(ListNode *head) {
//         std::unordered_set<ListNode*> st;
//         while (head)
//         {
//             if (st.find(head) == st.end())
//             {
//                 st.insert(head);
//                 head = head->next;
//             }
//             else
//             {
//                 return head;
//             }
//         }
//         return nullptr;
//     }
// };
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* low = head;
        ListNode* fast = head;
        while (fast !=nullptr && fast->next!=nullptr)
        {
            low = low->next;
            fast = fast->next->next;
            if (low == fast)
            {
                ListNode* index1 = head;
                ListNode* index2 = low;
                while (index1!=index2)
                {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index2;
            }
        }
        return nullptr;
    }
};




