#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        int left1 = num1.size() - 1;
        int left2 = num2.size() - 1;
        vector<char> charVec;
        bool addone = false;
        while (left1 != 0 && left2 != 0)
        {
            int sumNum = (num1[left1] - '0') + (num2[left2] - '0');
            if (addone)
            {
                ++sumNum;
            }

            charVec.push_back(sumNum % 10 + '0');

            if (sumNum >= 10)
            {
                addone = true;
            }
            else
            {
                addone = false;
            }
            --left1;
            --left2;
        }
        if (left1 != 0 && left2 == 0)
        {
            while (left1 != 0)
            {
                int sumNum = (num1[left1] - '0');
                if (addone)
                {
                    ++sumNum;
                }
                charVec.push_back(sumNum % 10 + '0');
                addone = false;
                --left1;
            }
        }
        else if (left1 == 0 && left2 != 0)
        {
            while (left2 != 0)
            {
                int sumNum = (num2[left2] - '0');
                if (addone)
                {
                    ++sumNum;
                }
                charVec.push_back(sumNum % 10 + '0');
                addone = false;
                --left2;
            }
        }
        else
        {
            if (addone)
            {
                charVec.push_back('1');
            }
        }
        string res;
        for(int l = charVec.size()-1; l>= 0; --l)
        {
            res.push_back(charVec[l]);
        }
        return res;
    }
};