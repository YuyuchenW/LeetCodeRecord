#include<string>
using namespace std;
class Solution {
public:
    int longestDecomposition(string text) {
        if (text.empty())
        {
            return 0;
        }
        int n = text.size();
        for (size_t i = 1; i <= n/2; i++)
        {
            if (text.substr(0,i) == text.substr(n-i))
            {
                return 2+ longestDecomposition(text.substr(i,n-2*i));
            }
        }
        
        return 1;
    }
};