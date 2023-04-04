#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> path;
    vector<vector<int>> result;
    int sum = 0;
    void BackTracking(vector<int> &candicates, int target, int index, vector<int> &visited)
    {
        if (sum == target)
        {
            result.push_back(path);
            return;
        }
        if (sum > target)
        {
            return;
        }
        for (size_t i = index; i < candicates.size(); ++i)
        {
            if (i > 0)
            {
                if (candicates[i] == candicates[i - 1] && visited[i - 1] == 0)
                {
                    continue;
                }
            }
            visited[i] = 1;
            sum += candicates[i];
            path.push_back(candicates[i]);
            BackTracking(candicates, target, i + 1, visited);
            sum -= candicates[i];
            visited[i] = 0;
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<int> visited(candidates.size(), 0);
        BackTracking(candidates,target,0,visited);
        return result;
    }
};