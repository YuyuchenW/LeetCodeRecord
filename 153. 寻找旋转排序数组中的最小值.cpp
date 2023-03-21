#include <vector>
using namespace std;
//[3,4,5,1,2]
class Solution
{
public:
    void searchMinHelper(vector<int> &nums, int left, int right, int &result)
    {
        if (left >= right)
        {
            return;
        }
        if (right - left == 1)
        {
            result = nums[left] > nums[right] ? nums[right] : nums[left];
            return;
        }

        int mid = (right + left) / 2;
        int leftValue = nums[left];
        int rightValue = nums[right];
        int midValue = nums[mid];
        if (leftValue<midValue)
        {
            searchMinHelper(nums,mid,right,result);
        }
        else{
            searchMinHelper(nums,left,mid,result);
        }
        
    }
    int findMin(vector<int> &nums)
    {
        if (nums.size()==1)
        {
            return nums[0];
        }
        
        if (nums[0]<nums.back())
        {
            return nums[0];
        }
        
        int result = 0;
        searchMinHelper(nums,0,nums.size()-1,result);
        return result;
    }
};