#include<vector>
using namespace std;


class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int max = findMax(nums);
        int sum = k*(k-1)/2;
        return max*k +  sum;
    }
    int findMax(vector<int>& nums)
    {
        int max = -1;
        for(int& i : nums)
        {
            max = max> i? max : i;
        }
        return max;        
    }
};