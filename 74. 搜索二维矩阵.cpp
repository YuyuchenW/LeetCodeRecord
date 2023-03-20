#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int searchRow(vector<vector<int>> &matrix, int target)
    {
        int left = 0;
        int right = matrix.size() - 2;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (matrix[mid][0] <= target && matrix[mid + 1][0] > target)
            {
                return mid;
            }
            if (matrix[mid][0] > target)
            {

                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return matrix.size() - 1;
    }
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int k = searchRow(matrix, target);
        int left = 0;
        int right = matrix[0].size() - 1;
        int middle = 0;
        while (left <= right)
        {
            middle = (left + right) / 2;
            if (matrix[k][middle] == target)
            {
                return true;
            }
            else if (matrix[k][middle] > target)
            {
                right = middle - 1;
            }
            else
            {
                left = middle + 1;
            }
        }
        return false;
    }
};