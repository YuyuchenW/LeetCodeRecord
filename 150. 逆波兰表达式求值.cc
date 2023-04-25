#include <vector>
#include <string>
#include <stack>
using namespace std;
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> numSt;
        for (string s : tokens)
        {
            if (isdigit(s[0]))
            {
                int num = stoi(s);
                numSt.push(num);
            }
            else
            {
                if (s[0] == 43)
                {
                    int num1 = numSt.top();
                    numSt.pop();
                    int num2 = numSt.top();
                    numSt.pop();
                    num1 = num1 + num2;
                    numSt.push(num1);
                }
                else if (s[0] == 45)
                {
                    int num1 = numSt.top();
                    numSt.pop();
                    int num2 = numSt.top();
                    numSt.pop();
                    num1 = num2 - num1;
                    numSt.push(num1);
                }
                else if (s[0] == 42)
                {
                    int num1 = numSt.top();
                    numSt.pop();
                    int num2 = numSt.top();
                    numSt.pop();
                    num1 = num2 * num1;
                    numSt.push(num1);
                }
                else
                {
                    
                    int num1 = numSt.top();
                    numSt.pop();
                    int num2 = numSt.top();
                    numSt.pop();
                    num1 = num2 / num1;
                    numSt.push(num1);
                }
            }
        }
        return numSt.top();
    }
};