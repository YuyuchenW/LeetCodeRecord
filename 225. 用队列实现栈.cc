#include <queue>
using namespace std;

class MyStack
{
public:
    MyStack()
    {
        m_queueInSize = 0;
    }

    void push(int x)
    {
        m_queueIn.push(x);
        ++m_queueInSize;
    }

    int pop()
    {
        int tem = m_queueInSize;
        while (tem != 1)
        {
            m_queueOut.push(m_queueIn.front());
            m_queueIn.pop();
            --tem;
        }
        int result = m_queueIn.front();
        m_queueIn.pop();
        --m_queueInSize;
        while (!m_queueOut.empty())
        {
            m_queueIn.push(m_queueOut.front());
            m_queueOut.pop();
        }
        return result;
    }

    int top()
    {
        int tem = m_queueInSize;
        while (tem != 1)
        {
            m_queueOut.push(m_queueIn.front());
            m_queueIn.pop();
            --tem;
        }
        int result = m_queueIn.front();
        m_queueOut.push(m_queueIn.front());
        m_queueIn.pop();
        while (!m_queueOut.empty())
        {
            m_queueIn.push(m_queueOut.front());
            m_queueOut.pop();
        }

        return result;
    }

    bool empty()
    {
        return m_queueInSize == 0;
    }

private:
    queue<int> m_queueIn;
    queue<int> m_queueOut;
    int m_queueInSize;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */