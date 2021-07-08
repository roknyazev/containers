//
// Created by Wolmer Rudy on 6/16/21.
//

#ifndef CONTAINERS_LISTITERATOR_HPP
#define CONTAINERS_LISTITERATOR_HPP
#include "Node.hpp"

namespace ft
{
	/*
	 * Iterator
	 */
	template <class T>
	class ListIterator
	{
	public:
		typedef T value_type;
		typedef T& reference;
		typedef Node<T>* pointer;
	protected:
		pointer ptr;
	public:
		ListIterator()
		{};

		ListIterator(const ListIterator &other)
		{
			*this = other;
		};

		ListIterator(pointer ptr)
				: ptr(ptr)
		{};

		~ListIterator()
		{};

		pointer node() const
		{
			return (ptr);
		};

		ListIterator &operator=(const ListIterator &other)
		{
			ptr = other.ptr;
			return (*this);
		};

		ListIterator &operator++()
		{
			ptr = ptr->next;
			return (*this);
		};

		ListIterator &operator--()
		{
			ptr = ptr->prev;
			return (*this);
		};

		ListIterator operator++(int)
		{
			ListIterator tmp(*this);
			operator++();
			return (tmp);
		};

		ListIterator operator--(int)
		{
			ListIterator tmp(*this);
			operator--();
			return (tmp);
		};

		bool operator==(const ListIterator &other) const
		{
			return (ptr == other.ptr);
		};

		bool operator!=(const ListIterator &other) const
		{
			return (ptr != other.ptr);
		};

		bool operator>(const ListIterator &other) const
		{
			return (ptr > other.ptr);
		};

		bool operator>=(const ListIterator &other) const
		{
			return (ptr >= other.ptr);
		};

		bool operator<(const ListIterator &other) const
		{
			return (ptr < other.ptr);
		};

		bool operator<=(const ListIterator &other) const
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

		ListIterator operator+(int n) const
		{
			ListIterator tmp(*this);
			tmp += n;
			return (tmp);
		};

		ListIterator operator-(int n) const
		{
			ListIterator tmp(*this);
			tmp -= n;
			return (tmp);
		};

		ListIterator &operator+=(int n)
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

		ListIterator &operator-=(int n)
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

#endif //CONTAINERS_LISTITERATOR_HPP
