#include <stdexcept>
#include <cstring>

template<typename T, size_t Size>
class Stack
{
    public:
    Stack(size_t initialSize = 10) : m_curPos(0), m_size(initialSize) {
        m_data = new T[Size];
    };
    ~Stack(){
        delete[] m_data;
    }

    bool isEmpty() const {
        return m_curPos == 0;
    }
    

    void pop(){
        if(!isEmpty())
        {
            --m_curPos;
        }
    }

    void push(const T& data)
    {
        if(m_curPos == m_size)
        {
            T* newArr = new T[m_size*2];
            std::memcpy(newArr, m_data, sizeof(*m_data));

            m_size *=2;
            delete[] m_data
            m_data = newArr;
        }
        else{
        ++m_curPos;
        m_data[m_curPos] = (data);
        }
    }


    const T& peek() const {
        return m_data[m_curPos]
    }
    T& peek() const {
        return m_data[m_curPos]
    }

    private:
    int m_size;
    int m_curPos;
    T* m_data;
    
}