#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int res = 0;
        unordered_map<int,int> mp;
        for (size_t i = 0; i < nums.size()-1; i++)
        {
            for (size_t j = i+1; j < nums.size(); j++)
            {
                ++mp[nums[i] * nums[j]];
            }
        }
        for (auto i = mp.begin(); i != mp.end(); i++)
        {
            if(i->second <= 1) continue;
            res += (i->second) * (i->second-1) *4;
        }
        return res;
    }
};