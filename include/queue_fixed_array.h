#include <stdexcept>

template<typename T, size_t Size>
class Queue
{
    public:
    Queue() : m_head(0),m_tail(0) {};

    void enqueue(const T& data)
    {
        if(!isFull())
        {
            m_head++;
            m_head = m_head%Size;

            m_data[m_head] = data;
        }
    }

    bool isFull() const
    {
        return (m_head==0 and m_tail==Size) | (m_tail==0 && m_head==Size);
    }

    private:
    int m_head;
    int m_tail;
    T[Size] m_data;
}