#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(), prices.end());
        int n  =money -  prices[0] - prices[1];      
        return n >= 0 ? n : money; 
    }
};