#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
         if(nums.size() == 1)
        {
            if(nums[0] == target){return {0,0};}
            return {-1,-1};
        }
        
        int left =0; int right = nums.size()-1;
        int middle;
        int result_l = -1;
        int result_r = -1;
        while (left <=right )
        {
            middle = (left+right)/2;
            if(nums[middle] == target){result_l = middle;break;}
            else if (nums[middle]>target)
            {
                right = middle-1 ;
                
            }
            else{
                left = middle+1;
            }
        }
        if (result_l != -1)
        {
            result_r = result_l;
            for (result_l; result_l > 0;)
            {
                if (nums[result_l - 1] == target)
                {
                    --result_l;
                }
                else
                {
                    break;
                }
            }
            for (result_r; result_r < nums.size()-1;)
            {
                if (nums[result_r + 1] == target)
                {
                    ++result_r;
                }
                else
                {
                    break;
                }
            }
            return {result_l, result_r};
        }
        return {-1, -1};
    }
};