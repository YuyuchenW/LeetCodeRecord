/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    bool isPalindrome(ListNode *head)
    {
        if (head == nullptr)
        {
            return true;
        }

        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *pre = nullptr;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            ListNode *temp = slow->next;
            slow->next = pre;
            pre = slow;
            slow = temp;
        }
        if (fast != nullptr)
        {
            slow = slow->next;
        }
        while (pre != nullptr && slow != nullptr)
        {
            if (pre->val != slow->val)
            {
                return false;
            }
            pre = pre->next;
            slow = slow->next;
        }
        return true;
    }
};
// @lc code=end
