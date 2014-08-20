// queuetp.h -- QueueTp template header
#ifndef QUEUETP_H_
#define QUEUETP_H_

template <typename T>
class QueueTp
{
    private:
        enum { QSIZE = 10 };

        struct Node {
            T data;
            struct Node * next;
        };

        Node * head;
        Node * tail;
        int items;
        const int qsize;

    public:
        QueueTp(int qs = QSIZE)
            : qsize(qs), items(0), head(nullptr), tail(nullptr) {}
        ~Queue() {}
        bool isempty() const;
        bool isfull() const;
        int count() const;
        bool enqueue(const T & t);
        bool dequeue(T & t);
}

template <typename T>
bool QueueTp<T>::isempty() const
{
    return items == 0;
}

template <typename T>
bool QueueTp<T>::isfull() const
{
    return items == qsize;
}

template <typename T>
int QueueTp<T>::count() const
{
    return items;
}

template <typename T>
bool enqueue(const T & t)
{
    if (isfull())
        return false;

    Node * add = new Node;
    add->data = t;
    add->next = nullptr;
    items++;

    if (first)
        first = add;
    else
        tail->next = add;

    tail = add;
    return true;
}

template <typename T>
bool dequeue(T & data)
{
    if (isempty())
        return false;

    data = head->data;
    items--;
    Node * temp = head;
    head = head->next;

    delete temp;

    if (isempty()) {
        tail = nullptr;
    }

    return true;
}

#endif
