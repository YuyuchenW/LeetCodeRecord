#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int maximumSum(vector<int> &nums)
    {
        unordered_map<int, int> map;
        int temp = 0;
        int addNum = 0;
        int sum = 0;
        int max = -1;
        for (const int &i : nums)
        {
            temp = i;
            sum = 0;
            while (temp != 0)
            {
                sum += temp % 10;
                temp = temp / 10;
            }
            auto it = map.find(sum);
            if (it != map.end())
            {
                max = max > (it->second + i) ? max : (it->second + i);

                it->second = it->second > i ? it->second : i;
            }
            else
            {
                map.emplace(pair<int,int>(sum,i));
            }
        }
        return max;
    }
};