#include <vector>
#include <deque>
using namespace std;
class Solution
{
public:
    class myDeque
    {
    public:
        bool pop(int pnum)
        {
            if (pnum != m_deque.front())
            {
                return false;
            }
            else
            {
                m_deque.pop_front();
                return true;
            }
        };
        bool push(int num)
        {
            if (m_deque.empty())
            {
                m_deque.push_back(num);
                return true;
            }
            if (num > m_deque.front())
            {
                while (!m_deque.empty())
                {
                    m_deque.pop_back();
                }
                m_deque.push_back(num);
                return true;
            }
            else
            {
                while (m_deque.back()< num)
                {
                    m_deque.pop_back();
                }
                m_deque.push_back(num);
                return true;
            }
            return false;
        };
        int getMax()
        {
            return m_deque.front();
        };

    private:
        deque<int> m_deque;
    };

    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> result;
        myDeque mq;
        int left =0;
        int right = 0;
         for (size_t i = 0; i < k; i++)
         {
            mq.push(nums[right]);
            right++;
         }
         result.push_back(mq.getMax());
         while (right< nums.size()-1)
         {
            mq.pop(nums[left++]);
            mq.push(nums[++right]);
            result.push_back(mq.getMax());
         }
         return result;
         
    }
};