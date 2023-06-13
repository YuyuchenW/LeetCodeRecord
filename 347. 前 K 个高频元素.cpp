#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
class Solution
{
public:
    class compairFun
    {
    public:
        bool operator()(const pair<int, int> &p1, const pair<int, int> &p2)
        {
            return p1.second > p2.second;
        }
    };
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        for (int i : nums)
        {
            mp[i]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, compairFun> pr_queue;
        for(auto i = mp.begin(); i != mp.end(); ++i)
        {
            pr_queue.push(*i);
            if(pr_queue.size()>k)
            {
                pr_queue.pop();
            }
        }
        vector<int> result(k);
        for (int i = k-1; i >=0; i--)
        {
            result[i] = pr_queue.top().first;
            pr_queue.pop();
        }
        return result;
    }
};