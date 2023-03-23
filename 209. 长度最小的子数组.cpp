#include<vector>
#include<stdint.h>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int areaLeft = 0;
        int areaRight = 0;
        int result = INT64_MAX;
        int sum = 0;
        while (areaRight<nums.size())
        {
            
            if (sum== target)
            {
                result = result<(areaRight-areaLeft)? result: areaRight-areaLeft;
            }
            else if (sum<target)
            {
                sum+= nums[areaRight];
                ++areaRight;
            }
            else{
                sum =sum - nums[areaLeft];
                ++areaLeft;
            }
        }
        
        return result == INT64_MAX? 0:result;
        
    }
};