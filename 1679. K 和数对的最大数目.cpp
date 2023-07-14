#include <vector>
// 哈希表
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        unordered_map<int, int> ump;
        int res = 0;
        for (int &i : nums)
        {
            if (i >= k)
            {
                continue;
            }
            ++ump[i];
        }
        for (auto& i : ump)
        {
            if (i.second == 0)
            {
                continue;
            }
            const int target = k - i.first;
            auto f = ump.find(k);
            if (f == ump.end())
            {
                continue;
            }
            else
            {
                if (i.second > f->second)
                {
                    res += f->second;
                }
                else{
                    res += i.second;
                }
                f->second = 0;
            }
        }
        return res;
    }
};