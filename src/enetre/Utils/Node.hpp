

template <typename T>
struct Node
{
	T m_value;
	Node* m_next;
	Node* m_previous;
	Node(T value, Node<T>* prev = nullptr, Node<T>* next = nullptr);
};

template<typename T>
Node<T>::Node(T value, Node<T>* prev, Node<T>* next)
{
	m_value = value;
	m_next = next;
	m_previous = prev;
}