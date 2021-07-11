//
// Created by Wolmer Rudy on 7/8/21.
//

#ifndef CONTAINERS_VECTOR_HPP
#define CONTAINERS_VECTOR_HPP
#include "VectorIterator.hpp"
#include <exception>
#include <iterator>

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
		size_type vec_capacity;
		size_type vec_size;
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

		iterator insert (iterator position, const_reference val);
		void insert (iterator position, size_type n, const_reference val);

		template <class InputIterator>
		typename ft::enable_if
				<
				__is_input_iterator  <InputIterator>::value &&
				!__is_forward_iterator<InputIterator>::value &&
				is_constructible< value_type, typename ft::iterator_traits<InputIterator>::reference >::value,

				iterator
				>
				::type insert (iterator position, InputIterator first, InputIterator last);

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
	vec_size(0), vec_capacity(0), content(nullptr), allocator(alloc)
{
	content = allocator.allocate(0);
}

template<typename T, class A>
ft::Vector<T, A>::Vector(size_type n, const value_type &val, const allocator_type &alloc) :
	vec_size(0), vec_capacity(0), content(nullptr), allocator(alloc)
{
	content = allocator.allocate(0);
	assign(n, val);
}

template<typename T, class A>
template<class InputIterator>
ft::Vector<T, A>::Vector(InputIterator first, InputIterator last, const allocator_type &alloc) :
	vec_size(0), vec_capacity(0), content(nullptr), allocator(alloc)
{
	content = allocator.allocate(0);
	assign(first, last);
}

template<typename T, class A>
ft::Vector<T, A>::Vector(const ft::Vector<T, A> &x)
{
	*this = x;
}

template<typename T, class A>
ft::Vector<T, A>::~Vector()
{
	allocator.deallocate(content, vec_capacity);
}

template<typename T, class A>
ft::Vector<T, A> &ft::Vector<T, A>::operator=(const ft::Vector<T, A> &rhs)
{
	if (this == &rhs)
		return (*this);
	if (content != nullptr)
		allocator.deallocate(content, vec_capacity);
	allocator = rhs.allocator;
	vec_capacity = 0;
	vec_size = 0;
	content = allocator.allocate(0);
	assign(rhs.begin(), rhs.end());
	return (*this);
}

template<typename T, class A>
typename ft::Vector<T, A>::iterator ft::Vector<T, A>::begin()
{
	return iterator(content);
}

template<typename T, class A>
typename ft::Vector<T, A>::const_iterator ft::Vector<T, A>::begin() const
{
	return const_iterator(content);
}

template<typename T, class A>
typename ft::Vector<T, A>::iterator ft::Vector<T, A>::end()
{
	return iterator(content + vec_size);
}

template<typename T, class A>
typename ft::Vector<T, A>::const_iterator ft::Vector<T, A>::end() const
{
	return const_iterator(content + vec_size);
}

template<typename T, class A>
typename ft::Vector<T, A>::reverse_iterator ft::Vector<T, A>::rbegin()
{
	return reverse_iterator(content + vec_size - 1);
}

template<typename T, class A>
typename ft::Vector<T, A>::const_reverse_iterator ft::Vector<T, A>::rbegin() const
{
	return const_reverse_iterator(content + vec_size - 1);
}

template<typename T, class A>
typename ft::Vector<T, A>::reverse_iterator ft::Vector<T, A>::rend()
{
	return reverse_iterator(content - 1);
}

template<typename T, class A>
typename ft::Vector<T, A>::const_reverse_iterator ft::Vector<T, A>::rend() const
{
	return const_reverse_iterator(content - 1);
}

template<typename T, class A>
typename ft::Vector<T, A>::size_type ft::Vector<T, A>::size() const
{
	return vec_size;
}

template<typename T, class A>
typename ft::Vector<T, A>::size_type ft::Vector<T, A>::max_size() const
{
	return (std::numeric_limits<size_type>::max() / sizeof(value_type));
}

template<typename T, class A>
bool ft::Vector<T, A>::empty() const
{
	return vec_size == 0;
}

template<typename T, class A>
void ft::Vector<T, A>::resize(size_type n, value_type val)
{
	while (n < vec_size)
		pop_back();
	while (n > vec_size)
		push_back(val);
}

template<typename T, class A>
typename ft::Vector<T, A>::size_type ft::Vector<T, A>::capacity() const
{
	return vec_capacity;
}

template<typename T, class A>
void ft::Vector<T, A>::reserve(size_type n)
{
	iterator it = begin();
	iterator ite = end();
	size_type prev_size = vec_capacity;
	pointer prev_content = content;

	if (n > vec_capacity && vec_capacity != 0)
	{
		content = allocator.allocate(n);
		vec_capacity = n;
		assign(it, ite);
		allocator.deallocate(prev_content, prev_size);
	}
}

template<typename T, class A>
typename ft::Vector<T, A>::reference ft::Vector<T, A>::front()
{
	return content[0];
}

template<typename T, class A>
typename ft::Vector<T, A>::const_reference ft::Vector<T, A>::front() const
{
	return content[0];
}

template<typename T, class A>
typename ft::Vector<T, A>::reference ft::Vector<T, A>::back()
{
	return content[vec_size - 1];
}

template<typename T, class A>
typename ft::Vector<T, A>::const_reference ft::Vector<T, A>::back() const
{
	return content[vec_size - 1];
}

template<typename T, class A>
typename ft::Vector<T, A>::reference ft::Vector<T, A>::operator[](size_type n)
{
	return content[n];
}

template<typename T, class A>
typename ft::Vector<T, A>::const_reference ft::Vector<T, A>::operator[](size_type n) const
{
	return content[n];
}

template<typename T, class A>
typename ft::Vector<T, A>::reference ft::Vector<T, A>::at(size_type n)
{
	if (n >= vec_size || n < 0)
		throw std::out_of_range("Vector");
	return content[n];
}

template<typename T, class A>
typename ft::Vector<T, A>::const_reference ft::Vector<T, A>::at(size_type n) const
{
	if (n >= vec_size || n < 0)
		throw std::out_of_range("Vector");
	return content[n];
}


template<typename T, class A>
void ft::Vector<T, A>::assign(size_type n, const value_type &val)
{
	clear();
	insert(begin(), n, val);
}

template<typename T, class A>
template<class InputIterator>
void ft::Vector<T, A>::assign(InputIterator firstIt, InputIterator lastIt)
{
	clear();
	insert(begin(), firstIt, lastIt);
}

template<typename T, class A>
typename ft::Vector<T, A>::iterator ft::Vector<T, A>::insert(typename ft::Vector<T, A>::iterator position, const_reference val)
{
	size_type i = distance(begin(), position);

	if (vec_capacity == 0)
	{
		reserve(1);
		vec_capacity = 1;
	}
	if (vec_capacity < vec_size + 1)
		reserve(vec_capacity * 2);
	position = iterator(content + i);
	iterator it = end();
	while (it != position)
	{
		*it = *(it - 1);
		it--;
	}
	*it = val;
	vec_size++;
	return it;
}

template<typename T, class A>
void ft::Vector<T, A>::insert(typename ft::Vector<T, A>::iterator position, size_type n, const_reference val)
{
	size_type i = distance(begin(), position);

	if (vec_capacity == 0)
	{
		reserve(1);
		vec_capacity = 1;
	}
	while (vec_capacity < vec_size + n)
		reserve(vec_capacity * 2);

	position = iterator(content + i);
	iterator it = end() - 1 + n;
	while (it != position + n)
	{
		*it = *(it - n);
		*(it - n) = val;
		it--;
	}
	vec_size += n;
}

template<typename T, class A>
template<class InputIterator>
void ft::Vector<T, A>::insert(typename ft::Vector<T, A>::iterator position, InputIterator first, InputIterator last)
{
	size_type n = distance(last, first);
	size_type i = distance(begin(), position);

	while (vec_capacity < vec_size + n)
		reserve(vec_capacity * 2);

	position = iterator(content + i);
	iterator it = end() - 1 + n;
	while (it != position + n)
	{
		*it = *(it - n);
		*(it - n) = *first;
		first++;
		it--;
	}
	vec_size += n;
}

template<typename T, class A>
typename ft::Vector<T, A>::iterator ft::Vector<T, A>::erase(typename ft::Vector<T, A>::iterator position)
{
	iterator next = position + 1;
	iterator curr = position;

	while (curr != end())
	{
		*curr = *next;
		curr++;
		next++;
	}
	vec_size--;
	return position;
}

template<typename T, class A>
typename ft::Vector<T, A>::iterator ft::Vector<T, A>::erase(typename ft::Vector<T, A>::iterator first, typename ft::Vector<T, A>::iterator last)
{
	size_type n = &(*(last)) - &(*(first));
	iterator next = first + n;
	iterator curr = first;
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
	vec_size -= n;
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
	vec_size = 0;
}

/*
 * NON-MEMBER
 */

template<typename T, class A>
void ft::Vector<T, A>::swap(ft::Vector<T, A> &x)
{
	ft::swap(content, x.content);
	ft::swap(vec_size, x.vec_size);
	ft::swap(vec_capacity, x.vec_capacity);
}

template<typename T, class A>
typename ft::Vector<T, A>::allocator_type ft::Vector<T, A>::get_allocator() const
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
