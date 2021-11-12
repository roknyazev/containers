//
// Created by OUT-Knyazev-RO on 02.11.2021.
//

#ifndef CONTAINERS_MAP_HPP
#define CONTAINERS_MAP_HPP
#include "MapIterator.hpp"

namespace ft
{
	template <  class Key,
				class T,
				class Compare = std::less<Key>,
				class A = std::allocator<ft::Pair<const Key, T> >
				> class Map
	{
	public:
		typedef Key key_type;
		typedef T mapped_type;
		typedef A allocator_type;
		typedef Compare key_compare;
		typedef typename A::value_type value_type;
		typedef typename A::pointer pointer;
		typedef typename A::reference reference;
		typedef typename A::const_reference const_reference;
		typedef typename A::size_type size_type;
		typedef MapIterator<Key, T, Compare> iterator;
		typedef MapIterator<Key const, T const, Compare> const_iterator;
		typedef ReverseIterator<iterator> reverse_iterator;
		typedef ReverseIterator<const_iterator> const_reverse_iterator;
	private:
		typedef node<Key, T, Compare> node_obj;
		typedef node<Key, T, Compare> * node_ptr;

		allocator_type allocator;
		key_compare comp;

		node_ptr root;
		node_ptr min_node;
		node_ptr max_node;
		node_ptr first;
		node_ptr last;

	public:
		explicit Map(const allocator_type& alloc = allocator_type(), const Compare &cmp = Compare()):
		allocator(alloc),
		comp(cmp)
		{
			root = nullptr;
			min_node = nullptr;
			max_node = nullptr;
			first = new node_obj(allocator.allocate(1), comp);
			last = new node_obj(allocator.allocate(1), comp);
		}

		template <class InputIterator>
		Map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
					const allocator_type& alloc = allocator_type()) :
					allocator(alloc),
					comp(comp)
		{
			root = nullptr;
			min_node = nullptr;
			max_node = nullptr;
			first = new node_obj(allocator.allocate(1), comp);
			last = new node_obj(allocator.allocate(1), comp);

			for (; first != last; ++first)
				insert(*first);
		}

	};

}

#endif //CONTAINERS_MAP_HPP
