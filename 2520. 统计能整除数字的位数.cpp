#include<vector>
using namespace std;

class Solution {
public:
    int countDigits(int num) {
        vector<int>  vec;
        int res = 0;
        int size = 0;
        int tem = num;

        while (tem)
        {
            vec.push_back(tem%10);
            tem /= 10;
        }
        for (int& n : vec)
        {
            if (!(res%n))
            {
                ++res;
            }
        }
        return res;        
    }
};