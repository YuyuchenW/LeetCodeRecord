#include <vector>
using namespace std;
class Solution
{
public:

    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        if (k<2)
        {
            return 0;
        }
        int left =0;
        int right =0;
        int cnt = 0;
        int muti = 1;
        int n = nums.size();
        while (right != n)
        {
            muti = muti* nums[right];
            while (muti>= k)
            {
                muti = muti/nums[left];
                ++left;
            }
            ++right;
            cnt += right -left;
            
        }
        return cnt;
        
    }
};