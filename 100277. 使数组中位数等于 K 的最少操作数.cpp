#include <algorithm>
#include <vector>
using namespace std;
class Solution
{
public:
    long long minOperationsToMakeMedianK(vector<int> &nums, int k)
    {
        if (nums.size() == 1)
        {
            return abs(nums[0] - k);
        }
        
        long long res = 0l;

        sort(nums.begin(), nums.end());
        int mid = nums.size() / 2;
        if (nums[mid] == k)
        {
            return 0;
        }
        res += abs(nums[mid] - k);
        for (int i = mid -1; i >= 0; --i)
        {
            if (nums[i] <= k)
            {
                break;
            }
            res += nums[i] - k;
        }
        for (int i = mid + 1; i < nums.size(); ++i)
        {
            if (nums[i] >= k)
            {
                break;
            }
            res += k - nums[i];
        }
        return res;    
    }
};