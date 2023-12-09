#ifndef ETC_FUNC_HPP
# define ETC_FUNC_HPP

# include <iostream>

namespace ft
{
template<bool Cond, class T = void>
struct enable_if {};

template<class T> struct remove_const {typedef T type;};
template<class T> struct remove_const<const T> {typedef T type;};


template<class T>
struct enable_if<true, T> {typedef T type;};

template <class T, bool v>
struct integral_constant
{
	static const bool value = v;
	typedef T	value_type;
	typedef integral_constant type;
	operator value_type() const {return value;}
};

template<class T>struct is_intergral					: public integral_constant<T, false> {};
template<>struct is_intergral<bool> 					: public integral_constant<bool, true> {};
template<>struct is_intergral<char> 					: public integral_constant<char, true> {};
template<>struct is_intergral<signed char> 				: public integral_constant<signed char, true> {};
template<>struct is_intergral<unsigned char>			: public integral_constant<unsigned char, true> {};
template<>struct is_intergral<wchar_t> 					: public integral_constant<wchar_t, true> {};
template<>struct is_intergral<short int> 				: public integral_constant<short int, true> {};
template<>struct is_intergral<int> 						: public integral_constant<int, true> {};
template<>struct is_intergral<long int> 				: public integral_constant<long int, true> {};
template<>struct is_intergral<long long int> 			: public integral_constant<long long int, true> {};
template<>struct is_intergral<unsigned int>				: public integral_constant<unsigned int, true> {};
template<>struct is_intergral<unsigned long int> 		: public integral_constant<unsigned long int, true> {};
template<>struct is_intergral<unsigned long long int> 	: public integral_constant<unsigned long long int, true> {};

template<class InputIt1, class InputIt2>
bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2)
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

template<class InputIt1, class InputIt2, class BinaryPredicate>
bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate p)
{
	while (first1 != last1)
	{
		if (!p(*first1, *first2))
			return (false);
		++first1;
		++first2;
	}
	return (true);
}

template<class InputIt1, class InputIt2>
bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2)
{
	for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2)
	{
		if (*first1 < *first2)
			return (true);
		if (*first2 < *first1)
			return (false);
	}
    return ((first1 == last1) && (first2 != last2));
}

template<class InputIt1, class InputIt2, class Compare>
bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp)
{
	for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2)
	{
		if (comp(*first1, *first2))
			return (true);
		if (comp(*first2, *first1))
			return (false);
	}
    return ((first1 == last1) && (first2 != last2));
}

template<class T1, class T2>
struct pair
{
	typedef T1	first_type;
	typedef T2	second_type;

	first_type first;
	second_type	second;
	pair() : first(), second() {};
	template<class U, class V> pair(const pair<U,V>& pr) : first(pr.first), second(pr.second) {};
	pair(const first_type& a, const second_type& b) : first(a.first), second(b.second) {};
	pair& operator=(const pair& pr)
	{
		if (*this == pr)
			return (*this);
		this->first = pr.first;
		this->second = pr.second;
		return (*this);
	}
};

template <class T1, class T2>
pair<T1,T2> make_pair(T1 x, T2 y)
{
	return (pair<T1, T2>(x, y));
}

template <class T1, class T2>
bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{
	return (lhs.first == rhs.first && lhs.second == rhs.second);
}

template <class T1, class T2>
bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{
	return (!(lhs == rhs));
}

template <class T1, class T2>
bool operator< (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{
	return (lhs.first < rhs.first || (!(rhs.first < lhs.first)
	&& lhs.second<rhs.second));
}

template <class T1, class T2>
bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{
	return (!(rhs < lhs));
}

template <class T1, class T2>
bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{
	return (rhs < lhs);
}

template <class T1, class T2>
bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{
	return (!(lhs < rhs));
}

template<typename T>
class Node
{
private:
	T 		data;
	Node<T>	*next;
	Node<T>	*prev;
public:
	Node(void) : next(nullptr), data(), prev(nullptr) {}
	Node(T const &_data) : next(nullptr), data(_data), prev(nullptr) {}
	Node(Node *_prev, T const& _data, Node *_next=nullptr) :
	 prev(_prev), data(_data), next(_next) {}
	virtual ~Node(void);
	Node Node(const Node& obj) {*this = obj;}
	Node &operator=(const Node& obj)
	{
		if (*this == obj)
			return (*this);
		this->prev = obj.prev;
		this->data = obj.data;
		this->next = obj.next;
		return (*this);
	}
};


}

#endif