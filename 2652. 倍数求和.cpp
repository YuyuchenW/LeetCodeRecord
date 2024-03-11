#include<stdint.h>

using namespace std;
class Solution {
public:
    int sumOfMultiples(int n) {
        
        int map[1001] = {0};
        int nums[3] = {3,5,7};
        int res = 0;
        int index = 0;
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < 3; j++)
            {
                index = nums[j] * i;
                if (index <= n)
                {
                    if (map[index] != 1)
                    {
                        res += index;
                        map[index] = 1;
                    }
                    
                }
                else
                {
                    if (j == 0)
                    {
                        break;
                    }
                    
                }
            }
        }
        return res;        
    }
};