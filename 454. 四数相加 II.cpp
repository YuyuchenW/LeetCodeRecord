#include <vector>
#include <unordered_map>
using namespace std;

// class Solution
// {
// public:
//     int result = 0;
//     vector<int> path;

//     void backTracking(const vector<vector<int>> &vec, int &sum, int index)
//     {
//         if (path.size() == 4)
//         {
//             if (sum == 0)
//             {
//                 ++result;
//             }
//             return;
//         }

//         for (size_t i = 0; i < vec[index].size(); i++)
//         {
//             sum += vec[index][i];
//             path.push_back(vec[index][i]);
//             backTracking(vec, sum, index + 1);
//             sum -= vec[index][i];
//             path.pop_back();
//         }
//     }
//     int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
//     {
//         int sum = 0;
//         vector<vector<int>> vec = {nums1, nums2, nums3, nums4};
//         backTracking(vec,sum,0);
//         return result;
//     }
// };

class Solution
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        unordered_map<int, int> mp;
        for (int a : nums1)
        {
            for (int b : nums2)
            {
                ++mp[a + b];
            }
        }

        int cnt = 0;

        for (int c : nums3)
        {
            for (int d : nums4)
            {
                int tem = 0 - (c + d);
                if (mp.count(tem))
                {
                    cnt += mp[tem];
                }
            }
        }
        return cnt;
    }
};