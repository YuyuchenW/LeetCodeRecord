#include<stdint.h>
class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = x;
        long long target = x;
        long long mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (mid * mid == target) {
                return mid;
            } else if (mid * mid > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }
};