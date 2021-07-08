//
// Created by Wolmer Rudy on 6/16/21.
//

#ifndef CONTAINERS_CONSTLISTITERATOR_HPP
#define CONTAINERS_CONSTLISTITERATOR_HPP
#include "Node.hpp"

namespace ft
{
	/*
	 * Const iterator
	 */
	template <class T>
	class ConstListIterator
	{
	public:
		typedef T value_type;
		typedef T& reference;
		typedef Node<T>* pointer;
	protected:
		pointer ptr;
	public:
		ConstListIterator()
		{};
		ConstListIterator(const ConstListIterator &other)
		{
			*this = other;
		};
		ConstListIterator(pointer ptr)
				: ptr(ptr)
		{};
		~ConstListIterator()
		{};
		pointer node(void) const
		{
			return (ptr);
		};
		ConstListIterator &operator=(const ConstListIterator &other)
		{
			ptr = other.ptr;
			return (*this);
		};
		ConstListIterator &operator++()
		{
			ptr = ptr->next;
			return (*this);
		};
		ConstListIterator &operator--()
		{
			ptr = ptr->prev;
			return (*this);
		};
		ConstListIterator operator++(int)
		{
			ConstListIterator tmp(*this);
			operator++();
			return (tmp);
		};
		ConstListIterator operator--(int)
		{
			ConstListIterator tmp(*this);
			operator--();
			return (tmp);
		};
		bool operator==(const ConstListIterator &other) const
		{
			return (ptr == other.ptr);
		};
		bool operator!=(const ConstListIterator &other) const
		{
			return (ptr != other.ptr);
		};
		bool operator>(const ConstListIterator &other) const
		{
			return (ptr > other.ptr);
		};
		bool operator>=(const ConstListIterator &other) const
		{
			return (ptr >= other.ptr);
		};
		bool operator<(const ConstListIterator &other) const
		{
			return (ptr < other.ptr);
		};
		bool operator<=(const ConstListIterator &other) const
		{
			return (ptr <= other.ptr);
		};
		const value_type &operator*()
		{
			return (ptr->data);
		};
		const value_type *operator->()
		{
			return (ptr->data);
		};
		ConstListIterator operator+(int n) const
		{
			ConstListIterator tmp(*this);
			tmp += n;
			return (tmp);
		};
		ConstListIterator operator-(int n) const
		{
			ConstListIterator tmp(*this);
			tmp -= n;
			return (tmp);
		};
		ConstListIterator &operator+=(int n)
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
		ConstListIterator &operator-=(int n)
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

#endif //CONTAINERS_CONSTLISTITERATOR_HPP
