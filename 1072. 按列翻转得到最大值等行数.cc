#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

class Solution {
public:
    pair<string,string> getByte(const vector<int>& vec )
    {
        string s1;
        string s2;
        for (int i : vec)
        {
            s1.push_back(i);
            s2.push_back(1-i);
        }
        return {s1,s2};
    }

    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string,int> mp;
        uint64_t reverseNum = 1;
        int result = 1;

        for (size_t i = 0; i < matrix[0].size(); i++)
        {
            reverseNum = reverseNum << 1; 
        }
        reverseNum = reverseNum -1;
        for (size_t i = 0; i < matrix.size(); i++)
        {
            pair<string,string> byt = getByte(matrix[i]);

            ++mp[byt.first];
            ++mp[byt.second];
            int max = mp[byt.first] > mp[byt.second] ? mp[byt.first] : mp[byt.second];
            result =  result> max ? result : max;

        }

        return result;
        
    }
};