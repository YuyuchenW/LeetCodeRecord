#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        if (arr.size() == 1)
        {
            return true;
        }
        unordered_set<int> st;

        int left = 0;
        int right = 0;
        while (right < arr.size())
        {
            ++right;
            if (arr[left] != arr[right])
            {
                int dist = right - left;
                if (st.find(dist) == st.end())
                {
                    st.insert(dist);
                }
                else
                {
                    return false;
                }
            }
        }
        int lastDist = arr.size() - left;
        if (st.find(lastDist) != st.end())
            return false;
        return true;
    }
};