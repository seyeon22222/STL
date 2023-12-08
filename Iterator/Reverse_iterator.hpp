#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "Iterator_traits.hpp"

namespace ft
{
template<class Iter>
class Reverse_iterator
{
public:
	typedef Iter												iterator_type;
	typedef typename Iterator_traits<Iter>::iterator_category	iterator_category;
	typedef typename Iterator_traits<Iter>::value_type			value_type;
	typedef typename Iterator_traits<Iter>::difference_type		difference_type;
	typedef typename Iterator_traits<Iter>::pointer				pointer;
	typedef typename Iterator_traits<Iter>::reference			reference;
protected:
	iterator_type	base_iterator;
public:
	Reverse_iterator() : base_iterator() {}

	explicit Reverse_iterator( iterator_type x ) : base_iterator(x) {}

	template< class U >
	Reverse_iterator( const Reverse_iterator<U>& other )
	{
		base_iterator = other.base_iterator;
	}

	template< class U >
	Reverse_iterator& operator=( const Reverse_iterator<U>& other )
	{
		if (*this == other)
			return (*this);
		base_iterator = other.base_iterator;
	}

	Reverse_iterator base(void) const {return (base_iterator);}

	reference operator*() const
	{
		iterator_type	temp = base_iterator;
		return (*--temp);
	}

	pointer operator->() const {return &(operator*());}
	
	Reverse_iterator operator[](difference_type n) const {return (base_iterator[-n-1]);}
	Reverse_iterator operator++()
	{
		--base_iterator;
		return (*this);
	}

	Reverse_iterator operator++(int)
	{
		Reverse_iterator temp = *this;
		++(*this);
		return (temp);
	}

	Reverse_iterator operator--()
	{
		++base_iterator;
		return (*this);
	}
	Reverse_iterator operator--(int)
	{
		Reverse_iterator temp = *this;
		--(*this);
		return (temp);
	}

	Reverse_iterator operator+(difference_type n)
	{
		return (Reverse_iterator(base_iterator - n));
	}

	Reverse_iterator operator-(difference_type n)
	{
		return (Reverse_iterator(base_iterator + n));
	}

	Reverse_iterator operator+=(difference_type n)
	{
		base_iterator -= n;
		return (*this);
	}
	
	Reverse_iterator operator-=(difference_type n)
	{
		base_iterator += n;
		return (*this);
	}
};

template<class Iter1, class Iter2>
bool operator==(const Reverse_iterator<Iter1>&lhs, 
const Reverse_iterator<Iter2>& rhs)
{
	return (lhs.base() == rhs.base());
}

template<class Iter1, class Iter2>
bool operator!=(const Reverse_iterator<Iter1>&lhs, 
const Reverse_iterator<Iter2>& rhs)
{
	return (lhs.base() != rhs.base());
}

template<class Iter1, class Iter2>
bool operator<(const Reverse_iterator<Iter1>&lhs, 
const Reverse_iterator<Iter2>& rhs)
{
	return (lhs.base() < rhs.base());
}

template<class Iter1, class Iter2>
bool operator<=(const Reverse_iterator<Iter1>&lhs, 
const Reverse_iterator<Iter2>& rhs)
{
	return (lhs.base() <= rhs.base());
}

template<class Iter1, class Iter2>
bool operator>(const Reverse_iterator<Iter1>&lhs, 
const Reverse_iterator<Iter2>& rhs)
{
	return (lhs.base() > rhs.base());
}

template<class Iter1, class Iter2>
bool operator>=(const Reverse_iterator<Iter1>&lhs, 
const Reverse_iterator<Iter2>& rhs)
{
	return (lhs.base() >= rhs.base());
}

template<class Iter>
Reverse_iterator<Iter>	operator+(typename Reverse_iterator<Iter>::difference_type n, 
const Reverse_iterator<Iter>& it)
{
	return (it + n);
}

template <class Iter>
typename Reverse_iterator<Iter>::difference_type 
operator-(const Reverse_iterator<Iter>& lhs, const Reverse_iterator<Iter>& rhs)
{
	return (lhs.base() - rhs.base());
}
};

#endif