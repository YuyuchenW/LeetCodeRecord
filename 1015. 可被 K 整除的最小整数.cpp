class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k%2 == 0)
        {
            return -1;
        }
        int num = k%10;
        if(num  == 5)
        {
            return -1;
        }
    }
};