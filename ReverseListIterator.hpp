//
// Created by Wolmer Rudy on 6/16/21.
//

#ifndef CONTAINERS_REVERSELISTITERATOR_HPP
#define CONTAINERS_REVERSELISTITERATOR_HPP
#include "Node.hpp"

namespace ft
{
	/*
	 * Reverse iterator
	 */

	template <class T>
	class ReverseListIterator
	{
	public:
		typedef T value_type;
		typedef T& reference;
		typedef Node<T>* pointer;
	protected:
		pointer ptr;
	public:
		ReverseListIterator()
		{};
		ReverseListIterator(const ReverseListIterator &other)
		{
			*this = other;
		};
		ReverseListIterator(pointer ptr)
		{
			this->ptr = ptr;
		};
		~ReverseListIterator()
		{};
		ReverseListIterator &operator++()
		{
			this->ptr = this->ptr->prev;
			return (*this);
		};
		ReverseListIterator &operator--()
		{
			this->ptr = this->ptr->next;
			return (*this);
		};
		ReverseListIterator operator++(int)
		{
			ReverseListIterator tmp(*this);
			operator++();
			return (tmp);
		};
		ReverseListIterator operator--(int)
		{
			ReverseListIterator tmp(*this);
			operator--();
			return (tmp);
		};
		bool operator==(const ReverseListIterator &other) const
		{
			return (ptr == other.ptr);
		};
		bool operator!=(const ReverseListIterator &other) const
		{
			return (ptr != other.ptr);
		};
		bool operator>(const ReverseListIterator &other) const
		{
			return (ptr > other.ptr);
		};
		bool operator>=(const ReverseListIterator &other) const
		{
			return (ptr >= other.ptr);
		};
		bool operator<(const ReverseListIterator &other) const
		{
			return (ptr < other.ptr);
		};
		bool operator<=(const ReverseListIterator &other) const
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
		ReverseListIterator operator+(int n) const
		{
			ReverseListIterator tmp(*this);
			tmp += n;
			return (tmp);
		};
		ReverseListIterator operator-(int n) const
		{
			ReverseListIterator tmp(*this);
			tmp -= n;
			return (tmp);
		};
		ReverseListIterator &operator+=(int n)
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
		ReverseListIterator &operator-=(int n)
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

#endif //CONTAINERS_REVERSELISTITERATOR_HPP
