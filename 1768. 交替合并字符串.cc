#include<string>

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
            if(word1.size() < word2.size())
            {
                mergeAlternately(word2,word1);
            }

            int size1 = word1.size();
            int size2 = word2.size();
            string res;
            int ptr = 0;
            for(char i : word1)
            {
                res.push_back(i);
                if (ptr< size2)
                {
                    res.push_back(word2[ptr++]);                    
                }
            }
            return res;
    }
};