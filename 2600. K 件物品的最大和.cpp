class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int count = k - numOnes - numZeros;
        if (count>0 )
        {
            return numOnes - count;
        }
        else if (count == 0 )
        {
            return numOnes;
        }
        else
        {
            if (-count > numOnes)
            {
                return numOnes;
            }
            else{
                return k;
            }
        }
    }
};  