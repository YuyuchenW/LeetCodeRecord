#include<vector>
using namespace std;


class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int maxArr = 0;
        for (size_t i = 0; i < k; i++)
        {
            maxArr += nums[i];
        }
        int left = 0;
        int right = k-1;
        int tem = maxArr;
        while (right < nums.size() -1)
        {
            ++right;
            tem = maxArr - nums[left]  + nums[right];
            maxArr = tem > maxArr ? tem : maxArr;
            ++left;
        }
        
        return (double)maxArr / k;
    }
};