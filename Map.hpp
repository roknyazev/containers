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
            first = new node_obj(allocator.allocate(1), comp);
            last = new node_obj(allocator.allocate(1), comp);
            min_node = last;
            max_node = first;
		}

		template <class InputIterator>
		Map(InputIterator first,
            InputIterator last,
            const key_compare& comp = key_compare(),
            const allocator_type& alloc = allocator_type()) :
					allocator(alloc),
					comp(comp)
		{

            root = nullptr;
            first = new node_obj(allocator.allocate(1), comp);
            last = new node_obj(allocator.allocate(1), comp);
            min_node = last;
            max_node = first;

			for (; first != last; ++first)
				insert(*first);
		}

        Map(const Map& other) :
            allocator(other.allocator),
            comp(other.comp)
        {
            root = nullptr;
            first = new node_obj(allocator.allocate(1), comp);
            last = new node_obj(allocator.allocate(1), comp);
            min_node = last;
            max_node = first;


            for (const_iterator it = other.begin(); it != other.end(); ++it)
                insert(*it);
        }

        ~Map()
        {
            //clear(); FIXME
            //deallocateNode(_lastElem);
        }

        Map& operator=(const Map& x)
        {
            Map tmp(x);
            this->swap(tmp);

            return *this;
        }





        iterator begin()
        {
            return iterator(_lastElem->right, _lastElem, _comp);
        }

        const_iterator begin() const
        {
            return const_iterator(_lastElem->right, _lastElem, _comp);
        }

        iterator end()
        {
            return iterator(_lastElem, _lastElem, _comp);
        }

        const_iterator end() const
        {
            return const_iterator(_lastElem, _lastElem, _comp);
        }

        reverse_iterator rbegin()
        {
            return reverse_iterator(_lastElem->left, _lastElem, _comp);
        }


        const_reverse_iterator rbegin() const
        {
            return const_reverse_iterator(_lastElem->left, _lastElem, _comp);
        }


        reverse_iterator rend()
        {
            return reverse_iterator(_lastElem, _lastElem, _comp);
        }

        const_reverse_iterator rend() const
        {
            return const_reverse_iterator(_lastElem, _lastElem, _comp);
        }

    };

}

#endif //CONTAINERS_MAP_HPP
