#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution
{
public:
    int numberOfBoomerangs(vector<vector<int>> &points)
    {
        int map[20000][20000] = {0};

        int res = 0;
        for (int i = 0; i < points.size(); ++i)
        {
            unordered_map<int, int> path;
            for (int j = 0; j < points.size(); ++j)
            {
                if (i == j)
                {
                    continue;
                }
                int dist = (points[i][0] - points[j][0])*(points[i][0] - points[j][0]) + (points[i][1] - points[j][1])*(points[i][1] - points[j][1]);

                ++ path[dist];
            }
            for (auto &p : path)
            {
                if (p.second > 1)
                {
                    res += p.second * (p.second - 1);
                }
            }
        }
        return res;
    }
};