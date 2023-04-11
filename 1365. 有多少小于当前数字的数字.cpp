#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> result = nums;
        sort(result.begin(),result.end());
        unordered_map<int,int> mp;
        for (size_t i = 0; i < result.size(); i++)
        {
            if(mp.find(result[i])==mp.end()) mp.insert({result[i],i});
        }

        for (size_t i = 0; i < result.size(); i++)
        {
            auto item = mp.find(nums[i]);
            if (item!= mp.end())
            {
                result[i] = item->second;
            }
        }
        
        return result;
    }
};