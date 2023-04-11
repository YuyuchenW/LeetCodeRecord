#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> sortArrayByParityII(vector<int> &nums)
    {
        int evPtr = 0;
        int odPtr = 1;

        while (evPtr < nums.size() && odPtr < nums.size())
        {
            if (nums[evPtr]%2 !=0 &&(nums[odPtr] + 1) % 2 != 0)
            {
                int t = nums[evPtr];
                nums[evPtr] = nums[odPtr];
                nums[odPtr] = t;
                ++ ++evPtr;
                ++ ++odPtr;
                continue;
            }
            if (nums[evPtr] % 2 == 0)
            {
                ++ ++evPtr;
            }
            if ((nums[odPtr] + 1) % 2 == 0)
            {
                ++ ++odPtr;
            }
        }
        return nums;
    }
};