#include <vector>
using namespace std;

class Solution
{
public:
    int isWinner(vector<int> &player1, vector<int> &player2)
    {
        int score1 = score(player1);
        int score2 = score(player2);
        if (score1 > score2)
        {
            return 1;
        }
        else if (score1 == score2)
        {
            return 0;
        }
        return 2;
    }

    int score(vector<int> &player)
    {
        int sum = 0;
        int doubleFlag = 0;
        for (int i = 0; i < player.size(); ++i)
        {
            if (doubleFlag == 0)
            {
                sum += player[i];
                --doubleFlag;
            }
            else
            {
                sum += player[i] * 2;
            }
            if (player[i] == 10)
            {
                doubleFlag = 2;
            }
        }
        return sum;
    }
};