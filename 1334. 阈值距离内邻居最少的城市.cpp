#include <vector>
using namespace std;
class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<int>> map(n, vector<int>(n, __INT_MAX__));

        for (size_t i = 0; i < edges.size(); i++)
        {
            map[edges[i][0]][edges[i][1]] = edges[i][2];
            map[edges[i][1]][edges[i][0]] = edges[i][2];
        }

        for (size_t k = 0; k < n; k++)
        {
            for (size_t i = 0; i < n; i++)
            {
                for (size_t j = 0; j < n; j++)
                {
                    if (i == j || map[i][k] == __INT_MAX__ || map[j][k] == __INT_MAX__)
                    {
                        continue;
                    }
                    map[i][j] = (map[i][j] < (map[i][k] + map[j][k])) ? map[i][j] : (map[i][k] + map[j][k]);
                }
            }
        }

        int res = 0;
        int min_cnt = __INT_MAX__;

        for (size_t i = 0; i < n; i++)
        {
            int cnt = 0;
            for (size_t j = 0; j < n; j++)
            {
                if (i!=j && map[i][j] <= distanceThreshold)
                {
                    ++cnt;
                }
            }
            if (cnt <= min_cnt)
            {
                res = i;
                min_cnt = cnt;
            }
        }
        return res;        
    }
};