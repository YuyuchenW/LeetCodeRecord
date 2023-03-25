#include <vector>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, int cities, int isVisited[], int i)
    {
        for (size_t j = 0; j < cities; j++)
        {
            if (isConnected[i][j] == 1 && isVisited[j]!=1)
            {
                isVisited[j] = 1;
                dfs(isConnected,cities,isVisited,j);
            }
        }
        
        
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cities  = isConnected.size();
        int isVisited[cities] = {0};
        int cnt =0;
        for (size_t i = 0; i < cities; i++)
        {
            if (!isVisited[i])
            {
                ++cnt;
                dfs(isConnected,cities,isVisited,i);
            }
        }
        return cnt;
    }
};