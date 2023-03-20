//先找出k
//index translator
//i<numSize - k -1
//  ori_index -(k+1)  = i      
//else
// ori_index+(numSize - k + 1) = i
// 二分查找
#include<vector>
using namespace std;
class Solution {
public:
    int numsSize = 0;
    int k = -1;
    int indexTranslator(const int& index)
    {
        if (k == -1)
        {
            return index;
        }
        if (index <= k + 1)
        {
            return index+k;
        }
        else
            return index-k-1;
        
        
    }
    int search(vector<int>& nums, int target) {
        numsSize = nums.size();
        if (numsSize ==1)
        {
            return nums[0]==1 ? 0:-1;
        }
        
        for (size_t i = 0; i < numsSize-2; i++)
        {
            if (nums[i]< nums[i+1])
            {
                continue;
            }
            else{
                k = i;
            }
        }
        int left = 0;
        int right = numsSize-1;
        int middle = 0;
        int t_mid = 0;
        while (left <= right)
        {
            middle = (left+right)/2;
            t_mid = indexTranslator(middle);
            if (nums[t_mid] == target)
            {
                return t_mid;
            }
            
            if (nums[t_mid] <target)
            {
                left = target+1;
            }
            else{
                right = target -1;
            }
        }
        return -1;
    }
};