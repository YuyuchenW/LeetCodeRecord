#include <vector>
using namespace std;

class Solution
{
public:
    long long countPairs(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> tb(n);
        for (auto e : edges)
        {
            tb[e[0]].push_back(e[1]);
            tb[e[0]].push_back(e[0]);
        }
        vector<int> visited(n, 0);

        long long res = 0;
        for (size_t i = 0; i < n; i++)
        {
            int size = 0;
            dfs(visited, i, size, tb);
            res += (n - size) * size;
        }

        return (res >> 1);
    }

    void dfs(vector<int> &visited, int x, int &size, vector<vector<int>> &tb)
    {
        if (visited[x] != 0)
        {
            return;
        }
        visited[x] = 1;
        ++size;
        for (int y : tb[x])
        {
            dfs(visited, y, size, tb);
        };
    }
};