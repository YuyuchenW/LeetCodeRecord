/*
 * @lc app=leetcode.cn id=3067 lang=cpp
 *
 * [3067] 在带权树网络中统计可连接服务器对数目
 */
#include <functional>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>> &edges, int signalSpeed)
    {
        int n = edges.size() + 1;
        vector<vector<pair<int, int>>> tr(n);
        for (const vector<int> &e : edges)
        {
            tr[e[0]].push_back({e[1], e[2]});
            tr[e[1]].push_back({e[0], e[2]});
        }
        function<int(int, int, int)> dfs = [&](int x, int fa, int sum) -> int
        {
            int cnt = sum % signalSpeed == 0;
            for (auto &[y, wt] : tr[x])
            {
                if (y != fa)
                {
                    cnt += dfs(y, x, sum + wt);
                }
            }
            return cnt;
        };

        vector<int> res(n);
        for (size_t i = 0; i < n; i++)
        {
            int sum = 0;
            for (auto &[y, wt] : tr[i])
            {
                int cnt = dfs(y, i, wt);
                res[i] += cnt * sum;
                sum += cnt;
            }
        }
        return res;
    }
};
// @lc code=end
