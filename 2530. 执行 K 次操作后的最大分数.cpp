#include <vector>
#include <set>
using namespace std;
class Solution
{
public:
    long long maxKelements(vector<int> &nums, int k)
    {
        long long res = 0ll;
        multiset<int> st;
        for (size_t i = 0; i < nums.size(); i++)
        {
            st.emplace(nums[i]);
        }

        for (size_t i = 0; i < k; i++)
        {
            auto it = --st.end();
            int num = *it;
            res += num;
            if (num > 0)
            {
                num = (num + 2) / 3;
            }
            else
            {
                num = num / 3;
            }
            st.erase(it);
            st.emplace(num);
        }
        return res;
    }
};