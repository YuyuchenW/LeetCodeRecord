#include <vector>
using namespace std;

class Solution
{
public:
    bool validMountainArray(vector<int> &arr)
    {
        int left = 0;
        int right = arr.size() - 1;
        if (right <= 1)
        {
            return false;
        }

        for (size_t i = 0; i < arr.size(); i++)
        {
            if (left == right)
            {
                break;
            }
            if (arr[left] < arr[left + 1])
            {
                ++left;
            }
            if (arr[right] < arr[right - 1])
            {
                --right;
            }
        }
        if (left == right && left != 0 && right != arr.size() - 1)
            return true;
        return false;
    }
};