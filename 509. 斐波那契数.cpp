#include<vector>
using namespace std;
class Solution {
public:
    int fib(int n) {
        vector<int> f(n+1,0);
        f[0] = 0;
        f[1] = 1;
        if (n<=1)
        {
            return f[n];
        }


        for (size_t i =2; i <= n; ++i )
        {
            f[i] = f[i-1]+f[i-2];
        }
        
        return f[n];
        
    }
};