#include<vector>
using namespace std;
class Solution {
public:
    vector<int> path;
    void trackingBack(vector<int>& nums, vector<vector<int>>& results, int target, int index)
    { 
        if (path.size() == target)
        {          
            results.push_back(path);
            return;
        }
        for (int i = index; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            trackingBack(nums,results,target,i+1);
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> results;
        results.push_back({});
        for (size_t i = 1; i <= nums.size(); i++)
        {
            trackingBack(nums,results,i,0);
        }
        return results;
    }
};