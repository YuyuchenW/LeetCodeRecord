
#include<deque>
using namespace std;

class RecentCounter {
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        pingDq.push_back(t);
        while (pingDq.front()+3000 < t)
        {
            pingDq.pop_front();
        }
        
        return pingDq.size();
    }
private:
    deque<int> pingDq;

};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */