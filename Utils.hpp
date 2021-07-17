//
// Created by Wolmer Rudy on 7/9/21.
//

#ifndef CONTAINERS_UTILS_HPP
#define CONTAINERS_UTILS_HPP
#include <cstddef>
#include <memory>
#include "TypeTraits.hpp"
#include "AVL.hpp"

namespace ft
{
	/*
	 * iterators_traits, reverse_iterator
	 */

	// tags
	struct InputIteratorTag
	{
	};
	struct ForwardIteratorTag : public InputIteratorTag
	{
	};
	struct BidirectionalIteratorTag : public ForwardIteratorTag
	{
	};
	struct RandomAccessIteratorTag : public BidirectionalIteratorTag
	{
	};


	//it traits
	template <typename Iter>
	struct iterator_traits
	{
		typedef typename Iter::difference_type difference_type;
		typedef typename Iter::value_type value_type;
		typedef typename Iter::pointer pointer;
		typedef typename Iter::reference reference;
		typedef typename Iter::iterator_category iterator_category;
	};

	// distance
	template <typename RandomAccessIt>
	typename iterator_traits<RandomAccessIt>::difference_type distance(RandomAccessIt first, RandomAccessIt last, RandomAccessIteratorTag)
	{
		return last - first;
	}

	template <typename InputIt>
	typename iterator_traits<InputIt>::difference_type distance(InputIt first, InputIt last, InputIteratorTag)
	{
		typename iterator_traits<InputIt>::difference_type dist = 0;
		for (; first != last; ++first)
			dist++;
		return dist;
	}

	template <typename InputIt>
	typename iterator_traits<InputIt>::difference_type distance(InputIt first, InputIt last)
	{
		return distance(first, last, typename iterator_traits<InputIt>::iterator_category());
	}


	template <typename Iter>
	class ReverseIterator
	{
	private:
		Iter base_iterator;

		ReverseIterator();

	public:
		typedef Iter iterator_type;
		typedef typename iterator_traits<Iter>::difference_type difference_type;
		typedef typename iterator_traits<Iter>::value_type value_type;
		typedef typename iterator_traits<Iter>::pointer pointer;
		typedef typename iterator_traits<Iter>::reference reference;
		typedef typename iterator_traits<Iter>::iterator_category iterator_category;

		ReverseIterator(Iter base) : base_iterator(base)
		{
		}

		ReverseIterator(const ReverseIterator<Iter> &other) : base_iterator(other.base_iterator)
		{
		}

		~ReverseIterator()
		{
		}

		Iter base() const
		{
			return base_iterator;
		}

		ReverseIterator<Iter> &operator=(const ReverseIterator<Iter> &other)
		{
			base_iterator = other.base_iterator;
			return *this;
		}

		ReverseIterator<Iter> &operator++()
		{
			--base_iterator;
			return *this;
		}

		ReverseIterator<Iter> operator++(int)
		{
			ReverseIterator<Iter> ite(base_iterator--);
			return ite;
		}

		reference operator*() const
		{
			Iter ite(base_iterator);
			--ite;
			return *ite;
		}

		pointer operator->() const
		{
			Iter ite(base_iterator);
			--ite;
			return ite.operator->();
		}

		ReverseIterator<Iter> &operator--()
		{
			++base_iterator;
			return *this;
		}

		ReverseIterator<Iter> operator--(int)
		{
			ReverseIterator<Iter> ite(base_iterator++);
			return ite;
		}

		ReverseIterator<Iter> &operator+=(difference_type offset)
		{
			base_iterator -= offset;
			return *this;
		}

		ReverseIterator<Iter> &operator-=(difference_type offset)
		{
			base_iterator += offset;
			return *this;
		}
	};

	template <typename Iter>
	bool operator==(const ReverseIterator<Iter> &lhs, const ReverseIterator<Iter> &rhs)
	{
		return lhs.base() == rhs.base();
	}

	template <typename Iter>
	bool operator!=(const ReverseIterator<Iter> &lhs, const ReverseIterator<Iter> &rhs)
	{
		return lhs.base() != rhs.base();
	}

	template <typename Iter>
	bool operator<(const ReverseIterator<Iter> &lhs, const ReverseIterator<Iter> &rhs)
	{
		return lhs.base() > rhs.base();
	}

	template <typename Iter>
	bool operator>(const ReverseIterator<Iter> &lhs, const ReverseIterator<Iter> &rhs)
	{
		return lhs.base() < rhs.base();
	}

	template <typename Iter>
	bool operator<=(const ReverseIterator<Iter> &lhs, const ReverseIterator<Iter> &rhs)
	{
		return lhs.base() >= rhs.base();
	}

	template <typename Iter>
	bool operator>=(const ReverseIterator<Iter> &lhs, const ReverseIterator<Iter> &rhs)
	{
		return lhs.base() <= rhs.base();
	}

	template <typename Iter>
	ReverseIterator<Iter> operator+(const ReverseIterator<Iter> &ite, size_t offset)
	{
		ReverseIterator<Iter> r(ite.base() - offset);
		return r;
	}

	template <typename Iter>
	ReverseIterator<Iter> operator+(typename ReverseIterator<Iter>::difference_type offset, const ReverseIterator<Iter> &ite)
	{
		ReverseIterator<Iter> r(ite.base() - offset);
		return r;
	}

	template <typename Iter>
	ReverseIterator<Iter> operator-(const ReverseIterator<Iter> &ite, typename ReverseIterator<Iter>::difference_type offset)
	{
		ReverseIterator<Iter> r(ite.base() + offset);
		return r;
	}

	template <typename Iter>
	ptrdiff_t operator-(const ReverseIterator<Iter> &lhs, const ReverseIterator<Iter> &rhs)
	{
		return rhs.base() - lhs.base();
	}

	/*
	 * equal/lexicographical compare
	 */

	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
								 InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return (false);
			else if (*first1 < *first2)
				return (true);
			++first1;
			++first2;
		}
		return (first2 != last2);
	}

	template <class InputIterator1, class InputIterator2>
	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
	{
		while (first1 != last1)
		{
			if (*first1 != *first2)
				return (false);
			++first1;
			++first2;
		}
		return (true);
	}

	template<class value_type>
	void swap(value_type &a, value_type &b)
	{
		value_type tmp(a);
		a = b;
		b = tmp;
	}
}

#endif //CONTAINERS_UTILS_HPP
