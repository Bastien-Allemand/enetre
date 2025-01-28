#include "Node.hpp"

template <typename T>
class iterator
{
	Node<T>* m_node;
public:
	iterator(const Node<T> _m_node);
	Node<T> GetNode();
	void SetNode(Node<T> _node);
	iterator operator++();
	iterator operator+(int _n);
	iterator operator--();
	iterator operator-(int _n);
	iterator operator*();
};


template <typename T>
iterator<T>::iterator(const Node<T> _m_node) :m_node(_m_node) {}

template<typename T>
inline Node<T> iterator<T>::GetNode()
{
	return m_node;
}

template<typename T>
inline void iterator<T>::SetNode(Node<T> _node)
{
	m_node = _node;
}

template<typename T>
iterator<T> iterator<T>::operator++()
{
	return m_value = m_value->m_next;
}
template<typename T>
iterator<T> iterator<T>::operator+(int _n)
{
	for (int i = 0; i < _n; i++)
	{
		m_value = m_value->m_next;
	}
	return m_value;
}

template<typename T>
iterator<T> iterator<T>::operator--()
{
	return m_value = m_value->m_previous;
}

template<typename T>
iterator<T> iterator<T>::operator-(int _n)
{
	for (int i = 0; i < _n; i++)
	{
		m_value = m_value->m_previous;
	}
	return m_value;
}

template<typename T>
iterator<T> iterator<T>::operator*()
{
	return m_node->m_value;
}

