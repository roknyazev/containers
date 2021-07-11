//
// Created by Wolmer Rudy on 7/10/21.
//

#ifndef CONTAINERS_VECTORITERATOR_HPP
#define CONTAINERS_VECTORITERATOR_HPP
#include "Utils.hpp"

namespace ft
{
	template <typename T>
	class VectorIterator
	{
	public:
		typedef size_t size_type;
		typedef ptrdiff_t difference_type;
		typedef T value_type;
		typedef T *pointer;
		typedef T &reference;
		typedef RandomAccessIteratorTag iterator_category;
	private:
		pointer valuePtr;
	public:
		explicit VectorIterator(pointer value) : valuePtr(value) {}
		explicit VectorIterator() : valuePtr(NULL) {}
		VectorIterator(const VectorIterator<T> &other) : valuePtr(other.valuePtr) {}
		~VectorIterator() {}

		VectorIterator &operator=(const VectorIterator<T> &other)
		{
			valuePtr = other.valuePtr;
			return *this;
		}

		// prefix increment
		VectorIterator &operator++()
		{
			++valuePtr;
			return *this;
		}

		// postfix increment
		VectorIterator operator++(int)
		{
			VectorIterator<T> ite = *this;
			++valuePtr;
			return ite;
		}

		reference operator*() const
		{
			return *valuePtr;
		}

		pointer operator->() const
		{
			return valuePtr;
		}

		// prefix decrement
		VectorIterator &operator--()
		{
			--valuePtr;
			return *this;
		}

		// postfix decrement
		VectorIterator operator--(int)
		{
			VectorIterator ite = *this;
			--valuePtr;
			return ite;
		}

		VectorIterator &operator+=(size_type offset)
		{
			valuePtr += offset;
			return *this;
		}

		VectorIterator &operator-=(size_type offset)
		{
			valuePtr -= offset;
			return *this;
		}

		reference operator[](difference_type n) const
		{
			return *(*this + n);
		}

		template <typename Tf>
		friend bool operator==(const VectorIterator<Tf> &lhs, const VectorIterator<Tf> &rhs);

		template <typename Tf>
		friend bool operator<(const VectorIterator<Tf> &lhs, const VectorIterator<Tf> &rhs);

		template <typename Tf>
		friend ptrdiff_t operator-(const VectorIterator<Tf> &lhs, const VectorIterator<Tf> &rhs);

		template <typename Tf, class Alloc>
		friend class Vector;
	};

	template <typename T>
	bool operator==(const VectorIterator<T> &lhs, const VectorIterator<T> &rhs)
	{
		return lhs.valuePtr == rhs.valuePtr;
	}

	template <typename T>
	bool operator!=(const VectorIterator<T> &lhs, const VectorIterator<T> &rhs)
	{
		return !(lhs == rhs);
	}

	template <typename T>
	bool operator<(const VectorIterator<T> &lhs, const VectorIterator<T> &rhs)
	{
		return lhs.valuePtr < rhs.valuePtr;
	}

	template <typename T>
	bool operator>(const VectorIterator<T> &lhs, const VectorIterator<T> &rhs)
	{
		return rhs < lhs;
	}

	template <typename T>
	bool operator<=(const VectorIterator<T> &lhs, const VectorIterator<T> &rhs)
	{
		return !(lhs > rhs);
	}

	template <typename T>
	bool operator>=(const VectorIterator<T> &lhs, const VectorIterator<T> &rhs)
	{
		return !(lhs < rhs);
	}

	template <typename T>
	VectorIterator<T> operator+(const VectorIterator<T> &ite, size_t offset)
	{
		VectorIterator<T> res = ite;
		return res += offset;
	}

	template <typename T>
	VectorIterator<T> operator+(size_t offset, const VectorIterator<T> &ite)
	{
		return ite + offset;
	}

	template <typename T>
	VectorIterator<T> operator-(const VectorIterator<T> &ite, size_t offset)
	{
		VectorIterator<T> res = ite;
		return res -= offset;
	}

	template <typename T>
	ptrdiff_t operator-(const VectorIterator<T> &lhs, const VectorIterator<T> &rhs)
	{
		return lhs.valuePtr - rhs.valuePtr;
	}
}

#endif //CONTAINERS_VECTORITERATOR_HPP
