//
// Created by Wolmer Rudy on 7/17/21.
//

#ifndef CONTAINERS_MAPITERATOR_HPP
#define CONTAINERS_MAPITERATOR_HPP
#include "Utils.hpp"
#include "AVL.hpp"

namespace ft
{
	template <class Key, class T, class Compare>
	class MapIterator
	{
	public:
		typedef Key                                             key_type;
		typedef Compare                                         key_compare;
		typedef T                                               mapped_type;

		typedef size_t                                          size_type;
		typedef ptrdiff_t                                       difference_type;
		typedef ft::Pair<const key_type, mapped_type>           value_type;
		typedef BidirectionalIteratorTag                        iterator_category;

		typedef value_type&                                     reference;
		typedef value_type*                                     pointer;
	private:
		typedef node<Key, T>* node_pointer;
		pointer value;
		node_pointer node;
		key_compare comp;
	public:
		MapIterator(pointer value = nullptr, node_pointer node = nullptr, key_compare comp = key_compare()) :
		value(value),
		node(node),
		comp(comp){}
		MapIterator(const MapIterator &other) :
		value(other.value),
		node(other.node),
		comp(other.comp){}
		~MapIterator() {}

		MapIterator &operator=(const MapIterator &other)
		{
			value = other.value;
			node = other.value;
			comp = other.value;
			return *this;
		}

		// prefix increment
		MapIterator &operator++()
		{
			if (node->right != nullptr)
				node = findmin(node->right);
			else
				node = findmaxparent(node->parent);
			return *this;
		}

		// postfix increment
		MapIterator operator++(int)
		{
			MapIterator ite = *this;
			if (node->right != nullptr)
				node = findmin(node->right);
			else
				node = findmaxparent(node->parent);
			return ite;
		}

		reference operator*() const
		{
			return node->content;
		}

		pointer operator->() const
		{
			return &(node->content);
		}

		// prefix decrement
		MapIterator &operator--()
		{
			if (node->left != nullptr)
				node = findmax(node->right);
			else
				node = findminparent(node->parent);
			return *this;
		}

		// postfix decrement
		MapIterator operator--(int)
		{
			MapIterator ite = *this;
			if (node->left != nullptr)
				node = findmax(node->right);
			else
				node = findminparent(node->parent);
			return ite;
		}

		template <typename Tf>
		friend bool operator==(const MapIterator<Tf> &lhs, const MapIterator<Tf> &rhs);

		template <typename Tf, class Alloc>
		friend class Map;
	};

	template <typename T>
	bool operator==(const MapIterator<T> &lhs, const MapIterator<T> &rhs)
	{
		return lhs.node == rhs.node;
	}

	template <typename T>
	bool operator!=(const MapIterator<T> &lhs, const MapIterator<T> &rhs)
	{
		return !(lhs == rhs);
	}
}

#endif //CONTAINERS_MAPITERATOR_HPP
