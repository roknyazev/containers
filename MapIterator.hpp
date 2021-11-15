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
		typedef T                                               mapped_type;

		typedef size_t                                          size_type;
		typedef ptrdiff_t                                       difference_type;
		typedef ft::Pair<const key_type, mapped_type>           value_type;
		typedef BidirectionalIteratorTag                        iterator_category;

		typedef value_type&                                     reference;
		typedef value_type*                                     pointer;
	private:
		typedef node<Key, T, Compare>* node_pointer;
		node_pointer node;
	public:
		explicit MapIterator(node_pointer node = nullptr) :
		node(node)
		{}
		MapIterator(const MapIterator &other) :
		node(other.node)
		{}
		~MapIterator()
		{}

		MapIterator &operator=(const MapIterator &other)
		{
			if (this == &other)
				return *this;
			node = other.value;
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
			return *(node->content);
		}

		pointer operator->() const
		{
			return node->content;
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

		template <class KeyF, class TF, class CompareF>
		friend bool operator==(const MapIterator<KeyF, TF, CompareF> &lhs, const MapIterator<KeyF, TF, CompareF> &rhs);

		template <class KeyF, class TF, class CompareF, class Alloc>
		friend class Map;
	};

	template <class Key, class T, class Compare>
	bool operator==(const MapIterator<Key, T, Compare> &lhs, const MapIterator<Key, T, Compare> &rhs)
	{
		return lhs.node == rhs.node;
	}

	template <class Key, class T, class Compare>
	bool operator!=(const MapIterator<Key, T, Compare> &lhs, const MapIterator<Key, T, Compare> &rhs)
	{
		return !(lhs == rhs);
	}
}

#endif //CONTAINERS_MAPITERATOR_HPP
