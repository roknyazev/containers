//
// Created by Wolmer Rudy on 7/17/21.
//

#ifndef CONTAINERS_MAPITERATOR_HPP
#define CONTAINERS_MAPITERATOR_HPP
#include "Utils.hpp"

namespace ft
{
	template <typename T>
	class MapIterator
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
		explicit MapIterator(pointer value) : valuePtr(value) {}
		explicit MapIterator() : valuePtr(NULL) {}
		MapIterator(const MapIterator<T> &other) : valuePtr(other.valuePtr) {}
		~MapIterator() {}

		MapIterator &operator=(const MapIterator<T> &other)
		{
			valuePtr = other.valuePtr;
			return *this;
		}

		// prefix increment
		MapIterator &operator++()
		{
			++valuePtr;
			return *this;
		}

		// postfix increment
		MapIterator operator++(int)
		{
			MapIterator<T> ite = *this;
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
		MapIterator &operator--()
		{
			--valuePtr;
			return *this;
		}

		// postfix decrement
		MapIterator operator--(int)
		{
			MapIterator ite = *this;
			--valuePtr;
			return ite;
		}

		MapIterator &operator+=(size_type offset)
		{
			valuePtr += offset;
			return *this;
		}

		MapIterator &operator-=(size_type offset)
		{
			valuePtr -= offset;
			return *this;
		}

		reference operator[](difference_type n) const
		{
			return *(*this + n);
		}

		template <typename Tf>
		friend bool operator==(const MapIterator<Tf> &lhs, const MapIterator<Tf> &rhs);

		template <typename Tf>
		friend bool operator<(const MapIterator<Tf> &lhs, const MapIterator<Tf> &rhs);

		template <typename Tf>
		friend ptrdiff_t operator-(const MapIterator<Tf> &lhs, const MapIterator<Tf> &rhs);

		template <typename Tf, class Alloc>
		friend class Map;
	};

	template <typename T>
	bool operator==(const MapIterator<T> &lhs, const MapIterator<T> &rhs)
	{
		return lhs.valuePtr == rhs.valuePtr;
	}

	template <typename T>
	bool operator!=(const MapIterator<T> &lhs, const MapIterator<T> &rhs)
	{
		return !(lhs == rhs);
	}

	template <typename T>
	bool operator<(const MapIterator<T> &lhs, const MapIterator<T> &rhs)
	{
		return lhs.valuePtr < rhs.valuePtr;
	}

	template <typename T>
	bool operator>(const MapIterator<T> &lhs, const MapIterator<T> &rhs)
	{
		return rhs < lhs;
	}

	template <typename T>
	bool operator<=(const MapIterator<T> &lhs, const MapIterator<T> &rhs)
	{
		return !(lhs > rhs);
	}

	template <typename T>
	bool operator>=(const MapIterator<T> &lhs, const MapIterator<T> &rhs)
	{
		return !(lhs < rhs);
	}

	template <typename T>
	MapIterator<T> operator+(const MapIterator<T> &ite, size_t offset)
	{
		MapIterator<T> res = ite;
		return res += offset;
	}

	template <typename T>
	MapIterator<T> operator+(size_t offset, const MapIterator<T> &ite)
	{
		return ite + offset;
	}

	template <typename T>
	MapIterator<T> operator-(const MapIterator<T> &ite, size_t offset)
	{
		MapIterator<T> res = ite;
		return res -= offset;
	}

	template <typename T>
	ptrdiff_t operator-(const MapIterator<T> &lhs, const MapIterator<T> &rhs)
	{
		return lhs.valuePtr - rhs.valuePtr;
	}
}

#endif //CONTAINERS_MAPITERATOR_HPP
