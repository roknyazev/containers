//
// Created by Wolmer Rudy on 7/13/21.
//

#ifndef CONTAINERS_STACK_HPP
#define CONTAINERS_STACK_HPP
#include "Vector.hpp"

namespace ft
{
	template <typename T, typename Container = Vector<T> >
	class Stack
	{
	public:
		typedef typename Container::value_type value_type;
		typedef Container container_type;
		typedef typename Container::size_type size_type;
	private:
		container_type base_container;
	public:
		Stack(const container_type &base_container = container_type())
				: base_container(base_container)
		{}

		~Stack()
		{}

		Stack(const Stack &other)
				: base_container(other.base_container)
		{}

		Stack &operator=(const Stack &rhs)
		{
			base_container = rhs.base_container;
			return *this;
		}

		bool empty() const
		{
			return base_container.empty();
		}

		size_type size() const
		{
			return base_container.size();
		}

		value_type &top()
		{
			return base_container.back();
		}

		const value_type &top() const
		{
			return base_container.back();
		}

		void push(const value_type &val)
		{
			return base_container.push_back(val);
		}

		void pop()
		{
			base_container.pop_back();
		}

		template <typename Tf, typename Ct>
		friend void swap(Stack<Tf, Ct> &lhs, Stack<Tf, Ct> &rhs);

		template <typename Tf, typename Ct>
		friend bool operator==(const Stack<Tf, Ct> &lhs, const Stack<Tf, Ct> &rhs);

		template <typename Tf, typename Ct>
		friend bool operator<(const Stack<Tf, Ct> &lhs, const Stack<Tf, Ct> &rhs);
	};

	template <typename T, typename Container>
	void swap(Stack<T, Container> &lhs, Stack<T, Container> &rhs)
	{
		ft::swap(lhs.base_container, rhs.base_container);
	}

	template <typename T, typename Container>
	bool operator==(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs)
	{
		return lhs.base_container == rhs.base_container;
	}

	template <typename T, typename Container>
	bool operator!=(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs)
	{
		return !(lhs == rhs);
	}

	template <typename T, typename Container>
	bool operator<(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs)
	{
		return lhs.base_container < rhs.base_container;
	}

	template <typename T, typename Container>
	bool operator<=(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs)
	{
		return !(lhs > rhs);
	}

	template <typename T, typename Container>
	bool operator>(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs)
	{
		return rhs < lhs;
	}

	template <typename T, typename Container>
	bool operator>=(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs)
	{
		return !(lhs < rhs);
	}
}

#endif //CONTAINERS_STACK_HPP
