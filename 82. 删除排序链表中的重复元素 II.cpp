
#include <unordered_map>
// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

using namespace std;
class Solution
{
public: 
    {
        if (head == nullptr)
            return head;
        std::unordered_map<int, int> map;
        ListNode *cur = head;
        ListNode *pre = head;

        while (cur != nullptr)
        {
            auto it = map.find(cur->val);
            ++map[cur->val];
            if (it != map.end())
            {
                pre->next = cur->next;
                cur = cur->next;
            }
            else
            {
                pre = cur;
                cur = cur->next;
            }
        }

        cur = head;
        ListNode *dumy = new ListNode(0);
        ListNode *tmp = dumy;
        while (cur != nullptr)
        {
            if (map[cur->val] > 1)
            {
                cur = cur->next;
                continue;
            }
            tmp->next = cur;
            tmp = tmp->next;
            cur = cur->next;
            tmp->next = nullptr;
        }
        return dumy->next;
    }
};