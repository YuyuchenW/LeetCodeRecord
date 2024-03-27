/*
 * @lc app=leetcode.cn id=445 lang=cpp
 *
 * [445] 两数相加 II
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        l1 = reverse(l1);
        l2 = reverse(l2);
        ListNode *head = new ListNode(0);
        ListNode *dump = new ListNode(0, head);
        int carry = 0;
        while (l1 && l2)
        {
            int sum = l1->val + l2->val + carry;
            carry = sum / 10;
            head->next = new ListNode(sum % 10);
            head = head->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1)
        {
            int sum = l1->val + carry;
            carry = sum / 10;
            head->next = new ListNode(sum % 10);
            head = head->next;
            l1 = l1->next;
        }
        while (l2)
        {
            int sum = l2->val + carry;
            carry = sum / 10;
            head->next = new ListNode(sum % 10);
            head = head->next;
            l2 = l2->next;
        }
        if (carry)
        {
            head->next = new ListNode(carry);
            head = head->next;
        }

        return reverse(dump->next->next);
    }

    ListNode *reverse(ListNode *head)
    {
        ListNode *pre = nullptr;
        ListNode *cur = head;
        while (cur)
        {
            ListNode *temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};

// @lc code=end
