//
// Created by romak on 12.07.2021.
//

#ifndef CONTAINERS_vector_IPP
#define CONTAINERS_vector_IPP
#include <cstdio>

/*
 * MEMBER
 */

template<typename T, class A>
ft::vector<T, A>::vector(const allocator_type &alloc) :
		vec_size(0), vec_capacity(0), content(NULL), allocator(alloc)
{
	content = allocator.allocate(0);
}

template<typename T, class A>
ft::vector<T, A>::vector(size_type n, const value_type &val, const allocator_type &alloc) :
		vec_size(0), vec_capacity(0), content(NULL), allocator(alloc)
{
	content = allocator.allocate(0);
	assign(n, val);
}

template<typename T, class A>
template<class InputIterator>
ft::vector<T, A>::vector(InputIterator first, InputIterator last, const allocator_type &alloc) :
		vec_size(0), vec_capacity(0), content(NULL), allocator(alloc)
{
	content = allocator.allocate(0);
	assign(first, last);
}

template<typename T, class A>
ft::vector<T, A>::vector(const ft::vector<T, A> &x)
{
	*this = x;
}

template<typename T, class A>
ft::vector<T, A>::~vector()
{
	allocator.deallocate(content, vec_capacity);
}

template<typename T, class A>
ft::vector<T, A> &ft::vector<T, A>::operator=(const ft::vector<T, A> &rhs)
{
	if (this == &rhs)
		return (*this);
	if (content != NULL)
		allocator.deallocate(content, vec_capacity);
	allocator = rhs.allocator;
	vec_capacity = 0;
	vec_size = 0;
	content = allocator.allocate(0);
	assign(rhs.begin(), rhs.end());
	return (*this);
}

template<typename T, class A>
typename ft::vector<T, A>::iterator ft::vector<T, A>::begin()
{
	return iterator(content);
}

template<typename T, class A>
typename ft::vector<T, A>::const_iterator ft::vector<T, A>::begin() const
{
	return const_iterator(content);
}

template<typename T, class A>
typename ft::vector<T, A>::iterator ft::vector<T, A>::end()
{
	return iterator(content + vec_size);
}

template<typename T, class A>
typename ft::vector<T, A>::const_iterator ft::vector<T, A>::end() const
{
	return const_iterator(content + vec_size);
}

template<typename T, class A>
typename ft::vector<T, A>::reverse_iterator ft::vector<T, A>::rbegin()
{
	return reverse_iterator(content + vec_size - 1);
}

template<typename T, class A>
typename ft::vector<T, A>::const_reverse_iterator ft::vector<T, A>::rbegin() const
{
	return const_reverse_iterator(content + vec_size - 1);
}

template<typename T, class A>
typename ft::vector<T, A>::reverse_iterator ft::vector<T, A>::rend()
{
	return reverse_iterator(content - 1);
}

template<typename T, class A>
typename ft::vector<T, A>::const_reverse_iterator ft::vector<T, A>::rend() const
{
	return const_reverse_iterator(content - 1);
}

template<typename T, class A>
typename ft::vector<T, A>::size_type ft::vector<T, A>::size() const
{
	return vec_size;
}

template<typename T, class A>
typename ft::vector<T, A>::size_type ft::vector<T, A>::max_size() const
{
	return (std::numeric_limits<size_type>::max() / sizeof(value_type));
}

template<typename T, class A>
bool ft::vector<T, A>::empty() const
{
	return vec_size == 0;
}

template<typename T, class A>
void ft::vector<T, A>::resize(size_type n, value_type val)
{
	while (n < vec_size)
		pop_back();
	while (n > vec_size)
		push_back(val);
}

template<typename T, class A>
typename ft::vector<T, A>::size_type ft::vector<T, A>::capacity() const
{
	return vec_capacity;
}

template<typename T, class A>
void ft::vector<T, A>::reserve(size_type n)
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
typename ft::vector<T, A>::reference ft::vector<T, A>::front()
{
	return content[0];
}

template<typename T, class A>
typename ft::vector<T, A>::const_reference ft::vector<T, A>::front() const
{
	return content[0];
}

template<typename T, class A>
typename ft::vector<T, A>::reference ft::vector<T, A>::back()
{
	return content[vec_size - 1];
}

template<typename T, class A>
typename ft::vector<T, A>::const_reference ft::vector<T, A>::back() const
{
	return content[vec_size - 1];
}

template<typename T, class A>
typename ft::vector<T, A>::reference ft::vector<T, A>::operator[](size_type n)
{
	return content[n];
}

template<typename T, class A>
typename ft::vector<T, A>::const_reference ft::vector<T, A>::operator[](size_type n) const
{
	return content[n];
}

template<typename T, class A>
typename ft::vector<T, A>::reference ft::vector<T, A>::at(size_type n)
{
	if (n >= vec_size || n < 0)
	{
		char error[100];
		sprintf(error, "%s%lu%s%lu%s", "vector::at: n (which is ", n, ") >= this->size() (which is ", vec_size, ")");
		throw std::out_of_range(error);
	}
	return content[n];
}

template<typename T, class A>
typename ft::vector<T, A>::const_reference ft::vector<T, A>::at(size_type n) const
{
	if (n >= vec_size || n < 0)
	{
		char error[100];
		sprintf(error, "%s%lu%s%lu%s", "vector::at: n (which is ", n, ") >= this->size() (which is ", vec_size, ")");
		throw std::out_of_range(error);
	}
	return content[n];
}


template<typename T, class A>
void ft::vector<T, A>::assign(size_type n, const value_type &val)
{
	clear();
	insert(begin(), n, val);
}

template<typename T, class A>
template<class InputIterator>
void ft::vector<T, A>::assign(InputIterator firstIt, InputIterator lastIt)
{
	clear();
	insert(begin(), firstIt, lastIt);
}

template<typename T, class A>
typename ft::vector<T, A>::iterator ft::vector<T, A>::insert(typename ft::vector<T, A>::iterator position, const_reference val)
{
	size_type i = distance(begin(), position);

	if (vec_capacity == 0)
	{
		allocator.deallocate(content, 0);
		content = allocator.allocate(1);
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
void ft::vector<T, A>::insert(typename ft::vector<T, A>::iterator position, size_type n, const_reference val)
{
	insert_dispatch(position, n, val);
}

template<typename T, class A>
template<class InputIterator>
void ft::vector<T, A>::insert(typename ft::vector<T, A>::iterator position, InputIterator first, InputIterator last)
{
	typedef typename ft::is_integer<InputIterator>::type Integral;
	insert_dispatch(position, first, last, Integral());
}

template<typename T, class A>
typename ft::vector<T, A>::iterator ft::vector<T, A>::erase(typename ft::vector<T, A>::iterator position)
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
typename ft::vector<T, A>::iterator ft::vector<T, A>::erase(typename ft::vector<T, A>::iterator first, typename ft::vector<T, A>::iterator last)
{
	size_type n = &(*(last)) - &(*(first));
	iterator next = first + n;
	iterator curr = first;
	iterator result;

	while (curr != last && curr != end() && next != end())
	{
		*curr = *next;
		curr++;
		next++;
	}
	result = curr;
	while (curr != end() && next != end())
	{
		*curr = *next;
		curr++;
		next++;
	}
	vec_size -= n;
	return result;
}

template<typename T, class A>
void ft::vector<T, A>::push_back(const value_type &val)
{
	insert(end(), val);
}

template<typename T, class A>
void ft::vector<T, A>::pop_back()
{
	erase(end() - 1);
}

template<typename T, class A>
void ft::vector<T, A>::clear()
{
	vec_size = 0;
}

/*
 * NON-MEMBER
 */

template<typename T, class A>
void ft::vector<T, A>::swap(ft::vector<T, A> &x)
{
	ft::swap(content, x.content);
	ft::swap(vec_size, x.vec_size);
	ft::swap(vec_capacity, x.vec_capacity);
}

template<typename T, class A>
typename ft::vector<T, A>::allocator_type ft::vector<T, A>::get_allocator() const
{
	return allocator;
}

template <class T, class A>
void swap (ft::vector<T, A>& x, ft::vector<T, A>& y)
{
	x.swap(y);
}

template <class T, class A>
bool operator== (const ft::vector<T, A>& lhs, const ft::vector<T, A>& rhs)
{
	return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
}

template <class T, class A>
bool operator!= (const ft::vector<T, A>& lhs, const ft::vector<T, A>& rhs)
{
	return !(lhs == rhs);
}

template <class T, class A>
bool operator<  (const ft::vector<T, A>& lhs, const ft::vector<T, A>& rhs)
{
	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <class T, class A>
bool operator<= (const ft::vector<T, A>& lhs, const ft::vector<T, A>& rhs)
{
	return !(rhs < lhs);
}


template <class T, class A>
bool operator>  (const ft::vector<T, A>& lhs, const ft::vector<T, A>& rhs)
{
	return rhs < lhs;
}

template <class T, class A>
bool operator>= (const ft::vector<T, A>& lhs, const ft::vector<T, A>& rhs)
{
	return !(lhs < rhs);
}

#endif //CONTAINERS_vector_IPP
