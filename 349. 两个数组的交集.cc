#include<unordered_set>
#include<vector>
using namespace std;


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st;
        unordered_set<int> st1;

        vector<int> res;
        for(int val : nums1)
        {
            st.insert(val);
        }
        for(int val : nums2)
        {
            if (st.count(val)&& !st1.count(val))
            {
                st1.insert(val);
                res.push_back(val);
            }
        }
        return res;

    }   
};