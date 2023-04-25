#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// class Solution
// {
// public:
//     string reverseWords(string s)
//     {
//         vector<string> strVec;
//         string stringVar = "";
//         for(char c : s)
//         {
//             if (c == ' ')
//             {
//                 if (stringVar.size() == 0)
//                 {
//                 }
//                 else{
//                     strVec.push_back(stringVar);
//                     stringVar.clear();
//                 }
//             }
//             else
//             {
//                 stringVar.push_back(c);
//             }
//         }
//         if(!stringVar.empty())
//         {
//             strVec.push_back(stringVar);
//         }
//         string result= "";
//         for(size_t i = strVec.size()-1;i>0;--i)
//         {

//             result.append(strVec[i]);
//             result.push_back(' ');
//         }
//         result.append(strVec[0]);
//         return result;
//     }
// };

class Solution
{
public:
    void reverseStr(string &s, int start, int end)
    {
        for (int i = start, j = end; i < j; ++i, --j)
        {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
    }

    void removeSpace(string &s)
    {
        int slow = 0;
        for (size_t i = 0; i < s.size(); i++)
        {
            if (s[i] != ' ')
            {
                 if (slow!= 0)
                 {
                    s[slow++] = ' ';
                 }
                 while (i<s.size()&& s[i]!=' ')
                 {
                    s[slow++] = s[i];
                    ++i;
                 }
            }
        }

        s.resize(slow);
    }
    string reverseWords(string s)
    {
        removeSpace(s);
        reverseStr(s,0,s.size()-1);
        int left =0;
        int right = 0;
        while (right<= s.size())
        {
            if(right == s.size())
            {
                reverseStr(s,left,right-1);
                break;
            }
            if (s[right]!= ' ')
            {
                ++right;
            }
            else{
                reverseStr(s,left,right-1);
                left = ++right;
            }
        }
        return s;
    }
};