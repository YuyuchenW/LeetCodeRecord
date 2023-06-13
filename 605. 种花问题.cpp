#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        stack<int> st;
        if(n == 0) return true;
        if(n> (flowerbed.size()/2)+1) return false;
        if (flowerbed.size()<2)
        {
            return flowerbed[0] == 1? false:true;
        }
        st.push(flowerbed[0]);
        int num = 0;
        int count= flowerbed[0] == 0? 1:0;
        
        for (size_t i = 1; i < flowerbed.size()-1; ++i)
        {
            if (flowerbed[i]  == st.top()&& st.top() == 0)
            {
                ++count;
                if(count == 2)
                {
                    count =0;
                    ++num;
                }
            }else{
                    count =0;
            }

            st.push(flowerbed[i]);          
        }
        if(flowerbed[flowerbed.size()-1]==0 && st.top() == 0)
        {
            ++num;
        }


        return n<= num;
    }
}; 