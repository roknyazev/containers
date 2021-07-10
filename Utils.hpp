//
// Created by Wolmer Rudy on 7/9/21.
//

#ifndef CONTAINERS_UTILS_HPP
#define CONTAINERS_UTILS_HPP

namespace ft
{
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
