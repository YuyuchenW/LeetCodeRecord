/*
 * @lc app=leetcode.cn id=2816 lang=cpp
 *
 * [2816] 翻倍以链表形式表示的数字
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
    ListNode *doubleIt(ListNode *head)
    {
        head = reverse(head);
        ListNode *dump = new ListNode(0);
        ListNode *pre = dump;    
        int carry = 0;
        while (head)
        {
            int sum = head->val *2 + carry;
            carry = sum / 10;
            dump->next = new ListNode(sum % 10);
            dump = dump->next;
            head = head->next;
        }
        if (carry)
        {
            dump->next = new ListNode(carry);
            dump = dump->next;
        }
        
        return reverse(pre->next);
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
