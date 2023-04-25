#include<unordered_set>
using namespace std;

class Solution {
public:
    unordered_set<int> st;
    bool isHappy(int n) {
        if (st.count(n))
        {
            return false;
        }
        if (n == 1 )
        {
            return true;
        }
        st.insert(n);
        int sum = 0;
        int e = 1;
        while (n)
        {
            sum += n%10;
            n = n/10;
        }
        return isHappy(sum);
    }
};