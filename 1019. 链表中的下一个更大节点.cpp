#include<vector>
using namespace std;
#include<stack>
// Definition for singly-linked list.
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

//     vector<int> nextLargerNodes(ListNode* head) {
        
//         vector<int> varArr;
//         ListNode* temp = new ListNode(0);
//         temp->next = head;
//         while (head !=nullptr)
//         {

//             varArr.push_back(head->val);
//             head = head->next;
//         }
//         vector<int> result(varArr.size(),0);
//         for (size_t i = 0; i < varArr.size()-1; i++)
//         {
//             int var = varArr[i];
//             for (size_t j = i+1; j < varArr.size(); j++)
//             {
//                 if (varArr[j]>var)
//                 {
//                     result[i] = varArr[j];
//                     break;
//                 }
//             }
//         }
//         return varArr;
//     }
// };

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        int cnt = 0;
        vector<int> result;
        stack<pair<int,int>> st;//first index,second var
        while (head!=nullptr)
        {
            result.push_back(0);
            while (!st.empty()&& head->val>st.top().second)
            {
                result[st.top().first] = head->val;
                st.pop();
            }
            st.push({cnt,head->val});
            head = head->next;
            ++cnt;
        }
        return result;
    }
};
