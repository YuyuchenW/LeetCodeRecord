#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int size = grid.size();
        unordered_map<string,int> ump;
        int ans = 0;
        for (size_t i = 0; i < size; i++)
        {
            string arrStr = "";
            for (size_t j = 0; j < size; j++)
            {
                arrStr += to_string(grid[i][j]);
                arrStr += ",";
            }
            ++ump[arrStr];    
        }

        for (size_t i = 0; i < size; i++)
        {
            string arrStr = "";
            for (size_t j = 0; j < size; j++)
            {
                arrStr += to_string(grid[j][i]);
                arrStr += ",";
            }

            auto it = ump.find(arrStr);
            if (it != ump.end())
            {
                ans += it->second;   
            }          
        }
        return ans;
    }
};