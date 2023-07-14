#include<stack>

using namespace std;
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1;
        stack<int> st2;
        while (l1!=nullptr)
        {
            st1.push(l1->val);
            l1= l1->next;
        }
        while (l2!=nullptr)
        {
            st2.emplace(l2->val);
            l2= l2->next;
        }
        int flag = 0;

        ListNode* res = new ListNode();
        while (!st1.empty() || !st2.empty()|| flag)
        {
            if (!st1.empty() && !st2.empty())
            {
                int tem = st1.top() + st2.top();
                st1.pop();
                st2.pop();
                res->val = tem %10 +flag;
                res->next = new ListNode();
                res = res->next;

                flag = (tem>=10);
            }
            else if (!st1.empty() &&st2.empty())
            {
                res->val = (st1.top() +flag)%10;
                res->next = new ListNode();
                res = res->next;

                flag = (st1.top() +flag)>=10;
                st1.pop();
            }
             else if (st1.empty() &&!st2.empty())
            {
                res->val = (st2.top() +flag)%10;
                res->next = new ListNode();
                res = res->next;

                flag = (st2.top() +flag)>=10;
                st2.pop();
            }
            else
            {
                res->val = 1;
            }
        }
        return res;      
    }
};