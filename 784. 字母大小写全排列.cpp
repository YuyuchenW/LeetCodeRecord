#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<string> result;
    string path = "";
    void trackingBack(const string& s, int n,int index)
    {
        if (path.size() == n)
        {
            result.push_back(path);
            return;
        }
        for(int i = index;i < n;++i){
            if (isdigit(s[i]))
            {
                path+=s[i];
                continue;
            }
            path+= s[i];
            trackingBack(s,n,i+1);
            path.pop_back();
            break;
        }
    }
    vector<string> letterCasePermutation(string s) {
        trackingBack(s,s.size(),0);      
        return result;
    }
};