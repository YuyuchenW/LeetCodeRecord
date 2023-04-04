#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& results, vector<int> result,int n, int target)
    {
        if (n == target)
        {
            result.push_back(n);
            results.push_back(result);
            return;
        }
        result.push_back(n);
        for (size_t i = 0; i < graph[n].size(); i++)
        {
            dfs(graph,results,result,graph[n][i],target);
        }
        return;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> results;
        vector<int> result;
        dfs(graph,results,result,0,graph.size()-1);
        return results;
    }
};