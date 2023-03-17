#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> result;
    vector<int> path;
    void trackingback(int numSize, vector<int> &nums,vector<int>& usedList)
    {
        if (path.size() == numSize)
        {
            result.push_back(path);
            return;
        }
        for (size_t i = 0; i < numSize; ++i)
        {
            if (usedList[i])
            {
                continue;
            }
            
            path.push_back(nums[i]);
            usedList[i]= 1;
            trackingback(numSize, nums,usedList);
            path.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        
        for (size_t i = 0; i < nums.size(); i++)
        {
            vector<int> usedList(nums.size(),0);
            path.push_back(nums[i]);
            usedList[i] = 1;
            trackingback(nums.size(), nums,usedList);
        }

        return result;
    }
};