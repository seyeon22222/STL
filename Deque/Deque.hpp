#ifndef DEQUE_HPP
# define DEQYE_HPP

# include <iostream>
# include <memory>
# include <stdexcept>
# include "../Iterator/Reverse_iterator.hpp"
# include "../Vector/Vector.hpp"

namespace ft
{
template < class T, class Alloc = std::allocator<T> >
class Deque
{
public:
	typedef T									value_type;
	typedef Alloc								allocator_type;
	typedef value_type&							reference;
	typedef const value_type&					const_reference;
	typedef typename Alloc::pointer				pointer;
	typedef typename Alloc::cosnt_pointer		const_pointer;
	typedef VectorIterator<value_type>			iterator;
	typedef VectorIterator<const value_type>	const_iterator;
	typedef Reverse_iteartor<iterator>			reverse_iterator;
	typedef Reverse_iterator<const iterator>	const_reverse_iterator;
	typedef std::ptrdiff_t						difference_type;
	typedef std::size_t							size_type;
private:
	pointer			v_first;
	size_type		v_link;
	size_type		v_size;
	size_type		v_capacity;
	allocator_type	v_allocator;
public:
	explicit Deque (const allocator_type& alloc = allocator_type())
	: v_head(nullptr), v_tail(nullptr), v_size(0), v_link(0) {}

	explicit Deque (size_type n, const value_type& val = value_type(),
	 const allocator_type& alloc = allocator_type())
	{
		v_first = v_allocator.allocate(n);
		for (size_type i = 0; i < n; i++)
		{
			v_allocator.construct(v_first + i, val);
		}
		v_size = n;
		v_capacity = n;
		v_link = 0;
	}

	template <class InputIterator>
	Deque (InputIterator first, InputIterator last,
	 const allocator_type& alloc = allocator_type(),
	typename enable_if<!is_intergral<InputIterator>::value>::type* = 0)
	{
		if (first > last)
			throw std::length_error("Deque");
		difference_type sub = last - first;
		v_first = v_allocator.allocate(static_cast<size_type>(sub));
		for (difference_type i = 0; i < sub; i++)
		{
			v_allocator.constrcut(v_first + i, *(first + i));
			v_size++;
		}
		v_capacity = v_size;
		v_link = 0;

	}

	Deque (const Deque& x)
	{
		*this = x;
	}

	Deque &operator=(const Deque &obj)
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
			v_allocator.construct(v_first + i, obj[i]);
		v_link = 0;
		return (*this);
	}

	virtual ~Deque() 
	{
		for(size_type i = 0; i < v_size; i++)
			v_allocator.destroy(v_first + i);
		if (v_capacity)
			v_allocator.deallocate(v_first, v_capacity);
		if (v_link != 0)
		{

		}
	}

};
}



#endif