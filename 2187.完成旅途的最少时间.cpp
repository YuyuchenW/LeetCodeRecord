/*
 * @lc app=leetcode.cn id=2187 lang=cpp
 *
 * [2187] 完成旅途的最少时间
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    long long minimumTime(vector<int> &time, int totalTrips)
    {

        if (time.size() == 1)
        {
            return (long long)time[0] * (long long)totalTrips;
        }

        sort(time.begin(), time.end());

        long long ans = 0;

        long long right = (long long)totalTrips * (long long)time[0];
        long long left = time[0];

        while (left <= right)
        {
            long long mid = (left + right) / 2;
            long long s = cal(mid, time);
            if (s < totalTrips)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return left;
    }

    long long cal(long long t, vector<int> &nums)
    {
        long long ans = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (t >= nums[i])
            {
                ans += t / nums[i];
            }
        }
        return ans;
    }
};
// @lc code=end
