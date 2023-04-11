#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n==1)
        {
            return {{1}};
        }
        int target = n*n;
        vector<vector<int>> result(n,vector<int>(n,0));
    
        int dx[4] = {0,1,0,-1};
        int dy[4] = {1,0,-1,0};
        int cnt =1;
        int x =0;
        int y =-1;
        int i =0;
        while (cnt <=target)
        {
           int tx = x +dx[i];
           int ty = y+ dy[i];
           if (tx>=0&&tx<n&&ty>=0&&ty<n&& result[tx][ty] == 0)
           {
            result[tx][ty] = cnt;
            ++cnt;
            x = tx;
            y = ty;
           }
           else{
             ++i;
             i = i%4;
           }
        }
        return result;
    }
};