#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        int map1[2001] = {0};
        int map2[2001] = {0};
        vector<vector<int>> res(2);
        for (int i : nums1)
        {
            ++map1[i + 1000];
        }

        for (int i : nums2)
        {
            if (map1[i] == 0)
            {
                
                if (res[1].size() < 2)
                {
                    res[1].push_back(i);
                }
            }
            ++map2[i + 1000];
        }

        for (int i : nums1)
        {
            if (map2[i] == 0)
            {
                
                if (res[0].size() < 2)
                {
                    res[0].push_back(i);
                }
                else{
                    return res;
                }
            }
        }
        return res;
    }
};