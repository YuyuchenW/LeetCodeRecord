#include<string>
using namespace std;
class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        const int judge_4 = 10000;
        const int judge_v = 1000000000;
        long long v = static_cast<long>(length) * static_cast<long>(width) * static_cast<long>(height);
        string type[4] = {"Neither","Bulky","Heavy","Both"};
        int res = 0;
        if (length >= judge_4||width >=judge_4 || height >= judge_4 || v  >= judge_v )
        {
            res += 1;
        }
        if (mass>= 100)
        {
            res += 2;
        }
        return type[res];
    }
};