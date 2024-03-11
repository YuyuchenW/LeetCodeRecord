#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts)
    {
        std::sort(horizontalCuts.begin(), horizontalCuts.end());
        std::sort(verticalCuts.begin(), verticalCuts.end());
        int max_h = getMaxLength(h, horizontalCuts);
        int max_w = getMaxLength(w, verticalCuts);
        long long res = ((long long)max_h * (long long)max_w) % 1000000007;
        return res;
    }
    int getMaxLength(int n, vector<int> &vec)
    {
        int res = vec[0] > n - vec.back() ? vec[0] : n - vec.back();

        for (size_t i = 1; i < vec.size(); i++)
        {
            int n = vec[i] - vec[i - 1];
            res = res > n ? res : n;
        }

        return res;
    }
};