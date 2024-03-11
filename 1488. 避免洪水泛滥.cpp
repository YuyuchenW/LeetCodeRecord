#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> avoidFlood(vector<int> &rains)
    {
        unordered_map<int, int> ump;

        queue<int> qe;

        vector<int> res(rains.size(), -1);

        for (size_t i = 0; i < rains.size(); i++)
        {

            if (rains[i] != 0)
            {
                auto it = ump.find(rains[i]);
                if (it != ump.end())
                {
                    if (it->second == 1)
                    {
                        return {};
                    }
                    ++it->second;
                }
                else
                {
                    ump.emplace(pair<int,int>(rains[i], 1));
                }

                qe.push()
            }
        }
    }
};