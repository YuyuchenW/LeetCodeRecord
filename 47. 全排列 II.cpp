#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> path;
    vector<vector<int>> result;
    void backTracking(vector<int>& nums, vector<bool>& visited)
    {
        if (nums.size() == path.size())
        {
            result.push_back(path);
        }
        
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (i>0)
            {
                if (nums[i-1] == nums[i] && visited[i-1] == false)
                {
                    continue;
                }
            }
            if (visited[i] == true)
            {
                continue;
            }
            visited[i] = true;
            path.push_back(nums[i]);
            backTracking(nums,visited);
            path.pop_back();
            visited[i] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<bool> visited(nums.size(),false);
        backTracking(nums,visited);
        return result;
    }
};
