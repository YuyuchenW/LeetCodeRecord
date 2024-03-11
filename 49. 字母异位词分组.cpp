#include<unordered_map>
#include<vector>
#include<string>
using namespace std;
// 输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
// 输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int index  =0;
        unordered_map<string, int> umap;
        vector<vector<string>> res;
        for(string& i : strs)
        {
            int map[26] = {0};
            for(char& j : i)
            {
                map[j - 'a']++;
            }
            string key = "";
            for(int i = 0;i <26 ; ++i)
            {
                key += "|";
                key += to_string(map[i]);
            }
            auto it = umap.find(key);
            if(it == umap.end())
            {
                umap[key] = index++;
                vector<string> temp;
                temp.push_back(i);
                res.push_back(temp);
            }
            else{
                res[it->second].push_back(i);
            }
        }
        return res;
    }
};