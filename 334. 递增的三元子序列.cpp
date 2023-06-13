#include <vector>
using namespace std;

// class Solution {
// public:
//     bool increasingTriplet(vector<int>& nums) {
//         int cnt = 0;
//         if(nums.size() <= 2)
//         {
//             return false;
//         }

//         for (size_t i = 0; i < nums.size()-1; --i)
//         {
//             if (nums[i] < nums[i+1])
//             {
//                 ++cnt;
//                 if(cnt == 2)
//                 {return true;}
//             }
//             else{
//                 cnt = 0;
//             }
//         }
//         return  false;
//     }
// };

class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        if (nums.size() < 3)
        {
            return false;
        }
        int mid = __INT_MAX__;
        int sm = __INT_MAX__;
        for (int n : nums)
        {
            if (n < sm)
            {
                sm = n;
            }
            else if (n < mid)
            {
                mid = n;
            }
            else if (n > mid)
            {
                return true;
            }
        }
        return false;
    }
};