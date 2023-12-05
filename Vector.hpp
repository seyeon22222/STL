#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <memory>
# include <stdexcept>
# include "Iterator_traits.hpp"
# include "Reverse_iterator.hpp"
# include "Etc_func.hpp"

namespace ft
{
template< class T, class Allocator = std::allocator<T> >
class Vector
{
// Vector Iterator => random_access_iterator
template<typename C>
class VectorIterator
{
	public:
		typedef typename Iterator_traits<C*>::value_type		value_type;
		typedef typename Iterator_traits<C*>::difference_type	difference_type;
		typedef typename Iterator_traits<C*>::pointer			pointer;
		typedef typename Iterator_traits<C*>::reference			reference;
		typedef std::random_access_iterator_tag					iterator_category;
		typedef pointer											iterator_type;
	private:
		pointer	ptr;
	public:
		VectorIterator(void) : ptr(nullptr) {}
		VectorIterator(pointer a) : ptr(a) {}
		virtual ~VectorIterator(void) {}
		VectorIterator(const VectorIterator<typename remove_const<value_type>::type>& obj) : ptr(&(*obj)) {}

		//operator
		VectorIterator<value_type> &operator=(const VectorIterator<typename remove_const<value_type>::type>& obj)
		{
			if (*this == obj)
				return (*this);
			ptr = &(*obj);
			return (*this);
		}

		VectorIterator &operator++()
		{
			++ptr;
			return (*this);
		}

		VectorIterator operator++(int)
		{
			VectorIterator temp(*this);
			++ptr;
			return (temp);
		}

		VectorIterator &operator--()
		{
			--ptr;
			return (*this);
		}

		VectorIterator operator--(int)
		{
			VectorIterator temp(*this);
			--ptr;
			return (temp);
		}

		VectorIterator operator+(const difference_type& a) const {return (ptr + a);}
		VectorIterator operator-(const difference_type& a) const {return (ptr - a);}
		VectorIterator &operator+=(const difference_type& a)
		{
			ptr += a;
			return (*this);
		}

		VectorIterator &operator-=(const difference_type& a) const
		{
			ptr -= a;
			return (*this);
		}
		
		reference operator*() const {return *ptr;}
		pointer operator->() const {return ptr;}
		reference operator[](difference_type n) const {return *(ptr + n);}

	public:
		template<typename A, typename B>
		friend bool operator==(const VectorIterator<A>& lhs, const VectorIterator<B>& rhs)
		{ return (&(*lhs)) == &(*rhs); }

		template<typename A, typename B>
		friend bool operator!=(const VectorIterator<A>& lhs, const VectorIterator<B>& rhs)
		{ return (&(*lhs)) != &(*rhs); }

		template<typename A, typename B>
		friend bool operator<(const VectorIterator<A>& lhs, const VectorIterator<B>& rhs)
		{ return (&(*lhs)) < &(*rhs); }

		template<typename A, typename B>
		friend bool operator<=(const VectorIterator<A>& lhs, const VectorIterator<B>& rhs)
		{ return (&(*lhs)) <= &(*rhs); }

		template<typename A, typename B>
		friend bool operator>(const VectorIterator<A>& lhs, const VectorIterator<B>& rhs)
		{ return (&(*lhs)) > &(*rhs); }

		template<typename A, typename B>
		friend bool operator>=(const VectorIterator<A>& lhs, const VectorIterator<B>& rhs)
		{ return (&(*lhs)) >= &(*rhs); }

		template<typename A, typename B>
		friend difference_type operator+(const VectorIterator<A>& lhs, const VectorIterator<B>& rhs)
		{ return (&(*lhs)) + &(*rhs); }

		template<typename A, typename B>
		friend difference_type operator-(const VectorIterator<A>& lhs, const VectorIterator<B>& rhs)
		{ return (&(*lhs)) - &(*rhs); }

		template<typename A>
		friend VectorIterator<A> operator+(typename VectorIterator<A>::differnce_type &lhs, typename VectorIterator<A>::differnce_type &rhs)
		{ return (lhs + rhs);}

		template<typename A>
		friend VectorIterator<A> operator-(typename VectorIterator<A>::differnce_type &lhs, typename VectorIterator<A>::differnce_type &rhs)
		{ return (lhs - rhs);}
};

public:
	typedef T									value_type;
	typedef Allocator							allocator_type;
	typedef std::size_t							size_type;
	typedef std::ptrdiff_t						difference_type;
	typedef value_type&							reference;
	typedef const value_type&					const_reference;
	typedef typename Allocator::pointer			pointer;
	typedef typename Allocator::const_pointer	const_pointer;
	typedef VectorIterator<value_type>			iterator;
	typedef VectorIterator<const value_type>	const_iterator;
	typedef Reverse_iterator<iterator>			reverse_iterator;
	typedef Reverse_iterator<const iterator>	const_reverse_iterator;
private:
	pointer			v_first;
	size_type		v_size, v_capacity;
	allocator_type	v_allocator;
public:
	// default
	explicit Vector(const allocator_type& alloc = allocator_type())
	: v_first(nullptr), v_size(0), v_capacity(0), v_allocator(alloc) {};

	// fill constructor
	explicit Vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
	 : v_size(n), v_capacity(n), v_allocator(alloc)
	{
		v_first = v_allocator.allocate(n);
		for (size_type i = 0; i < n; i++)
			v_allocator.construct(v_first + i, val);
	}

	// range constructor
	template <class InputIterator>
	Vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename enable_if<!is_intergral<InputIterator>::value>::type* = 0)
	: v_allocator(alloc)
	{
		if (first > last)
			throw std::length_error("vector");
		v_size = last - first;
		v_capacity = v_size;
		v_first = v_allocator.allocate(v_capacity);
		for (difference_type i = 0; i < static_cast<difference_type>(v_size); i++)
			v_allocator.construct(v_first + i, *(first + i));
	}
	
	//copy constructor(overloading operator=)
	Vector(const Vector& x) : v_size(0), v_capacity(0)
	{
		*this = x;
	}

	Vector &operator=(const Vector& obj)
	{
		if (this == &obj)
			return (*this);
		for (size_type i = 0; i < v_size; i++)
			v_allocator.destroy(v_first + i);
		v_size = obj.v_size;
		if (v_capacity < v_size)
		{
			if (v_capacity != 0)
				v_allocator.deallocate(v_first, v_capacity);
			v_capacity = v_size;
			v_first = v_allocator.allocate(v_capacity);
		}
		for (size_type i = 0; i < v_size; i++)
			v_allocator.allocate(v_first + i, obj[i]);
		return (*this);
	}

	//Vector desturctor 
	~Vector(void)
	{
		for(size_type i = 0; i < v_size; i++)
			v_allocator.destroy(v_first + i);
		if (v_capacity)
			v_allocator.deallocate(v_first, v_capacity);
	}

	//Iterator
	iterator begin(void) {return (iterator(v_first));}
	const_iterator begin(void) const {return (const_iterator(v_first));}
	iterator end(void) {return (iterator(v_first + v_size));}
	const_iterator end(void) const {return (const_iterator(v_first + v_size));}
	reverse_iterator rbegin(void) {return (reverse_iterator(end()));}
	const_reverse_iterator rbegin(void) const {return (const_reverse_iterator(end()));}
	reverse_iterator rend(void) {return (reverse_iterator(begin()));}
	const_reverse_iterator rend(void) const {return (const_reverse_iterator(begin()));}

	//Capacity
	size_type size(void) const {return (v_size);}
	size_type max_size(void) const {return (v_allocator.max_size());}
	size_type capacity() const {return (v_capacity);}
	bool empty() const {return (v_size == 0);}
	void reserve (size_type n)
	{
		if (v_capacity > n)
			return ;
		pointer	temp = v_allocator.allocate(n);
		try
		{
			for (size_type i = 0; i < v_size; i++)
				v_allocator.construct(temp + i, *(v_first + i));
		}
		catch (std::exception &e)
		{
			size_type i = 0;
			while (temp + i != NULL && i < v_size)
			{
				v_allocator.destroy(temp + i);
				i++;
			}
			v_allocator.deallocate(temp, n);
			throw;
		}
		for (size_type i = 0; i < v_size; i++)
			v_allocator.destroy(v_first + i);
		if (v_capacity)
			v_allocator.deallocate(v_first, v_capacity);
		v_capacity = n;
		v_first = temp;
	}

	void resize(size_type n, value_type val = value_type())
	{
		if (v_size > n)
		{
			for (size_type i = n; i < v_size; i++)
				v_allocator.destroy(v_first + i);
			v_size = n;
		}
		else if (v_size < n)
		{
			if (v_capacity * 2 > n)
				reserve(v_capacity * 2);
			else
				reserve(n);
			for (size_type i = v_size; i < n; i++)
			{
				v_allocator.construct(v_first + i, val);
				v_size++;
			}
		}	
	}
	
	void shrink_to_fit()
	{
		if (v_capacity > v_size)
		{
			pointer temp = v_allocator.allocate(v_size);
			for (size_type i = 0; i < v_size; i++)
				v_allocator.construct(temp + i, *(v_first + i));
			for (size_type i = 0; i < v_size; i++)
				v_allocator.destroy(v_first + i);
			v_allocator.deallocate(v_first, v_capacity);
			v_first = temp;
			v_capacity = v_size;
		}
	}

	//Element Access
	reference operator[](size_type n) {return *(v_first + n);}
	const_reference operator[](size_type n) const {return *(v_first + n);}

};
}

#endif