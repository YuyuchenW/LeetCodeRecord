#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution
{
public:
    vector<string> sortPeople(vector<string> &names, vector<int> &heights)
    {
        vector<string> res;
        map<int, string> peopleMap;
        for (size_t i = 0; i < heights.size(); i++)
        {
            peopleMap[heights[i]] = names[i];
        }
        for(auto i = -- peopleMap.end() ; i != peopleMap.begin(); --i)
        {
            res.push_back(i->second);
        }
        res.push_back(peopleMap.begin()->second);
        return res;
    }
};