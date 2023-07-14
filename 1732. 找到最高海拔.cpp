#include<vector>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int res = 0;
        int sum = 0;
        for (size_t i = 0; i < gain.size();++i)
        {
            sum+= gain[i];
            res = res>sum ? res : sum;
        }
        return res;
    }
};