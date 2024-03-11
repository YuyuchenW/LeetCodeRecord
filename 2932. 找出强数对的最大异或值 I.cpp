#include <vector>
using namespace std;

class Solution
{
public:
    int maximumStrongPairXor(vector<int> &nums)
    {
        int max = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            for (size_t j = i; j < nums.size(); j++)
            {
                int m = nums[i] >= nums[j] ? nums[i] : nums[j];
                int n = nums[i] < nums[j] ? nums[j] : nums[i];
                if (m - n <= n)
                {

                    int t = nums[i] ^ nums[j];
                    max = max > t ? max : t;
                }
            }
        }
        return max;
    }
};