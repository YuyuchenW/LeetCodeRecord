#include<string>
#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;

class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        unordered_map<char,int> mp;
        for (size_t i = 0; i < s.size(); i++)
        {
            auto item = mp.find(s[i]);
            if (item!= mp.end())
            {
                if(distance[s[i]-'a'] != i - item->second-1)
                return false;
            }
            else
            {
                mp.insert({s[i],i});
            }
        }
        return true;
        
    }
};