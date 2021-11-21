//
// Created by Wolmer Rudy on 7/8/21.
//

#ifndef CONTAINERS_VECTOR_HPP
#define CONTAINERS_VECTOR_HPP
#include "VectorIterator.hpp"
#include <exception>
#include <iterator>
#include <limits>

namespace ft
{
	template <typename T, class A = std::allocator<T> >
	class vector
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

		template<typename Integral>
		void insert_dispatch(iterator position, Integral n, const_reference val, ft::true_type)
		{
			size_type i = distance(begin(), position);
			if (vec_capacity == 0)
			{
				allocator.deallocate(content, 0);
				content = allocator.allocate(n);
				vec_capacity = n;
				position = iterator(content + i);
				while (n--)
				{
					*position = val;
					position++;
				}
				vec_size = n;
				return;
			}
			if (vec_size == 0)
			{
				position = iterator(content + i);
				while (n--)
				{
					*position = val;
					position++;
				}
				vec_size = n;
				return;
			}
			if (vec_capacity < vec_size + n)
				reserve(vec_size + n);

			position = iterator(content + i);
			iterator it = end() + n - 1;
			while (it != position)
			{
				*it = *(it - n);
				if ((it - n) == begin())
					break;
				it--;
			}
			vec_size += n;
			while (n--)
			{
				*position = val;
				position++;
			}
		}

		template<typename InputIterator>
		void insert_dispatch(iterator position, InputIterator first, InputIterator last, ft::false_type)
		{
			size_type i = distance(begin(), position);
			size_type n = distance(first, last);
			if (vec_capacity == 0)
			{
				allocator.deallocate(content, 0);
				content = allocator.allocate(n);
				vec_capacity = n;
				position = iterator(content + i);
				while (first != last)
				{
					*position = *first;
					first++;
					position++;
				}
				vec_size = n;
				return;
			}
			if (vec_size == 0)
			{
				position = iterator(content + i);
				while (first != last)
				{
					*position = *first;
					first++;
					position++;
				}
				vec_size = n;
				return;
			}
			if (vec_capacity < vec_size + n)
				reserve(vec_size + n);
			position = iterator(content + i);

			iterator it = end() + n - 1;
			while (it != position)
			{
				*it = *(it - n);
				if ((it - n) == begin())
					break;
				it--;
			}
			while (first != last)
			{
				*position = *first;
				first++;
				position++;
			}
			vec_size += n;
		}

	public:
		explicit vector (const allocator_type& alloc = allocator_type());
		explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
		template <class InputIterator>
		vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
		vector (const vector& x);

		~vector();

		vector& operator=(const vector &);

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
		void insert	(iterator position, InputIterator first, InputIterator last);

		iterator erase (iterator position);
		iterator erase (iterator first, iterator last);

		void push_back (const value_type& val);
		void pop_back();

		void clear();
		void swap (vector& x);

		/*
		 * observers
		 */
		allocator_type get_allocator() const;
	};
}

#include "Vector.ipp"

#endif //CONTAINERS_VECTOR_HPP
