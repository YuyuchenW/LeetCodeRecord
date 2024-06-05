/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
    void reorderList(ListNode *head)
    {
        auto findMiddle = [](ListNode *fhead) -> ListNode *
        {
            ListNode *slow = fhead, *fast = fhead;
            while (fast && fast->next)
            {
                slow = slow->next;
                fast = fast->next->next;
            }
            return slow;
        };
        ListNode *mid = findMiddle(head);

        auto reverse = [](ListNode *reHead) -> ListNode *
        {
            ListNode *prev = nullptr, *curr = reHead;
            while (curr)
            {
                ListNode *next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            return prev;
        };
        ListNode *reHead = reverse(mid);

        while (reHead->next)
        {
            ListNode *hNext = head->next;
            ListNode *reNext = reHead->next;
            head->next = reHead;
            reHead->next = hNext;
            head = hNext;
            reHead = reNext;
        }
    }
};
// @lc code=end
