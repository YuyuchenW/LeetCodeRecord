#include<vector>
using  namespace std;
class Solution {
public:
    int climbStairs(int n) {
        if(n<= 2){
            return n==1?1:2;
        }
        vector<int> dp(n+1,0);
        dp[1] = 1;
        dp[2] = 2;
        for (size_t i = 3; i < n+1; ++i)
        {
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
        
    }
};