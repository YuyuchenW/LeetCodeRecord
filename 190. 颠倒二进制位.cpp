#include"stdint.h"
#include<iostream>
class Solution {
public:
    uint32_t result =0;
    int cnt=32;
    uint32_t reverseBits(uint32_t n) {
        if (n==0)
        {
            std::cout<<cnt;
            while (cnt)
            {
                result = result<<1;
                --cnt;
            }
            
           return result;
        }
        if (n&1)
        {
            ++result;
            result = result<<1;
            reverseBits(n>>1);
            --cnt;
        }
        else{
            result = result<<1;
            reverseBits(n>>1);
            --cnt;
        }
        return result;
    }
};