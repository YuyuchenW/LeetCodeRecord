#include<vector>

using namespace std;
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int size = nums.size();
        int left = 0, right = nums.size()-1;
        int ans = 0;
        while (left <right)
        {
            ans = max(ans, min(nums.begin()+left,nums.begin()+right) );            
        }
    }
};