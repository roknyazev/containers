//
// Created by romak on 12.07.2021.
//

#ifndef CONTAINERS_TYPETRAITS_HPP
#define CONTAINERS_TYPETRAITS_HPP

namespace ft
{
	struct true_type { };
	struct false_type { };

	template<bool>
	struct truth_type
	{ typedef false_type type; };

	template<>
	struct truth_type<true>
	{ typedef true_type type; };
	
	template<class Sp, class T>
	struct traitor
	{
		enum { value = bool(Sp::value) || bool(T::value) };
		typedef typename truth_type<value>::type type;
	};

	template<typename, typename>
	struct are_same
	{
		enum { value = 0 };
		typedef false_type type;
	};

	template<typename T>
	struct are_same<T, T>
	{
		enum { value = 1 };
		typedef true_type type;
	};

	template<typename T>
	struct is_void
	{
		enum { value = 0 };
		typedef false_type type;
	};

	template<>
	struct is_void<void>
	{
		enum { value = 1 };
		typedef true_type type;
	};

	template<typename T>
	struct is_integer
	{
		enum { value = 0 };
		typedef false_type type;
	};

	template<>
	struct is_integer<bool>
	{
		enum { value = 1 };
		typedef true_type type;
	};

	template<>
	struct is_integer<char>
	{
		enum { value = 1 };
		typedef true_type type;
	};

	template<>
	struct is_integer<signed char>
	{
		enum { value = 1 };
		typedef true_type type;
	};

	template<>
	struct is_integer<unsigned char>
	{
		enum { value = 1 };
		typedef true_type type;
	};

	template<>
	struct is_integer<short>
	{
		enum { value = 1 };
		typedef true_type type;
	};

	template<>
	struct is_integer<unsigned short>
	{
		enum { value = 1 };
		typedef true_type type;
	};

	template<>
	struct is_integer<int>
	{
		enum { value = 1 };
		typedef true_type type;
	};

	template<>
	struct is_integer<unsigned int>
	{
		enum { value = 1 };
		typedef true_type type;
	};

	template<>
	struct is_integer<long>
	{
		enum { value = 1 };
		typedef true_type type;
	};

	template<>
	struct is_integer<unsigned long>
	{
		enum { value = 1 };
		typedef true_type type;
	};

	template<>
	struct is_integer<long long>
	{
		enum { value = 1 };
		typedef true_type type;
	};

	template<>
	struct is_integer<unsigned long long>
	{
		enum { value = 1 };
		typedef true_type type;
	};

	template<typename T>
	struct is_floating
	{
		enum { value = 0 };
		typedef false_type type;
	};

	template<>
	struct is_floating<float>
	{
		enum { value = 1 };
		typedef true_type type;
	};

	template<>
	struct is_floating<double>
	{
		enum { value = 1 };
		typedef true_type type;
	};

	template<>
	struct is_floating<long double>
	{
		enum { value = 1 };
		typedef true_type type;
	};

	template<typename T>
	struct is_pointer
	{
		enum { value = 0 };
		typedef false_type type;
	};

	template<typename T>
	struct is_pointer<T*>
	{
		enum { value = 1 };
		typedef true_type type;
	};

	template<typename T>
	struct is_arithmetic
			: public traitor<is_integer<T>, is_floating<T> >
	{ };

	template<typename T>
	struct is_scalar
			: public traitor<is_arithmetic<T>, is_pointer<T> >
	{ };

	template<typename T>
	struct is_char
	{
		enum { value = 0 };
		typedef false_type type;
	};

	template<>
	struct is_char<char>
	{
		enum { value = 1 };
		typedef true_type type;
	};

	template<typename T>
	struct is_byte
	{
		enum { value = 0 };
		typedef false_type type;
	};

	template<>
	struct is_byte<char>
	{
		enum { value = 1 };
		typedef true_type type;
	};

	template<>
	struct is_byte<signed char>
	{
		enum { value = 1 };
		typedef true_type type;
	};

	template<>
	struct is_byte<unsigned char>
	{
		enum { value = 1 };
		typedef true_type type;
	};

}

#endif //CONTAINERS_TYPETRAITS_HPP
