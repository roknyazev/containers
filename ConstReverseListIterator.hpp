//
// Created by Wolmer Rudy on 6/16/21.
//

#ifndef CONTAINERS_CONSTREVERSELISTITERATOR_HPP
#define CONTAINERS_CONSTREVERSELISTITERATOR_HPP
#include "Node.hpp"

namespace ft
{
	/*
	 * Const reverse iterator
	 */
	template <class T>
	class ConstReverseListIterator
	{
	public:
		typedef T value_type;
		typedef T& reference;
		typedef Node<T>* pointer;
	protected:
		pointer ptr;
	public:
		ConstReverseListIterator()
		{};
		ConstReverseListIterator(const ConstReverseListIterator &other)
		{
			*this = other;
		};
		ConstReverseListIterator(pointer ptr)
		{
			this->ptr = ptr;
		};
		~ConstReverseListIterator()
		{};
		ConstReverseListIterator &operator++()
		{
			this->ptr = this->ptr->prev;
			return (*this);
		};
		ConstReverseListIterator &operator--()
		{
			this->ptr = this->ptr->next;
			return (*this);
		};
		ConstReverseListIterator operator++(int)
		{
			ConstReverseListIterator tmp(*this);
			operator++();
			return (tmp);
		};
		ConstReverseListIterator operator--(int)
		{
			ConstReverseListIterator tmp(*this);
			operator--();
			return (tmp);
		};
		bool operator==(const ConstReverseListIterator &other) const
		{
			return (ptr == other.ptr);
		};
		bool operator!=(const ConstReverseListIterator &other) const
		{
			return (ptr != other.ptr);
		};
		bool operator>(const ConstReverseListIterator &other) const
		{
			return (ptr > other.ptr);
		};
		bool operator>=(const ConstReverseListIterator &other) const
		{
			return (ptr >= other.ptr);
		};
		bool operator<(const ConstReverseListIterator &other) const
		{
			return (ptr < other.ptr);
		};
		bool operator<=(const ConstReverseListIterator &other) const
		{
			return (ptr <= other.ptr);
		};
		value_type &operator*()
		{
			return (ptr->data);
		};
		value_type *operator->()
		{
			return (ptr->data);
		};
		ConstReverseListIterator operator+(int n) const
		{
			ConstReverseListIterator tmp(*this);
			tmp += n;
			return (tmp);
		};
		ConstReverseListIterator operator-(int n) const
		{
			ConstReverseListIterator tmp(*this);
			tmp -= n;
			return (tmp);
		};
		ConstReverseListIterator &operator+=(int n)
		{
			while (n < 0)
			{
				(*this)--;
				n++;
			}
			while (n > 0)
			{
				(*this)++;
				n--;
			}
			return (*this);
		};
		ConstReverseListIterator &operator-=(int n)
		{
			while (n > 0)
			{
				operator--();
				n--;
			}
			while (n < 0)
			{
				operator++();
				n++;
			}
			return (*this);
		};
	};
}

#endif //CONTAINERS_CONSTREVERSELISTITERATOR_HPP
