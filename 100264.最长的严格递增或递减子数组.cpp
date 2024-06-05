#include <vector>
using namespace std;

class Solution
{
public:
    int longestMonotonicSubarray(vector<int> &nums)
    {
        if (nums.size() <= 1)
        {
            return 1;
        }

        int left = 0, right = 1;
        int res = 1;
        for (right; right < nums.size(); ++right)
        {
            if (nums[right] > nums[right - 1])
            {
                res = max(res, right - left + 1);
            }
            else
            {
                left = right;
            }
        }
        int left = 0, right = 1;
        for (right ; right < nums.size(); ++right)
        {
            if (nums[right] < nums[right - 1])
            {
                res = max(res, right - left + 1);
            }
            else
            {
                left = right;
            }
        }
        return res;
    }
};