#include <string>
using namespace std;
class Solution
{
public:
    string capitalizeTitle(string title)
    {
        if (title.size() == 1)
        {
            title[0] = title[0] >= 'a' ? title[0] : title[0] + 32;
            return title;
        }

        int low = 0;
        int fast = 0;

        while (fast < title.size())
        {
            if (title[fast] == ' ')
            {
                if (fast - low > 2)
                {
                    title[low] = title[low] >= 'a' ? title[low] : title[low] + 32;
                }
                ++fast;
                low = fast;
                continue;
            }

            if (title[fast] < 'a')
            {
                title[fast] = title[fast] + 32;
            }
            ++fast;
        }
        if (fast - low > 2)
        {
            title[low] = title[low] >= 'a' ? title[low] : title[low] + 32;
        }

        return title;
    }
};