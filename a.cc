#include <vector>
#include<set>
using namespace std;

class Solution
{
public:
    vector<int> path;
    int sum = 0;
    set<vector<int>> st;
    void trackingBack(vector<int> &candidates, vector<vector<int>> &result,vector<int>& visited ,  int target)
    {
        if (sum == target)
        {
            if (st.count(visited))
            {
                return;
            }
            st.emplace(visited);
            result.push_back(path);
            return;
        }
        if (sum> target)
        {
            return; 
        }
        

        for (size_t i = 0; i < candidates.size(); i++)
        {
            sum += candidates[i];
            path.push_back(candidates[i]);
            ++visited[i];
            trackingBack(candidates, result,visited, target);
            sum -= candidates[i];
            path.pop_back();
            --visited[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> result;
        vector<int> visited(candidates.size(),0);
        trackingBack(candidates,result,visited,target);
        return result;
    }
};