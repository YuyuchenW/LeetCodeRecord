#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> result(queries.size(),false);
        int patternMap[26] = {0};
        for(char c: pattern)
        {
            if (c<=90)
            {
                ++patternMap[c-'A'];
            }
        }

        for (size_t i = 0; i < queries.size(); i++)
        {
            int queryMap[26] ={0};
            for(char qc : pattern)
            {
                if (qc<=90)
                {
                    ++queries[c-'A'];
                    
                }
                
            }
        }
        


    }
};