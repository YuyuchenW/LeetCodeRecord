#include <stack>
using namespace std;
class MyQueue
{
public:
    MyQueue()
    {
    }

    void push(int x)
    {
        m_stacKIn.push(x);
    }

    int pop()
    {
        if (m_stackOut.empty())
        {
            while (!m_stacKIn.empty())
            {
                m_stackOut.push(m_stacKIn.top());
                m_stacKIn.pop();
            }
            int t = m_stackOut.top();
            m_stackOut.pop();
            return t;
        }
        int t = m_stackOut.top();
        m_stackOut.pop();
        return t;
    }

    int peek()
    {
        if (m_stackOut.empty())
        {
            while (!m_stacKIn.empty())
            {
                m_stackOut.push(m_stacKIn.top());
                m_stacKIn.pop();
            }
            int t = m_stackOut.top();
            return t;
        }
        int t = m_stackOut.top();
        return t;
    }

    bool empty()
    {
        return m_stacKIn.empty() == m_stackOut.empty() == true;
    }

private:
    stack<int> m_stacKIn;
    stack<int> m_stackOut;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */