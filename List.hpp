//
// Created by Wolmer Rudy on 5/20/21.
//

#ifndef CONTAINERS_LIST_HPP
#define CONTAINERS_LIST_HPP
#include "ListIterator.hpp"
#include "ConstListIterator.hpp"
#include "ReverseListIterator.hpp"
#include "ConstReverseListIterator.hpp"
#include <memory>
#include <numeric>
#include "Node.hpp"

namespace ft
{
	template <typename T, class A = std::allocator<T> >
	class Vector
	{
	public:
		typedef A allocator_type;
		typedef typename A::value_type value_type;
		typedef typename A::reference reference;
		typedef typename A::const_reference const_reference;
		typedef typename A::difference_type difference_type;
		typedef typename A::size_type size_type;
		typedef ft::ListIterator<value_type> iterator;
		typedef ft::ConstListIterator<value_type> const_iterator;
		typedef ft::ReverseListIterator<value_type> reverse_iterator;
		typedef ft::ConstReverseListIterator<value_type> const_reverse_iterator;
	private:
		typedef Node<value_type> *node;
		allocator_type allocator;
		size_type len;
		node first;
		node last;
		node new_node(value_type value, node prev, node next);
		void init_list();
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

		/*
		 * element access
		 */
		reference front();
		const_reference front() const;

		reference back();
		const_reference back() const;

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

		void push_front (const value_type& val);
		void pop_front();

		void clear();
		void swap (Vector& x);

		/*
		 * list operations
		 */
		void splice (iterator position, Vector& x);
		void splice (iterator position, Vector& x, iterator i);
		void splice (iterator position, Vector& x, iterator first, iterator last);

		void remove (const value_type& val);

		template <class Predicate>
		void remove_if (Predicate pred);

		void unique();
		template <class BinaryPredicate>
		void unique (BinaryPredicate binary_pred);

		void merge (Vector& x);
		template <class Compare>
		void merge (Vector& x, Compare comp);

		void sort();
		template <class Compare>
		void sort (Compare comp);

		void reverse();

		/*
		 * observers
		 */
		allocator_type get_allocator() const;
	};
}

template<typename T, class A>
ft::Vector::node ft::Vector<T, A>::new_node(value_type value, ft::Vector::node prev, ft::Vector::node next)
{
	return (new Node<value_type>(value, prev, next));
}

template<typename T, class A>
void ft::Vector<T, A>::init_list()
{
	first = new_node(value_type(), nullptr, nullptr);
	last = new_node(value_type(), first, nullptr);
	first->next = last;
	len = 0;
}

template<typename T, class A>
ft::Vector<T, A>::Vector(const allocator_type &alloc)
{
	allocator = alloc;
	init_list();
}

template<typename T, class A>
ft::Vector<T, A>::Vector(size_type n, const value_type &val, const allocator_type &alloc)
{
	allocator = alloc;
	init_list();
	assign(n, val);
}

template<typename T, class A>
template<class InputIterator>
ft::Vector<T, A>::Vector(InputIterator first, InputIterator last, const allocator_type &alloc)
{
	allocator = alloc;
	init_list();
	assign(first, last);
}

template<typename T, class A>
ft::Vector<T, A>::Vector(const ft::List &x)
{
	init_list();
	*this = x;
}

template<typename T, class A>
ft::Vector<T, A>::~Vector()
{
	clear();
	delete first;
	delete last;
}

template<typename T, class A>
ft::Vector<T, A> &ft::Vector<T, A>::operator=(const ft::List &x)
{
	if (this == &x)
		return (*this);
	clear();
	assign(x.first(), x.last());
	len = x.len;
	return (*this);
}

template<typename T, class A>
ft::Vector::iterator ft::Vector<T, A>::begin()
{
	return ft::Vector::iterator(first->next);
}

template<typename T, class A>
ft::Vector::const_iterator ft::Vector<T, A>::begin() const
{
	return ft::Vector::const_iterator(first->next);
}

template<typename T, class A>
ft::Vector::iterator ft::Vector<T, A>::end()
{
	return ft::Vector::iterator(last);
}

template<typename T, class A>
ft::Vector::const_iterator ft::Vector<T, A>::end() const
{
	return ft::Vector::const_iterator(end);
}

template<typename T, class A>
ft::Vector::reverse_iterator ft::Vector<T, A>::rbegin()
{
	return ft::Vector::reverse_iterator(first->next);
}

template<typename T, class A>
ft::Vector::const_reverse_iterator ft::Vector<T, A>::rbegin() const
{
	return ft::Vector::const_reverse_iterator(first->next);
}

template<typename T, class A>
ft::Vector::reverse_iterator ft::Vector<T, A>::rend()
{
	return ft::Vector::reverse_iterator(last);
}

template<typename T, class A>
ft::Vector::const_reverse_iterator ft::Vector<T, A>::rend() const
{
	return ft::Vector::const_reverse_iterator(last);
}

template<typename T, class A>
size_type ft::Vector<T, A>::size() const
{
	return len;
}

template<typename T, class A>
size_type ft::Vector<T, A>::max_size() const
{
	return 0; //FIXME
}

template<typename T, class A>
bool ft::Vector<T, A>::empty() const
{
	return len == 0;
}

template<typename T, class A>
void ft::Vector<T, A>::resize(size_type n, value_type val)
{
	while (n > len)
		push_back(val);
	while (n < len)
		pop_back(val);
}

template<typename T, class A>
reference ft::Vector<T, A>::front()
{
	return first->next->content;
}

template<typename T, class A>
const_reference ft::Vector<T, A>::front() const
{
	return first->next->content;
}

template<typename T, class A>
reference ft::Vector<T, A>::back()
{
	return last->prev->content;
}

template<typename T, class A>
const_reference ft::Vector<T, A>::back() const
{
	return last->prev->content;
}

template<typename T, class A>
template<class InputIterator>
void ft::Vector<T, A>::assign(InputIterator firstIt, InputIterator lastIt)
{
	clear();
	while (firstIt != lastIt)
	{
		push_back(*(firstIt));
		firstIt++;
	}
}

template<typename T, class A>
void ft::Vector<T, A>::assign(size_type n, const value_type &val)
{
	clear();
	while (n--)
		push_back(val);
}

template<typename T, class A>
ft::Vector::iterator ft::Vector<T, A>::insert(ft::Vector::iterator position, const value_type &val)
{
	node next = position.node();
	node prev = next->prev;
	node newNode;
	newNode = new_node(val, prev, next);
	if (next)
		next->prev = newNode;
	if (prev)
		prev->next = newNode;
	len++;
	return ft::Vector::iterator(newNode);
}

template<typename T, class A>
void ft::Vector<T, A>::insert(ft::Vector::iterator position, size_type n, const value_type &val)
{
	while (n--)
		insert(position, val);
}

template<typename T, class A>
template<class InputIterator>
void ft::Vector<T, A>::insert(ft::Vector::iterator position, InputIterator firstIt, InputIterator lastIt)
{
	while (firstIt != lastIt)
	{
		insert(position, *firstIt);
		firstIt++;
	}
}

template<typename T, class A>
ft::Vector::iterator ft::Vector<T, A>::erase(ft::Vector::iterator position)
{
	node next;
	node prev;
	delete position.node();
	if (prev)
		prev->next = next;
	if (next)
		next->prev = prev;
	len--;
	return ft::Vector::iterator(next);
}

template<typename T, class A>
ft::Vector::iterator ft::Vector<T, A>::erase(ft::Vector::iterator firstIt, ft::Vector::iterator lastIt)
{
	while (firstIt != lastIt)
	{
		erase(firstIt);
		firstIt++;
	}
	return firstIt;
}

template<typename T, class A>
void ft::Vector<T, A>::push_back(const value_type &val)
{
	node new_elem = new_node(val, last->prev, last);
	last->prev->next = new_elem;
	last->prev = new_elem;
	len++;
}

template<typename T, class A>
void ft::Vector<T, A>::pop_back()
{
	erase(last->prev);
	len--;
}

template<typename T, class A>
void ft::Vector<T, A>::push_front(const value_type &val)
{
	node new_elem = new_node(val, last->prev, last);
	first->next->prev = new_elem;
	first->next = new_elem;
	len++;
}

template<typename T, class A>
void ft::Vector<T, A>::pop_front()
{
	erase(first->next);
	len--;
}

template<typename T, class A>
void ft::Vector<T, A>::clear()
{
	erase(first->next, last);
	len = 0;
}

#endif //CONTAINERS_LIST_HPP
