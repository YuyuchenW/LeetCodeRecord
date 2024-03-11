#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int modNum = 1000000007;
    int sumDistance(vector<int> &nums, string s, int d)
    {
        for (size_t j = 0; j < nums.size(); ++j)
        {
            nums[j] += ((s[j] == 'L') ? -1 : 1)*d;
        }

        sort(nums.begin(), nums.end());

        int res = distance(nums);
        return res;
    }

    int distance(vector<int> &nums)
    {
        long long sum = 0;
        long long res = 0;

        for (size_t i = 0; i < nums.size(); i++)
        {
            res = (res + (i * nums[i] - sum)) % modNum;
            sum += nums[i];
        }
        return res;
    }
};