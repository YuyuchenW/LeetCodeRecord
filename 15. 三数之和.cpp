#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                return result;
            }
            if (i > 0)
            {
                if (nums[i - 1] == nums[i])
                {
                    continue;
                }
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                int sm = nums[left] + nums[i] + nums[right];
                if (sm > 0)
                {
                    --right;
                }
                else if (sm < 0)
                {
                    left++;
                }
                else
                {
                    result.push_back({nums[i], nums[left], nums[right]});
                    while (right > left && nums[right] == nums[right - 1])
                        right--;
                    while (right > left && nums[left] == nums[left + 1])
                        left++;
                    right--;
                    left++;
                }
            }
        }
        return result;
    }
};