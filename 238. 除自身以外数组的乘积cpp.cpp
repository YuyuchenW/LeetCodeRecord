#include<vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(),1);

        int left = 1;
        int right = 1;
        for (size_t i = 0,  j = nums.size()-1; i < nums.size(); ++i,--j)
        {
            res[i] *= left;
            res[j] *= right;
            left *= nums[i];
            right *= nums[j];
        }
        return res;
        
    }
};