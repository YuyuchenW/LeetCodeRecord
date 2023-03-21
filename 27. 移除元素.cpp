#include<vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int lo; 
        int hi = 0;
        for (lo = 0; lo < nums.size(); ++lo)
        {
                if (nums[lo] == val)
                {
                    continue;
                }
                if (lo!=hi)
                {
                    nums[lo] = nums[hi];
                }
                
                ++hi;
        }
        
    }
};