#include<vector>
using namespace std;

// x+y = k
// 4x+2y = h
// y = k -x 
// 4x + (2k-2x) = h
// 2x = h- 2k
// x = h/2-k
//
class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        if (tomatoSlices%2 != 0)
        {
            return {};
        }
        int x = (tomatoSlices >> 1) - cheeseSlices;
        if (x < 0)
        {
            return {};
        }
        vector<int> res{2,0};        
        res[0] = (tomatoSlices >>1) - cheeseSlices;
        res[1] = cheeseSlices - res[0];
        return res;
    }
};