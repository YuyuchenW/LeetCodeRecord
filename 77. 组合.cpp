#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void tback(int n,int k,int index){
        if (path.size()==k)
        {
            result.push_back(path);
            return;
        }
        for (size_t i = index; i <= n; ++i)
        {
            path.push_back(i);
            tback(n,k,i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        for (size_t j = 1; j <= n; j++)
        {
            tback(n,k,j);
        }
        
        return result;
    }
};