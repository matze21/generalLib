#include <stdexcept>

template<typename T, size_t Size>
class Stack
{
    public:
    Stack() : m_curPos(0) {};

    bool isEmpty() const {
        return m_curPos == 0;
    }
    

    void pop(){
        if(!isEmpty())
        {
            --m_curPos;
        }
    }

    void push(T&& data)
    {
        if(m_curPos == Size)
        {
            std::runtime_error('arr full, resizing?');
        }
        else{
        ++m_curPos;
        m_data[m_curPos] = std::move(data);
        }
    }

    void push(const T& data)
    {
        if(m_curPos == Size)
        {
            std::runtime_error('arr full, resizing?');
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
    int m_defaultSize;
    int m_curPos;
    T m_data[Size];
    
}