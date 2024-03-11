#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool validPartition(vector<int> &nums)
    {
        int fast = 0, slow = 0;
        int type = 0; // 0 unkown 1 same 2 diff
        int preCount = 0;
        bool c = false;
        while (fast < nums.size())
        {
            if (nums[fast] == nums[slow])
            {
                if (type == 1)
                {
                    ++fast;
                    continue;
                }
                if (type == 0)
                {
                    type = 1;
                    slow = fast;
                    ++fast;
                    continue;
                }
                if (type == 2)
                {
                    if ((fast - slow + 1) % 3 != 1)
                    {
                        return false;
                    }
                    slow = fast;
                    ++fast;
                    type = 1;
                }
                c = true;
            }

            if (nums[fast] == nums[slow] + 1)
            {
                if (type == 2)
                {
                    ++fast;
                    continue;
                }
                if (type == 0)
                {
                    type = 2;
                    slow = fast;
                    ++fast;
                    continue;
                }
                if (type == 1)
                {
                    type = 2;
                    preCount = fast - slow;
                    slow = fast;
                    ++fast;
                    continue;
                }
                c = false;
            }

            if (type == 0)
            {
                return false;
            }

            if (type == 1)
            {
                preCount = fast - slow + 1;
            }

            if (type == 2)
            {
                int cnt = fast - slow + 1;
                if (cnt % 3 != 0)
                {
                    if (!c)
                    {
                        return false;
                    }
                    if ((preCount - cnt % 3) < 2)
                    {
                        return false;
                    }
                }
                preCount = fast - slow + 1;
            }
            type = 0;
            ++fast;
        }
        int cnt = fast - slow + 1;
        if (cnt % 3 != 0)
        {
            if (!c)
            {
                return false;
            }
            if ((preCount - cnt % 3) < 2)
            {
                return false;
            }
        }
        return true;
    }
};