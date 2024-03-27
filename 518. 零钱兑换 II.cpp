#include <vector>

using namespace std;

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        int res = 0;
        backtrack(0, amount, coins, res);
        return res;
    }

    void backtrack(int sum, int target, vector<int> &coins, int& res)
    {
        if (res == target)
        {
            ++res;
            return;
        }
        if (res >= target)
        {
            return;
        }
        for (size_t i = 0; i < coins.size(); i++)
        {
            backtrack(sum + coins[i], target, coins, res);
        }
    }
};