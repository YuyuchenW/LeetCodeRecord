#include <functional>
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int perfectMenu(vector<int> &materials, vector<vector<int>> &cookbooks, vector<vector<int>> &attribute, int limit)
    {
        int res = -1;
        vector<int> req(materials.size(), 0);
        int h = 0;
        int d = 0;

        function<void(int)> dfs = [&](int index)
        {
            if (!checkMaterials(materials, req))
            {
                return;
            }
            if (h >= limit)
            {
                res = res > d ? res : d;
                std::cout << "res = " << res << std::endl;
            }

            for (size_t i = index; i < cookbooks.size(); i++)
            {

                for (size_t j = 0; j < materials.size(); ++j)
                {
                    req[j] += cookbooks[i][j];
                }
                h += attribute[i][1];
                d += attribute[i][0];
                std::cout << " add i = " << i << " cook "
                          << " d = " << d << endl;
                dfs(index + 1);
                for (size_t j = 0; j < materials.size(); ++j)
                {
                    req[j] -= cookbooks[i][j];
                }
                h -= attribute[i][1];
                d -= attribute[i][0];
            }
            return;
        };
        dfs(0);
        return res;
    }

    bool checkMaterials(vector<int> &materials, vector<int> &req)
    {
        for (size_t i = 0; i < materials.size(); i++)
        {
            if (materials[i] < req[i])
            {
                return false;
            }
        }

        return true;
    }
};