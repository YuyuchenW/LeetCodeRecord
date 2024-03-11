
#include <vector>
using namespace std;
class Solution
{
public:
    int alternatingSubarray(vector<int> &nums)
    {
        int left = 0;
        int right = 1;
        int res = -1;
        while (right < nums.size())
        {
            int cnt = right - left;
            if (cnt % 2 == 0)
            {
                if (nums[left] == nums[right])
                {
                    res = cnt;
                }
                else
                {
                    left = right;
                }
            }
            else
            {
                if ((nums[left] + 1) == nums[right])
                {
                    res = cnt;
                }
                else
                {
                    left = right;
                }
            }
            ++right;
        }
        return res == -1 ? -1: res + 1;
    }
};