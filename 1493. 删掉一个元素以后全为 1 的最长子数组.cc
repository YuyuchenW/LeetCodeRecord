#include <vector>
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int left = 0;
        int right = 0;
        int res = 0;
        int cntZero = nums[0] == 0 ? 1 : 0;
        while (right < nums.size())
        {
            if (cntZero < 2)
            {

                ++right;
                if (nums[right] == 0)
                {
                    ++cntZero;
                }
                if (cntZero == 2)
                {
                    continue;
                }

                res = res > (right - left + 1) ? res : right - left + 1;
                continue;
            }
            if (nums[left] == 0)
            {
                --cntZero;
            }
            ++left;
        }

        return res==nums.size()? res-1 : res;
    }
};