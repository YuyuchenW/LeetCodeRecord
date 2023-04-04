#include<vector>
using namespace std;
class Solution {
public:

    bool searchTarget(vector<int>& nums,int right,int target)
    {
        int left = 0;
        
        while (left<=right)
        {
            int mid = (left+right)/2;
            if (nums[mid] == target)
            {
                return true;
            }
            else if(nums[mid]<target){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return false;
        
    }
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int doubleDiff = 2* diff;
        int cnt =0;
        for (size_t i = nums.size() -1; i >=2; i--)
        {
            if (nums[i] < doubleDiff)
            {
                break;
            }
            int right  = i;
            if (searchTarget(nums,right,nums[i]-diff) && searchTarget(nums,right,nums[i]-doubleDiff))
            {
                ++cnt;
            }
        }
        return cnt;
    }
};