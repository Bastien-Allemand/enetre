#include "iostream"
#include "iterator.hpp"

template <typename T>
class Vector
{
	iterator<T>* m_list;
	iterator<T> m_begin;
	iterator<T> m_end;
public:
	void push_back(T node);
	iterator<T> begin();
	iterator<T> size();
	T operator[](int _index);
	Vector();
};

template<typename T>
Vector<T>::Vector() : m_begin(nullptr), m_end(nullptr)
{
	std::cout << "Vector created" << std::endl;
}

template<typename T>
void Vector<T>::push_back(T node)
{
	if (m_begin == nullptr)
	{
		m_begin = m_end;
		m_end = new iterator<T>(node);
		m_begin.GetNode()->m_previous = nullptr;
		m_end.GetNode()->m_previous = m_begin;
	}
	else
	{
		m_begin = m_end;
		m_end = new iterator<T>(node, m_end);
		m_begin.GetNode()->m_next = m_end;
		m_end.GetNode()->m_previous = m_begin;
	}

}

template<typename T>
inline iterator<T> Vector<T>::begin()
{
	return m_begin;
}

template<typename T>
inline iterator<T> Vector<T>::size()
{
	return m_end;
}

template<typename T>
T Vector<T>::operator[](int _index)
{
	return *(m_begin + _index);
}


