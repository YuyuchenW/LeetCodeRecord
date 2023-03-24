#include <vector>
#include <stdint.h>
using namespace std;
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int areaLeft = 0;
        int areaRight = 0;
        int result = INT32_MAX;
        int sum = 0;
        while (areaRight != nums.size())
        {
            sum += nums[areaRight];
            if (sum >= target)
            {
                while (sum >= target)
                {
                    sum -= nums[areaLeft];
                    areaLeft++;
                }
                result = min(result, areaRight - areaLeft + 2);
            }

            ++areaRight;
        }

        return result == INT32_MAX ? 0 : result;
    }
};