//
// Created by Wolmer Rudy on 7/8/21.
//

#ifndef CONTAINERS_VECTOR_HPP
#define CONTAINERS_VECTOR_HPP
#include <memory>
#include "Utils.hpp"

namespace ft
{
	template <typename T, class A = std::allocator<T> >
	class Vector
	{
	public:
		typedef A allocator_type;
		typedef typename A::value_type value_type;
		typedef typename A::pointer pointer;
		typedef typename A::reference reference;
		typedef typename A::const_reference const_reference;
		typedef typename A::size_type size_type;
		typedef VectorIterator<value_type> iterator;
		typedef VectorIterator<value_type const> const_iterator;
		typedef ReverseIterator<iterator> reverse_iterator;
		typedef ReverseIterator<const_iterator> const_reverse_iterator;
	private:
		allocator_type allocator;
		pointer content;
		size_type capacity;
		size_type size;
	public:
		explicit Vector (const allocator_type& alloc = allocator_type());
		explicit Vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
		template <class InputIterator>
		Vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
		Vector (const Vector& x);

		~Vector();

		Vector& operator=(const Vector &);

		/*
		 * iterators
		 */
		iterator begin();
		const_iterator begin() const;

		iterator end();
		const_iterator end() const;

		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;

		reverse_iterator rend();
		const_reverse_iterator rend() const;

		/*
		 * capacity
		 */
		size_type size() const;
		size_type max_size() const;
		bool empty() const;
		void resize (size_type n, value_type val = value_type());
		size_type capacity() const;
		void reserve (size_type n);

		/*
		 * element access
		 */
		reference front();
		const_reference front() const;

		reference back();
		const_reference back() const;

		reference operator[] (size_type n);
		const_reference operator[] (size_type n) const;

		reference at (size_type n);
		const_reference at (size_type n) const;

		/*
		 * modifiers
		 */
		template <class InputIterator>
		void assign (InputIterator firstIt, InputIterator lastIt);
		void assign (size_type n, const value_type& val);

		iterator insert (iterator position, const value_type& val);
		void insert (iterator position, size_type n, const value_type& val);

		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last);

		iterator erase (iterator position);
		iterator erase (iterator first, iterator last);

		void push_back (const value_type& val);
		void pop_back();

		void clear();
		void swap (Vector& x);

		/*
		 * observers
		 */
		allocator_type get_allocator() const;
	};
}

/*
 * MEMBER
 */

template<typename T, class A>
ft::Vector<T, A>::Vector(const allocator_type &alloc) :
	size(0), capacity(0), content(nullptr), allocator(alloc)
{
	content = allocator.allocate(0);
}

template<typename T, class A>
ft::Vector<T, A>::Vector(size_type n, const value_type &val, const allocator_type &alloc) :
	size(0), capacity(0), content(nullptr), allocator(alloc)
{
	content = allocator.allocate(0);
	assign(n, val);
}

template<typename T, class A>
template<class InputIterator>
ft::Vector<T, A>::Vector(InputIterator first, InputIterator last, const allocator_type &alloc) :
	size(0), capacity(0), content(nullptr), allocator(alloc)
{
	content = allocator.allocate(0);
	assign(first, last);
}

template<typename T, class A>
ft::Vector<T, A>::Vector(const ft::Vector &x)
{
	*this = x;
}

template<typename T, class A>
ft::Vector<T, A>::~Vector()
{
	allocator.deallocate(content, capacity);
}

template<typename T, class A>
ft::Vector<T, A> &ft::Vector<T, A>::operator=(const ft::Vector &rhs)
{
	if (this == &rhs)
		return (*this);
	if (content != nullptr)
		allocator.deallocate(content, capacity);
	allocator = rhs.allocator;
	capacity = 0;
	size = 0;
	content = allocator.allocate(0);
	assign(rhs.begin(), rhs.end());
	return (*this);
}

template<typename T, class A>
ft::Vector::iterator ft::Vector<T, A>::begin()
{
	return iterator(content);
}

template<typename T, class A>
ft::Vector::const_iterator ft::Vector<T, A>::begin() const
{
	return const_iterator(content);
}

template<typename T, class A>
ft::Vector::iterator ft::Vector<T, A>::end()
{
	return iterator(content + size);
}

template<typename T, class A>
ft::Vector::const_iterator ft::Vector<T, A>::end() const
{
	return const_iterator(content + size);
}

template<typename T, class A>
ft::Vector::reverse_iterator ft::Vector<T, A>::rbegin()
{
	return reverse_iterator(content + size - 1);
}

template<typename T, class A>
ft::Vector::const_reverse_iterator ft::Vector<T, A>::rbegin() const
{
	return const_reverse_iterator(content + size - 1);
}

template<typename T, class A>
ft::Vector::reverse_iterator ft::Vector<T, A>::rend()
{
	return reverse_iterator(content - 1);
}

template<typename T, class A>
ft::Vector::const_reverse_iterator ft::Vector<T, A>::rend() const
{
	return const_reverse_iterator(content - 1);
}

template<typename T, class A>
size_type ft::Vector<T, A>::size() const
{
	return size;
}

template<typename T, class A>
size_type ft::Vector<T, A>::max_size() const
{
	return (std::numeric_limits<size_type>::max() / sizeof(value_type));
}

template<typename T, class A>
bool ft::Vector<T, A>::empty() const
{
	return size == 0;
}

template<typename T, class A>
void ft::Vector<T, A>::resize(size_type n, value_type val)
{
	while (n < size)
		pop_back();
	while (n > size)
		push_back(value);
}

template<typename T, class A>
size_type ft::Vector<T, A>::capacity() const
{
	return capacity;
}

template<typename T, class A>
void ft::Vector<T, A>::reserve(size_type n)
{
	iterator it = begin();
	iterator ite = end();
	size_type prev_size = capacity;
	pointer prev_content = content;

	if (n > capacity)
	{
		content = allocator.allocate(n);
		capacity = n;
		assign(it, ite);
		allocator.deallocate(prev_content, prev_size);
	}
}

template<typename T, class A>
reference ft::Vector<T, A>::front()
{
	return content[0];
}

template<typename T, class A>
const_reference ft::Vector<T, A>::front() const
{
	return content[0];
}

template<typename T, class A>
reference ft::Vector<T, A>::back()
{
	return content[size - 1];
}

template<typename T, class A>
const_reference ft::Vector<T, A>::back() const
{
	return content[size - 1];
}

template<typename T, class A>
reference ft::Vector<T, A>::operator[](size_type n)
{
	return content[n];
}

template<typename T, class A>
const_reference ft::Vector<T, A>::operator[](size_type n) const
{
	return content[n];
}

template<typename T, class A>
reference ft::Vector<T, A>::at(size_type n)
{
	if (n >= size || n < 0)
		throw std::out_of_range();
	return content[n];
}

template<typename T, class A>
const_reference ft::Vector<T, A>::at(size_type n) const
{
	if (n >= size || n < 0)
		throw std::out_of_range();
	return content[n];
}


template<typename T, class A>
void ft::Vector<T, A>::assign(size_type n, const value_type &val)
{
	clear();
	if (n > capacity)
		reserve(n);
	insert(begin(), n, val);
}

template<typename T, class A>
template<class InputIterator>
void ft::Vector<T, A>::assign(InputIterator firstIt, InputIterator lastIt)
{
	size_type n;

	clear();
	n = (&(*lastIt) - &(*firstIt));
	if (n > capacity)
		reserve(n);
	insert(begin(), firstIt, lastIt);
}

template<typename T, class A>
ft::Vector::iterator ft::Vector<T, A>::insert(ft::Vector::iterator position, const value_type &val)
{
	if (capacity < size + 1)
		reserve(capacity * 2);
	iterator it = end();
	while (it != position)
	{
		*it = *(it - 1);
		it--;
	}
	*it = val;
	size++;
	return it;
}

template<typename T, class A>
void ft::Vector<T, A>::insert(ft::Vector::iterator position, size_type n, const value_type &val)
{
	while (capacity < size + n)
		reserve(capacity * 2);
	iterator it = end() - 1 + n;
	while (it != position + n)
	{
		*it = *(it - n);
		*(it - n) = val;
		it--;
	}
	size += n;
}

template<typename T, class A>
template<class InputIterator>
void ft::Vector<T, A>::insert(ft::Vector::iterator position, InputIterator first, InputIterator last)
{
	size_type n = &(*(last)) - &(*(first));

	while (capacity < size + n)
		reserve(capacity * 2);
	iterator it = end() - 1 + n;
	while (it != position + n)
	{
		*it = *(it - n);
		*(it - n) = *first;
		first++;
		it--;
	}
	size += n;
}

template<typename T, class A>
ft::Vector::iterator ft::Vector<T, A>::erase(ft::Vector::iterator position)
{
	iterator next = position + 1;
	iterator curr = position;

	while (curr != end())
	{
		*curr = *next;
		curr++;
		next++;
	}
	size--;
	return position;
}

template<typename T, class A>
ft::Vector::iterator ft::Vector<T, A>::erase(ft::Vector::iterator first, ft::Vector::iterator last)
{
	size_type n = &(*(last)) - &(*(first));
	iterator next = position + n;
	iterator curr = position;
	iterator result;

	while (curr != last && curr != end())
	{
		*curr = *next;
		curr++;
		next++;
	}
	result = curr;
	while (curr != end())
	{
		*curr = *next;
		curr++;
		next++;
	}
	size -= n;
	return result;
}

template<typename T, class A>
void ft::Vector<T, A>::push_back(const value_type &val)
{
	insert(end(), val);
}

template<typename T, class A>
void ft::Vector<T, A>::pop_back()
{
	erase(end() - 1);
}

template<typename T, class A>
void ft::Vector<T, A>::clear()
{
	size = 0;
}

/*
 * NON-MEMBER
 */

template<typename T, class A>
void ft::Vector<T, A>::swap(ft::Vector<T, A> &x)
{
	ft::swap(content, x.content);
	ft::swap(size, x.size);
	ft::swap(capacity, x.capacity);
}

template<typename T, class A>
allocator_type ft::Vector<T, A>::get_allocator() const
{
	return allocator;
}

template <class T, class A>
void swap (ft::Vector<T, A>& x, ft::Vector<T, A>& y)
{
	x.swap(y);
}

template <class T, class A>
bool operator== (const ft::Vector<T, A>& lhs, const ft::Vector<T, A>& rhs)
{
	return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
}

template <class T, class A>
bool operator!= (const ft::Vector<T, A>& lhs, const ft::Vector<T, A>& rhs)
{
	return !(lhs == rhs);
}

template <class T, class A>
bool operator<  (const ft::Vector<T, A>& lhs, const ft::Vector<T, A>& rhs)
{
	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <class T, class A>
bool operator<= (const ft::Vector<T, A>& lhs, const ft::Vector<T, A>& rhs)
{
	return !(rhs < lhs);
}


template <class T, class A>
bool operator>  (const ft::Vector<T, A>& lhs, const ft::Vector<T, A>& rhs)
{
	return rhs < lhs;
}

template <class T, class A>
bool operator>= (const ft::Vector<T, A>& lhs, const ft::Vector<T, A>& rhs)
{
	return !(lhs < rhs);
}


#endif //CONTAINERS_VECTOR_HPP
