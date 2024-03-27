/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        int cnt = 0;
        ListNode *cur = head;
        while (cur)
        {
            ++cnt;
            cur = cur->next;
        }

        ListNode *dump = new ListNode(0, head);
        ListNode *p0 = dump;
        cur = dump->next;
        ListNode *pre = nullptr;
        while (cnt >= 2)
        {
            cnt -= 2;
            for (int i = 0; i < 2; i++)
            {
                ListNode *nxt = cur->next;
                cur->next = pre;
                pre = cur;
                cur = nxt;
            }
            ListNode *nxt = p0->next;
            p0->next->next = cur;
            p0->next = pre;
            p0 = nxt;
        }

        return dump->next;
    }
};
// @lc code=end
