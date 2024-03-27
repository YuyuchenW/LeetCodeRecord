/*
 * @lc app=leetcode.cn id=2861 lang=cpp
 *
 * [2861] 最大合金数
 */
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>> &composition, vector<int> &stock, vector<int> &cost)
    {
        long long  left = 0;
        long long  right = budget + 100000000ll;

        while (left <= right)
        {
            long long  mid = (left + right) / 2;
            if (check(n, k, budget, composition, stock, cost, mid))
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return left - 1;
    }

    bool check(int &n, int &k, int budget, vector<vector<int>> &composition, vector<int> &stock, vector<int> &cost, long long &target)
    {
        for (int i = 0; i < k; ++i)
        {

            long long sum = 0;
            for (size_t j = 0; j < n; j++)
            {
                long long need = max((long long)composition[i][j] * target - stock[j], 0ll);
                sum += need * cost[j];
            }

            if (sum <= budget)
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
