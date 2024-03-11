#include <vector>
using namespace std;

class Solution
{
public:
    int minOperationsMaxProfit(vector<int> &customers, int boardingCost, int runningCost)
    {
        if (runningCost >= 4 * boardingCost)
        {
            return -1;
        }
        int n = customers.size();
        int waitCount = 0;
        int sum = 0;
        int res = -1;
        int max = 0;
        for (size_t i = 0; i < n; i++)
        {
            if (customers[i] + waitCount <= 4)
            {
                sum += boardingCost * (customers[i] + waitCount) - runningCost;
                waitCount = 0;
            }
            else
            {
                sum += 4 * boardingCost - runningCost;
                waitCount += customers[i] - 4;
            }
            if (sum > max)
            {
                max = sum;
                res = i + 1;
            }
        }
        int i = 1;
        while (waitCount != 0)
        {
            if (waitCount <= 4)
            {
                sum += boardingCost * waitCount - runningCost;
                waitCount = 0;
            }
            else
            {
                sum += 4 * boardingCost - runningCost;
                waitCount -= 4;
            }
            if (sum > max)
            {
                max = sum;
                res += i;
            }
        }

        return res;
    }
};