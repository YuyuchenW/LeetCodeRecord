#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nozeroPtr = 0;
        int ptr = 0;
        while(ptr <nums.size())
        {
            if (nums[ptr]!= 0)
            {
                nums[nozeroPtr] = nums[ptr];
                nozeroPtr++;
            }
            ++ptr;
        }

        while (nozeroPtr < nums.size())
        {
            nums[nozeroPtr] = 0;
            ++nozeroPtr;
        }
    }
};