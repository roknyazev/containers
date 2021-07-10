//
// Created by Wolmer Rudy on 7/10/21.
//

#ifndef CONTAINERS_VECTORITERATOR_HPP
#define CONTAINERS_VECTORITERATOR_HPP

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
		typedef VectorIterator<T> VecItType;

		pointer _e;

		explicit VectorIterator(pointer elem) : _e(elem) {}

	public:
		explicit VectorIterator() : _e(NULL) {}

		VectorIterator(const VecItType &other) : _e(other._e) {}

		~VectorIterator() {}

		VecItType &operator=(const VecItType &other)
		{
			_e = other._e;
			return *this;
		}

		// prefix increment
		VecItType &operator++()
		{
			++_e;
			return *this;
		}

		// postfix increment
		VecItType operator++(int)
		{
			VecItType ite = *this;
			++_e;
			return ite;
		}

		reference operator*() const
		{
			return *_e;
		}

		pointer operator->() const
		{
			return _e;
		}

		// prefix decrement
		VecItType &operator--()
		{
			--_e;
			return *this;
		}

		// postfix decrement
		VecItType operator--(int)
		{
			VecItType ite = *this;
			--_e;
			return ite;
		}

		VecItType &operator+=(size_type offset)
		{
			_e += offset;
			return *this;
		}

		VecItType &operator-=(size_type offset)
		{
			_e -= offset;
			return *this;
		}

		reference operator[](difference_type n) const
		{
			return *(*this + n);
		}

		template <typename T>
		friend bool operator==(const VectorIterator<T> &lhs, const VectorIterator<T> &rhs);

		template <typename T>
		friend bool operator<(const VectorIterator<T> &lhs, const VectorIterator<T> &rhs);

		template <typename T>
		friend ptrdiff_t operator-(const VectorIterator<T> &lhs, const VectorIterator<T> &rhs);

		template <typename T>
		friend class Vector;
	};

	template <typename T>
	bool operator==(const VectorIterator<T> &lhs, const VectorIterator<T> &rhs)
	{
		return lhs._e == rhs._e;
	}

	template <typename T>
	bool operator!=(const VectorIterator<T> &lhs, const VectorIterator<T> &rhs)
	{
		return !(lhs == rhs);
	}

	template <typename T>
	bool operator<(const VectorIterator<T> &lhs, const VectorIterator<T> &rhs)
	{
		return lhs._e < rhs._e;
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
		return lhs._e - rhs._e;
	}
}

#endif //CONTAINERS_VECTORITERATOR_HPP
