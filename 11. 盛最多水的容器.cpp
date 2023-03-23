#include<vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() ==2)
        {
            return height[0]>height[1]? height[1]: height[0];
        }
        
        int left = 0;
        int right = height.size()-1;
        int result = 0;
        while (left < right)
        {
            result  =  max(result, (right-left)* (min(height[left],height[right])));

            if (height[left]>height[right])
            {
                --right;
            }
            else{
                ++left;
            }
        }
        return result;
    }
};