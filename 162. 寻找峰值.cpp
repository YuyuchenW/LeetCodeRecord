#include<vector>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        int mid = 0;

        while (left<right)
        {
            mid = (left+right)/2;
            //nums[-1] = nums[n] = -∞
            if (nums[mid]<nums[mid+1])
            {
                left = mid+1;
            }
            else
            {
                right = mid;
            }
        }
        return left;
    }
};