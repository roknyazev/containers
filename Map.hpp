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
        class value_compare
        {
            friend class map;

        protected:

            key_compare comp;

            value_compare(Compare c) : comp(c) {}  // constructed with map's comparison object

        public:

            typedef bool        result_type;
            typedef value_type  first_argument_type;
            typedef value_type  second_argument_type;

            bool operator()(const value_type& x, const value_type& y) const
            {
                return comp(x.first, y.first);
            }
        };
	private:
		typedef node<key_type , mapped_type, Compare> node_obj;
		typedef node<key_type , mapped_type, Compare> * node_ptr;

		allocator_type allocator;
		key_compare comp;

		node_ptr root;
		node_ptr min_node;
		node_ptr max_node;
		node_ptr first;
		node_ptr last;

        size_type map_size;

        void detach_first_last()
        {
            min_node->left = nullptr;
            max_node->right = nullptr;
        }

        void attach_first_last()
        {
            min_node->left = first;
            first->parent = min_node;

            max_node->right = last;
            last->parent = max_node;
        }

        node_ptr find_key(node_ptr p, key_type key)
        {
            if (!p)
                return 0;
            if (p->comp(key, p->key))
                return find_key(p->left, key);
            else if (p->comp(p->key, key))
                return find_key(p->right, key);
            else
                return p;
        }
	public:


		explicit Map(const allocator_type& alloc = allocator_type(), const Compare &cmp = Compare()):
		allocator(alloc),
		comp(cmp)
		{
            root = nullptr;
            map_size = 0;
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
            map_size = 0;
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
            map_size = 0;
            first = new node_obj(allocator.allocate(1), comp);
            last = new node_obj(allocator.allocate(1), comp);
            min_node = last;
            max_node = first;


            for (const_iterator it = other.begin(); it != other.end(); ++it)
                insert(*it);
        }

        ~Map()
        {
            clear();
            delete first;
            delete last;
        }

        Map& operator=(const Map& x)
        {
            Map tmp(x);
            this->swap(tmp);

            return *this;
        }





        iterator begin()
        {
            return iterator(min_node);
        }

        const_iterator begin() const
        {
            return const_iterator(min_node);
        }

        iterator end()
        {
            return iterator(last);
        }

        const_iterator end() const
        {
            return const_iterator(last);
        }

        reverse_iterator rbegin()
        {
            return reverse_iterator(max_node);
        }


        const_reverse_iterator rbegin() const
        {
            return const_reverse_iterator(max_node);
        }


        reverse_iterator rend()
        {
            return reverse_iterator(first);
        }

        const_reverse_iterator rend() const
        {
            return const_reverse_iterator(first);
        }

        bool empty() const
        {
            return map_size == 0;
        }

        size_type size() const
        {
            return map_size;
        }

        size_type       max_size() const
        {
            return (std::numeric_limits<size_type>::max() / sizeof(value_type));
        }

        mapped_type& operator[](const key_type& k)
        {
            detach_first_last();
            node_ptr tmp = find_key(root, k);
            attach_first_last();

            if (tmp)
                return tmp->content->second;

            pointer val = allocator.allocate(1);
            allocator.construct(val, make_pair<key_type, mapped_type>(k, mapped_type()));
            insert(*val);
            return val->second;
        }

        ft::Pair<iterator, bool> insert (value_type& val)
        {
            detach_first_last();
            node_ptr elemIsPresent = find_key(root, val.first);
            attach_first_last();
            if (elemIsPresent)
                return ft::Pair<iterator, bool>(iterator(elemIsPresent), false);

            ++map_size;
            detach_first_last();
            node_ptr res = nullptr;
            root = ft::insert<key_type, mapped_type, key_compare>(root, &val, nullptr, &res);
            //root = ft::insert<key_type, mapped_type, key_compare>(root, &val, nullptr, res);
            root->parent = nullptr;
            if (comp(val.first, min_node->key) || min_node == last)
                min_node = res;
            if (comp(max_node->key, val.first) || max_node == first)
                max_node = res;
            attach_first_last();
            return ft::Pair<iterator, bool>(iterator(res), true);
        }

        template <class InputIterator>
        void insert (InputIterator first_it, InputIterator last_it)
        {
            while (first_it != last_it)
                insert(*first_it++);
        }

        void erase (iterator position)
        {
            ft::remove(root, position->first);
            --map_size;
        }

        size_type erase (const key_type& k)
        {
            size_type ret;
            node_ptr tmp = ft::remove(root, k);
            if (tmp == 0)
                ret = 0;
            else
                ret = 1;
            map_size -= ret;
            return ret;
        }

        void erase (iterator first_it, iterator last_it)
        {
            while (first_it != last_it)
            {
                iterator tmp(first_it);
                ++first_it;
                erase(tmp);
            }
        }

        void swap (Map& x)
        {
            ft::swap(allocator);
            ft::swap(comp);
            ft::swap(root);
            ft::swap(min_node);
            ft::swap(max_node);
            ft::swap(first);
            ft::swap(last);
            ft::swap(map_size);
        }

        void clear()
        {
            erase(begin(), end());
        }


        key_compare key_comp() const
        {
            return comp;
        }

        value_compare value_comp() const
        {
            return value_compare(comp);
        }

        iterator find(const key_type& k)
        {
            node_ptr tmp = find_key(root, k);

            if (tmp)
                return iterator(tmp);

            return end();
        }

        const_iterator find(const key_type& k) const
        {
            node_ptr tmp = searchNode(root, k);

            if (tmp)
                return const_iterator(tmp);

            return end();
        }

        size_type count (const key_type& k) const
        {
            node_ptr tmp = searchNode(root, k);

            return tmp;
        }

        iterator lower_bound(const key_type& k)
        {
            iterator it = begin();

            for (; it != end(); ++it)
                if (!_comp(it->first, k))
                    break;

            return it;
        }

        const_iterator lower_bound(const key_type& k) const
        {
            const_iterator it = begin();

            for (; it != end(); ++it)
                if (!_comp(it->first, k))
                    break;

            return it;
        }

        iterator upper_bound(const key_type& k)
        {
            iterator it = begin();

            for (; it != end(); ++it)
                if (_comp(k, it->first))
                    break;

            return it;
        }

        const_iterator upper_bound(const key_type& k) const
        {
            const_iterator it = begin();

            for (; it != end(); ++it)
                if (_comp(k, it->first))
                    break;

            return it;
        }
    };

}

#endif //CONTAINERS_MAP_HPP
