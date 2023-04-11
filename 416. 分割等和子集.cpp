#include <vector>
using namespace std;
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;

        for(int x : nums)
        {
            sum+= x;
        }

        if (sum%2 !=0)
        {
            return false;
        }
        sum = sum/2;
        vector<int> dp(10001,0);
         for (size_t i = 0; i < nums.size(); i++)
         {
            for (size_t j = sum ; j >= nums[i]; --j)
            {
                dp[i] = max(dp[i],dp[j-nums[i]+nums[i]]);
            }
            
         }
         if (dp[sum] = sum)
         {
            return true;
         }
         return false;
        
    }
};