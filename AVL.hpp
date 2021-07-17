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
		{
		}

		~Pair()
		{
		}

		Pair(const T1 &x, const T2 &y) : first(x), second(y)
		{
		}

		template <typename U1, typename U2>
		Pair(const Pair<U1, U2> &c) : first(c.first), second(c.second)
		{
		}

		Pair(const Pair<T1, T2> &c) : first(c.first), second(c.second)
		{
		}

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





	template <typename T1, typename T2>
	struct node
	{
		Pair<T1, T2> data;
		T1 &key;
		unsigned char height;
		node* left;
		node* right;

		node(const T1 &key, const T2 &value) : data(key, value), key(data.first)
		{
			left = 0;
			right = 0;
			height = 1;
		}
	};

	template <typename T1, typename T2>
	unsigned char height(node<T1, T2>* p)
	{
		return p?p->height:0;
	}

	template <typename T1, typename T2>
	int bfactor(node<T1, T2>* p)
	{
		return height(p->right)-height(p->left);
	}

	template <typename T1, typename T2>
	void fixheight(node<T1, T2>* p)
	{
		unsigned char hl = height(p->left);
		unsigned char hr = height(p->right);
		p->height = (hl>hr?hl:hr)+1;
	}

	template <typename T1, typename T2>
	node<T1, T2>* rotateright(node<T1, T2>* p) // правый поворот вокруг p
	{
		node<T1, T2>* q = p->left;
		p->left = q->right;
		q->right = p;
		fixheight(p);
		fixheight(q);
		return q;
	}

	template <typename T1, typename T2>
	node<T1, T2>* rotateleft(node<T1, T2>* q) // левый поворот вокруг q
	{
		node<T1, T2>* p = q->right;
		q->right = p->left;
		p->left = q;
		fixheight(q);
		fixheight(p);
		return p;
	}

	template <typename T1, typename T2>
	node<T1, T2>* balance(node<T1, T2>* p) // балансировка узла p
	{
		fixheight(p);
		if( bfactor(p)==2 )
		{
			if( bfactor(p->right) < 0 )
				p->right = rotateright(p->right);
			return rotateleft(p);
		}
		if( bfactor(p)==-2 )
		{
			if( bfactor(p->left) > 0  )
				p->left = rotateleft(p->left);
			return rotateright(p);
		}
		return p; // балансировка не нужна
	}

	template <typename T1, typename T2>
	node<T1, T2>* insert(node<T1, T2>* p, T1 k) // вставка ключа k в дерево с корнем p
	{
		if( !p ) return new node<T1, T2>(k);
		if( k<p->key )
			p->left = insert(p->left,k);
		else
			p->right = insert(p->right,k);
		return balance(p);
	}

	template <typename T1, typename T2>
	node<T1, T2>* findmin(node<T1, T2>* p) // поиск узла с минимальным ключом в дереве p
	{
		return p->left?findmin(p->left):p;
	}

	template <typename T1, typename T2>
	node<T1, T2>* removemin(node<T1, T2>* p) // удаление узла с минимальным ключом из дерева p
	{
		if( p->left==0 )
			return p->right;
		p->left = removemin(p->left);
		return balance(p);
	}

	template <typename T1, typename T2>
	node<T1, T2>* remove(node<T1, T2>* p, T1 k) // удаление ключа k из дерева p
	{
		if( !p ) return 0;
		if( k < p->key )
			p->left = remove(p->left,k);
		else if( k > p->key )
			p->right = remove(p->right,k);
		else //  k == p->key
		{
			node<T1, T2>* q = p->left;
			node<T1, T2>* r = p->right;
			delete p;
			if( !r ) return q;
			node<T1, T2>* min = findmin(r);
			min->right = removemin(r);
			min->left = q;
			return balance(min);
		}
		return balance(p);
	}
}

#endif //CONTAINERS_AVL_HPP

