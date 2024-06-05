/*
 * @lc app=leetcode.cn id=1535 lang=cpp
 *
 * [1535] 找出数组游戏的赢家
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int getWinner(vector<int> &arr, int k)
    {
        int n = arr.size();
        if (k >= n)
            return *max_element(arr.begin(), arr.end());
        int win = arr[0];
        int win_count = 0;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] > win)
            {
                win = arr[i];
                win_count = 1;
            }
            else
            {
                win_count++;
            }
            if (win_count == k)
                return win;
        }
        return win;
    }
};
// @lc code=end
