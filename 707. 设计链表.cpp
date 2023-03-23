class MyLinkedList
{

public:
    struct ListNode
    {
        int value;
        ListNode *next;
        ListNode(int x)
        {
            value = x;
            next = nullptr;
        }
        ListNode() : value(0), next(nullptr){};
        ListNode(int x, ListNode* node):value(x),next(node){};
    };
    // 初始化链表
    MyLinkedList()
    {
        m_size = 0;
        m_dummyHead = new ListNode(0);
    }

    // 获取第i个位置的值
    int get(int index)
    {
        if (index>= m_size|| index< 0)
        {
            return -1;
        }
        ListNode* res = m_dummyHead->next;
        while (index>0)
        {
            --index;
            res = res->next;
        }
        return res->value;
        
    }
    // 将一个值为 val 的节点插入到链表中第一个元素之前。在插入完成后，新节点会成为链表的第一个节点。
    void addAtHead(int val)
    {
        if (m_size == 0)
        {
            m_dummyHead->next = new ListNode(val);
            ++m_size;
            return;
        }
        ListNode* preHead = m_dummyHead->next;
        ++m_size;

        m_dummyHead->next  = new ListNode(val,preHead);
    }
    // 将一个值为 val 的节点追加到链表中作为链表的最后一个元素。
    void addAtTail(int val)
    {
        ListNode* cur = m_dummyHead;
        while (cur->next  != nullptr)
        {
            cur = cur->next;
        }
        ++m_size;
        cur->next = new ListNode(val);
    }
    // 将一个值为 val 的节点插入到链表中下标为 index 的节点之前。
    //如果 index 等于链表的长度，那么该节点会被追加到链表的末尾。如果 index 比长度更大，该节点将 不会插入 到链表中。
    void addAtIndex(int index, int val)
    {
        if (index == 0)
        {
            addAtHead(val);
            return;
        }
        if (index == m_size)
        {
            addAtTail(val);
            return;
        }
        if (index>m_size)
        {
            return;
        }
        ListNode* cur = m_dummyHead;
        while (index>0)
        {
            --index;
            cur = cur->next;
        }
        ++m_size;
        ListNode* temp = cur->next;
        cur->next = new ListNode(val,temp);

    }
    //  如果下标有效，则删除链表中下标为 index 的节点。
    void deleteAtIndex(int index)
    {
        if (index<0||index>=m_size)
        {
            return;
        }
        
        ListNode* cur = m_dummyHead;
        while (index>0)
        {
            cur = cur->next;
            --index;
        }
        ListNode* tem = cur->next;
        cur->next = cur->next->next;
        delete tem;
        --m_size; 

    }

private:
    int m_size;
    ListNode *m_dummyHead;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */