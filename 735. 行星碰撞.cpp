#include <vector>
#include <stack>
#include <cmath>
using namespace std;

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        vector<int> st;
        for (size_t i = 0; i < asteroids.size(); i++)
        {
            if(st.empty())
            {
                st.push_back(asteroids[i]);
                continue;
            }
            int mul = st.back() * asteroids[i];
            if (mul> 0)
            {
                st.push_back(asteroids[i]);
            }
            else
            {
                if(st.back()<0)
                {
                    st.push_back(asteroids[i]);
                }
                else if (abs(st.back()) > abs(asteroids[i]))
                {
                    continue;                  
                }
                else if (abs(st.back()) == abs(asteroids[i]))
                {
                    st.pop_back();
                }
                else if(abs(st.back()) < abs(asteroids[i]))
                {
                    st.pop_back();
                    --i;
                }
            }
        }

        return st;
    }
};