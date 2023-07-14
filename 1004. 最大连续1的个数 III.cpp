#include<vector>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int res = 0;
        int zeroNums = 0;

        while (right < nums.size())
        {
            if (nums[right] == 0)
            {
                ++zeroNums;
                if (zeroNums <= k)
                {
                    ++right;
                }
                else
                {
                    while (zeroNums > k && left<= right)
                    {
                        if (nums[left] == 0)
                        {
                            --zeroNums;
                        }
                        ++left;
                    }
                    ++right;
                }
            }
            else{
                ++right;
            }
            res = res> right-left? res :right-left;
        }
        return res;
    }
};