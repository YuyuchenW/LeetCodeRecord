#include<vector>
#include<unordered_map>
using namespace std;

//哈希表方法
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        vector<int> res;
        unordered_map<int,int> ump;

        for (size_t i = 0; i < nums.size(); i++)
        {
            auto it = ump.find(nums[i]);
            if (it != ump.end())
            {
                ++it->second;
            }
            else
            {
                ump[nums[i]] =1;
            }             
        }
        
        for (auto it = ump.begin(); it != ump.end();++it)
        {
            if (it->second == 1)
            {
                res.push_back(it->first);
            }
        }
        return res;        

    }
};

//位运算

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res(2,0);
        int tar = 0;

        for(int num :nums)
        {
            tar ^= num;
        }

        int lastBit = tar  == __WINT_MIN__ ?  tar : (tar & -tar);

        for(int num : nums)
        {
            if (lastBit & num)
            {
                res[0] ^= num;
            }
            else
            {
                res[1] ^= num;
            }
        }
        return res;
    }
};