#include<vector>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxC = -1;
        for(const int& i : candies)
        {
            maxC = maxC > i ? maxC : i;
        }
        maxC = maxC - extraCandies;
        vector<bool> res(candies.size(),true);
        for (size_t i = 0; i < candies.size(); ++i)
        {
            if (candies[i] <= maxC)
            {
                 res[i] = false;
            }
            
        }
        return res;
    }
};