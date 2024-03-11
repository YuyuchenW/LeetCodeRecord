#include <vector>
using namespace std;
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int res = 0;
        int n = height.size();
        if (n == 0)
            return res;
        int left = 0;
        int right = 1;
        while (left < n -1)
        {
            int max = -1;
            int v = 0;
            for (int i = right; i < n; i++)
            {
                if(height[i] >= height[left])
                {
                    right = i;
                    break;
                }
                
                if (max < height[i])
                {
                    max = height[i];
                    right = i;
                }
            }
            for (int i = left+1; i < right; i++)
            {
                v += height[i];
            }
            res += height[left] > height[right] ? height[right] * (right -left -1) - v : height[left] * (right - left -1) - v;
            left = right;
            ++right;
        }
        return res;        
    }
};