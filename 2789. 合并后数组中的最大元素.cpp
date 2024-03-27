#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        if (nums.size() == 1)
        {
            return nums[0];
        }
        
        stack<int> st;
        st.emplace(nums[0]);
        int max = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] > st.top())
            {
                st.emplace(nums[i]);
            }
            else
            {
                int tmp = st.top();
                st.pop();
                tmp += nums[i];
                max = max > tmp ? max : tmp;
                st.emplace(tmp);
            }
        }
    }
};