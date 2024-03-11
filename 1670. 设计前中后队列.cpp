// void pushMiddle(int val) 将 val 添加到队列的 正中间 。
// void pushBack(int val) 将 val 添加到队里的 最后面 。
// int popFront() 将 最前面 的元素从队列中删除并返回值，如果删除之前队列为空，那么返回 -1 。
// int popMiddle() 将 正中间 的元素从队列中删除并返回值，如果删除之前队列为空，那么返回 -1 。
// int popBack() 将 最后面 的元素从队列中删除并返回值，如果删除之前队列为空，那么返回 -1 。

#include <deque>

class FrontMiddleBackQueue
{
public:
    // FrontMiddleBack() 初始化队列。
    FrontMiddleBackQueue()
    {
        if (m_deq.size() != 0)
        {
            m_deq.clear();
        }
        cnt = 0;

    }
    
    /**
     * @brief 将元素推入前端
     *
     * 将指定的元素推入容器的前端。
     *
     * @param val 要推入元素的数值
     */
    void pushFront(int val)
    {
        m_deq.push_front(val);
        cnt++;
    }

    void pushMiddle(int val)
    {
        
    }

    void pushBack(int val)
    {
    }

    int popFront()
    {
    }

    int popMiddle()
    {
    }

    int popBack()
    {
    }

private:
    std::deque<int> m_deq;
    int cnt = 0;
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */