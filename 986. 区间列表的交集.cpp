#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> result;

        if (!(firstList.size() && secondList.size()))
        {
            return {};
        }
        int i = 0;
        int j = 0;
        while (i<firstList.size() && j <secondList.size())
        {
            int lo;
            int hi;
            lo = max(firstList[i][0],secondList[j][0]);
            hi = min(firstList[i][1],secondList[j][1]);

            if (lo<=hi)
            {
                result.push_back({lo,hi});
            }
            if (firstList[i][1]<secondList[j][1])
            {
                i++;
            }
            else{j++;}
        }
        return result;
        
    }
};