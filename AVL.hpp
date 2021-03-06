//
// Created by Wolmer Rudy on 7/17/21.
//

#ifndef CONTAINERS_AVL_HPP
#define CONTAINERS_AVL_HPP
#include "Utils.hpp"

namespace ft
{
	template <typename T1, typename T2>
	struct Pair
	{
		T1 first;
		T2 second;

		Pair() : first(), second()
		{}

		~Pair()
		{}

		Pair(const T1 &x, const T2 &y) : first(x), second(y)
		{}

		template <typename U1, typename U2>
		explicit Pair(const Pair<U1, U2> &c) : first(c.first), second(c.second)
		{}

		Pair(const Pair<T1, T2> &c) : first(c.first), second(c.second)
		{}

		template <typename U1, typename U2>
		Pair<T1, T2> &operator=(const Pair<U1, U2> &c)
		{
			first = c.first;
			second = c.second;
			return *this;
		}

		Pair<T1, T2> &operator=(const Pair<T1, T2> &c)
		{
			first = c.first;
			second = c.second;
			return *this;
		}
	};

	template <typename T1, typename T2>
	Pair<T1, T2> make_pair(T1 t, T2 u)
	{
		return Pair<T1, T2>(t, u);
	}

	template <typename T1, typename T2>
	bool operator==(const Pair<T1, T2> &lhs, const Pair<T1, T2> &rhs)
	{
		return lhs.first == rhs.first && lhs.second == rhs.second;
	}

	template <typename T1, typename T2>
	bool operator<(const Pair<T1, T2> &lhs, const Pair<T1, T2> &rhs)
	{
		return lhs.first < rhs.first && lhs.second < rhs.second;
	}

	template <typename T1, typename T2>
	bool operator!=(const Pair<T1, T2> &lhs, const Pair<T1, T2> &rhs)
	{
		return !(lhs == rhs);
	}

	template <typename T1, typename T2>
	bool operator<=(const Pair<T1, T2> &lhs, const Pair<T1, T2> &rhs)
	{
		return lhs <= rhs;
	}

	template <typename T1, typename T2>
	bool operator>(const Pair<T1, T2> &lhs, const Pair<T1, T2> &rhs)
	{
		return rhs < lhs;
	}

	template <typename T1, typename T2>
	bool operator>=(const Pair<T1, T2> &lhs, const Pair<T1, T2> &rhs)
	{
		return !(lhs < rhs);
	}

	template <typename T1, typename T2, class Compare>
	struct node
	{
		typedef Compare    key_compare;
		Pair<const T1, T2> *content;
		const T1 &key;
		unsigned char height;
		node* parent;
		node* left;
		node* right;
		key_compare comp;
		node(Pair<const T1, T2> *content, key_compare comp) :
		content(content),
		key(content->first),
		parent(nullptr),
		comp(comp)
		{
			left = 0;
			right = 0;
			height = 1;
		}
	};

	template <typename T1, typename T2, class Compare>
	unsigned char height(node<T1, T2, Compare>* p)
	{
		return p ? p->height : 0;
	}

	template <typename T1, typename T2, class Compare>
	int bfactor(node<T1, T2, Compare>* p)
	{
		return height(p->right) - height(p->left);
	}

	template <typename T1, typename T2, class Compare>
	void fixheight(node<T1, T2, Compare>* p)
	{
		unsigned char hl = height(p->left);
		unsigned char hr = height(p->right);
		p->height = (hl > hr  ? hl : hr) + 1;
	}

	template <typename T1, typename T2, class Compare>
	node<T1, T2, Compare>* rotateright(node<T1, T2, Compare>* p)
	{
		node<T1, T2, Compare>* q = p->left;
        node<T1, T2, Compare>* r = q->right;
        node<T1, T2, Compare>* parent = p->parent;

		p->left = r;
		q->right = p;

        if (r)
            r->parent = p;
        if (p)
            p->parent = q;
        if (q)
            q->parent = parent;

		fixheight(p);
		fixheight(q);
		return q;
	}

	template <typename T1, typename T2, class Compare>
	node<T1, T2, Compare>* rotateleft(node<T1, T2, Compare>* q)
	{
		node<T1, T2, Compare>* p = q->right;
        node<T1, T2, Compare>* r = p->left;
        node<T1, T2, Compare>* parent = q->parent;

		q->right = r;
		p->left = q;

        if (r)
            r->parent = q;
        if (q)
            q->parent = p;
        if (p)
            p->parent = parent;

		fixheight(q);
		fixheight(p);
		return p;
	}

	template <typename T1, typename T2, class Compare>
	node<T1, T2, Compare>* balance(node<T1, T2, Compare>* p)
	{
		fixheight(p);
		if (bfactor(p) == 2)
		{
			if (bfactor(p->right) < 0)
				p->right = rotateright(p->right);
			return rotateleft(p);
		}
		if (bfactor(p)== -2)
		{
			if(bfactor(p->left) > 0)
				p->left = rotateleft(p->left);
			return rotateright(p);
		}
		return p;
	}

	template <typename T1, typename T2, class Compare>
	node<T1, T2, Compare>* insert(node<T1, T2, Compare>* p,
                                  Pair<const T1, T2> *content,
                                  node<T1, T2, Compare>* up,
                                  node<T1, T2, Compare>** result)
	{
        node<T1, T2, Compare> *res;
		if (!p)
        {
            res = new node<T1, T2, Compare>(content, Compare());
            *result = res;
            (*result)->parent = up;
            return *result;
        }
		if (p->comp(content->first, p->key))
			p->left = insert(p->left, content, p, result);
		else
			p->right = insert(p->right, content, p, result);
		return balance(p);
	}

	template <typename T1, typename T2, class Compare>
	node<T1, T2, Compare>* findmin(node<T1, T2, Compare>* p)
	{
		return p->left ? findmin(p->left) : p;
	}

	template <typename T1, typename T2, class Compare>
	node<T1, T2, Compare>* findmax(node<T1, T2, Compare>* p)
	{
		return p->right ? findmin(p->right) : p;
	}

	template <typename T1, typename T2, class Compare>
	node<T1, T2, Compare>* findmaxparent(node<T1, T2, Compare>* p)
	{
        if (p->parent == nullptr)
            return p;
		return (p != p->parent->left) ? findmaxparent(p->parent) : p->parent;
	}

	template <typename T1, typename T2, class Compare>
	node<T1, T2, Compare>* findminparent(node<T1, T2, Compare>* p)
	{
        if (p->parent == nullptr)
            return p;
		return (p != p->parent->right) ? findmaxparent(p->parent) : p->parent;
	}

	template <typename T1, typename T2, class Compare>
	node<T1, T2, Compare>* removemin(node<T1, T2, Compare>* p)
	{
		if (p->left == 0)
			return p->right;
		p->left = removemin(p->left);
		return balance(p);
	}

	template <typename T1, typename T2, class Compare>
	node<T1, T2, Compare>* remove(node<T1, T2, Compare>* p, T1 k)
	{
		if (!p)
			return 0;
		if (p->comp(k, p->key))
			p->left = remove(p->left, k);
		else if (p->comp(p->key, k))
			p->right = remove(p->right, k);
		else
		{
			node<T1, T2, Compare>* q = p->left;
			node<T1, T2, Compare>* r = p->right;
			delete p;
			if (!r)
				return q;
			node<T1, T2, Compare>* min = findmin(r);
			min->right = removemin(r);
			min->left = q;
			return balance(min);
		}
		return balance(p);
	}
}

#endif //CONTAINERS_AVL_HPP

