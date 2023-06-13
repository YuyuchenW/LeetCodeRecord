#include<vector>

using namespace std;

class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        if(arr1.size() < arr2.size())
        {
            addNegabinary(arr2,arr1);
        }
        int n = arr1.size() - 1;
        int m = arr2.size() - 1;
        vector<int> res(n,0);
        while (m>=0)
        {
            int temp = arr1[n] + arr2[m];
            if(temp >= 2)
            {
                temp = temp -2;
                res[n] = temp;
                --arr1[n-1];
            }
            if(temp<0)
            {
                res[n] = 0;
                ++arr1[n-1];
            }
            else{
                res[n] = temp;
            }
            --n;
            --m;
        }
        while (n>=0)
        {
            
        }
        
        
    }
};