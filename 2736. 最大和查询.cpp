#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution1
{
public:
    // 自定义哈希函数
    struct PairHash
    {
        template <typename T, typename U>
        std::size_t operator()(const std::pair<T, U> &p) const
        {
            auto hash1 = std::hash<T>{}(p.first);
            auto hash2 = std::hash<U>{}(p.second);
            return hash1 ^ hash2;
        }
    };

    // 自定义相等性比较函数
    struct PairEqual
    {
        template <typename T, typename U>
        bool operator()(const std::pair<T, U> &a, const std::pair<T, U> &b) const
        {
            return a.first == b.first && a.second == b.second;
        }
    };

    vector<int> maximumSumQueries(vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &queries)
    {
        multimap<int, int> map_1_value_index;
        vector<int> res;
        unordered_map<pair<int, int>, int, PairHash, PairEqual> visited;
        for (size_t i = 0; i < nums1.size(); i++)
        {
            map_1_value_index.emplace(pair<int, int>(nums1[i], nums2[i]));
        }

        for (size_t i = 0; i < queries.size(); i++)
        {
            auto v1 = visited.find(pair<int, int>(queries[i][0], queries[i][1]));
            if (v1 != visited.end())
            {
                res.push_back(v1->second);
                continue;
            }

            int max = -1;
            for (auto rit = map_1_value_index.rbegin(); rit != map_1_value_index.rend(); ++rit)
            {
                if (rit->first >= queries[i][0])
                {
                    if (map_1_value_index.count(rit->first) > 1)
                    {
                        auto range = map_1_value_index.equal_range(rit->first);
                        for (auto it = range.first; it != range.second; ++it)
                        {
                            if (it->second >= queries[i][1])
                            {
                                max = max > (rit->first + it->second) ? max : (rit->first + it->second);
                            }
                        }
                    }
                    else
                    {
                        if (rit->second >= queries[i][1])
                        {
                            max = max > (rit->first + rit->second) ? max : (rit->first + rit->second);
                        }
                    }
                }
                else
                {
                    break;
                }
            }
            visited[pair<int, int>(queries[i][0], queries[i][1])] = max;
            visited[pair<int, int>(queries[i][1], queries[i][0])] = max;
            res.push_back(max);
        }

        return res;
    }
};

class Solution
{
public:
    vector<int> maximumSumQueries(vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &queries)
    {
        vector<pair<int, int>> num_vec(nums1.size());
        for (size_t i = 0; i < nums1.size(); i++)
        {
            num_vec[i] = pair<int, int>(nums1[i], nums2[i]);
        }
        sort(num_vec.begin(), num_vec.end(), [](const pair<int, int> &a, const pair<int, int> &b)
             { return a.first > b.first; });
        vector<int> qid(queries.size());
        iota(qid.begin(), qid.end(), 0);
         sort(qid.begin(), qid.end(),
             [&](int i, int j) { return queries[i][0] > queries[j][0]; });

        int j = 0;
        vector<int> ans(queries.size());
        vector<pair<int, int>> st;
        for (int i : qid)
        {
            int x = queries[i][0], y = queries[i][1];

            for (; j < num_vec.size() && x <= num_vec[j].first; ++j)
            {
                while (!st.empty() && st.back().second <= num_vec[j].first + num_vec[j].first)
                {
                    st.pop_back();
                }

                if (st.empty() || st.back().first < num_vec[j].second)
                {
                    st.emplace_back(num_vec[j].second, num_vec[j].first + num_vec[j].second);
                }
            }
            auto it = lower_bound(st.begin(), st.end(), y, [](const pair<int, int> &p, int val)
                                  { return p.first < val; });
            ans[i] = it != st.end() ? it->second : -1;
        }
        return ans;
    }
};