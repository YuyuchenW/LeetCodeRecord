#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<string> findHighAccessEmployees(vector<vector<string>> &access_times)
    {
        unordered_map<string, vector<int>> map;
        vector<string> res;
        for (size_t i = 0; i < access_times.size(); i++)
        {
            auto it = map.find(access_times[i][0]);
            if (it == map.end())
            {
                vector<int> t;
                map.emplace(pair<string, vector<int>>(access_times[i][0], t));
                it = map.find(access_times[i][0]);
            }

            it->second.push_back(stoi(access_times[i][1]));
        }

        for (auto i : map)
        {
            if (i.second.size() > 2)
            {
                int visited[101] = {0};
                int cnt = 0;
                int min
                sort(i.second.begin(), i.second.end());
                    for (size_t j = 0; j < i.second.size() - 1; ++j)
                    {
                        if (i.second[j + 1] - i.second[j] < 100)
                        {
                            if (visited[j] == 0)
                            {
                                ++cnt;
                                visited[j] = 1;
                            }
                            if (visited[j + 1] == 0)
                            {
                                ++cnt;
                                visited[j + 1] = 1;
                            }
                        }
                    }
                if (cnt == 3)
                {
                    res.push_back(i.first);
                }
            }
        }
        return res;
    }
};