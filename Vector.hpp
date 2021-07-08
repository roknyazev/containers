//
// Created by Wolmer Rudy on 7/8/21.
//

#ifndef CONTAINERS_VECTOR_HPP
#define CONTAINERS_VECTOR_HPP

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

#endif //CONTAINERS_VECTOR_HPP
