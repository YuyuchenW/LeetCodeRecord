#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        sort(barcodes.begin(),barcodes.end());
        vector<int> res;
        int left = 0;
        int right = barcodes.size()-1;

        while (left < right)
        {
            res.push_back(barcodes[left]);
            res.push_back(barcodes[right]);
            ++left;
            --right;
        }

        if(left == right)
        {
            res.push_back(barcodes[left]);
        }
        return res;      
    }
};