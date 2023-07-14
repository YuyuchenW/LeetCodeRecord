#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        if (word1.size() != word2.size())
        {
            return false;
        }

        unordered_map<int, int> mp_i1;
        unordered_map<int, int> mp_i2;
        unordered_map<char, int> mp2;
        unordered_map<char, int> mp3;

        for (size_t i = 0; i < word1.size(); i++)
        {

            ++mp2[word1[i]];
            ++mp3[word2[i]];
        }
        for (auto i : mp2)
        {
            auto k = mp3.find(i.first);
            if (k == mp3.end())
            {
                return false;
            }
            ++mp_i1[i.second];
            ++mp_i2[k->second];
        }
        if (mp_i1.size() != mp_i2.size())
        {
            return false;
        }
        
        for (auto i : mp_i1)
        {
            auto k = mp_i2.find(i.first);
            if (k == mp_i2.end() || k->second != i.second)
            {
                return false;
            }
        }
        return true;
    }
};