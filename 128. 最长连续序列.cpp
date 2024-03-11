#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(int i = 0;i < nums.size();++i)
        {
            st.emplace(nums[i]);
        }    
        
        int currentNum = -1;
        int maxLen = 0;
        int currentLen= 0;
        for(auto& i : st)
        {
            currentNum = i;
            currentLen = 1;
            if (st.count(currentNum - 1))
            {
                continue;
            }
            
            while(st.count(++currentNum))
            {
                currentLen++;
            }
            maxLen = max(maxLen, currentLen);
        }
        return maxLen;
    }
};