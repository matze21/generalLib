#include <stdexcept>

class Stack
{
	public:
  Stack() : m_top(nullptr) {};
  ~Stack() {
    while(m_top){
      Node* next = m_top->next;
      delete m_top;
      m_top = next;
    }
  }
  
  bool isEmpty()
  {
    return m_top == nullptr
  }
  
  void push(int data)
  {
    Node* newN = new Node(data) 
    newN->next = m_top;
    m_top = newN;
  }
  
  void pop()
  {
    if (!empty())
    {
    	Node* out = m_top;
    	m_top = m_top->next;
      delete out;
    }
    else
    {
      std::runtime_error('exception, is empty');
    }
  }
  
  Node* peek()
  {
    if(!empty())
    {
      return m_top;
    }
    else
    {
      std::runtime_error('exception, is empty');
    }
  }
  
	private:
  
  struct Node
	{
  	int data;
  	Node* next;
    
    Node(int d) : data(d),next(nullptr) {};
	}
  Node* m_top;
}