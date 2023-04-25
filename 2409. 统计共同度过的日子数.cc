#include <string>

using namespace std;
class Solution
{
public:
    int monthArr[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int compairDate(const pair<int, int> &ar1, const pair<int, int> &ar2, pair<int, int> lea1, pair<int, int> lea2)
    {
        if (ar1.first > ar2.first)
        {
            compairDate(ar2, ar1, lea2, lea1);
        }
        if (ar1.first == ar2.second && ar1.second > ar2.second)
        {
            compairDate(ar2, ar1, lea2, lea1);
        }

        int result =0;
        if (ar2.first>lea1.first)
        {
            return 0;
        }
        else if(ar2.first == lea1.first)
        {
            if (ar2.second> lea1.second )
            {
                return 0;
            }
            if (ar1.second<ar2.second)
            {
                return lea1.second - ar2.second +1;
            }
            else{
                return 
            }
        }
        return 99;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob)
    {

        pair<int, int> AliceArrive = {stoi(arriveAlice.substr(0, 2)), stoi(arriveAlice.substr(3))};
        pair<int, int> AliceLeave = {stoi(leaveAlice.substr(0, 2)), stoi(leaveAlice.substr(3))};
        pair<int, int> BobLeave = {stoi(leaveBob.substr(0, 2)), stoi(leaveBob.substr(3))};
        pair<int, int> BobArrive = {stoi(arriveBob.substr(0, 2)), stoi(arriveBob.substr(3))};
        return  compairDate(AliceArrive,BobArrive,AliceLeave,BobLeave);
    }
};