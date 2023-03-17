#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rowSize = mat.size();
        int colSize = mat[0].size();
        vector<int> dx = {1,0,0,-1};
        vector<int> dy = {0,1,-1,0};
        vector<vector<int>> result(rowSize,vector<int>(colSize,INT64_MAX));
        queue<pair<int,int>> q;
        for (size_t i = 0; i < rowSize; i++)
        {   
            for (size_t j = 0; j < colSize; j++)
            {   
                if (mat[i][j] == 0)
                {
                    result[i][j] = 0;
                    q.push(pair<int,int>(i,j));
                }
            }
        }
        while (!q.empty())
        {
            int r = q.front().first, c  = q.front().second;
            q.pop();
            for (size_t i = 0; i < 4; i++)
            {
                int newX = r +dx[i];
                int newY = c +dy[i];
                if (newX>=0&&newX<rowSize&&newY>=0&&newY<colSize)
                {
                    if (result[r][c]+1<result[newX][newY])
                    {
                        result[newX][newY] = result[r][c]+1;
                        q.push(pair<int,int>(newX,newY));
                    }
                }
            }
            
        }
        return result; 
    }
};