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
class deque
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
	pointer			v_head;
	pointer			v_tail;
	size_type		v_size;
	allocator_type	v_allocator;
public:
	explicit deque (const allocator_type& alloc = allocator_type())
	: v_head(nullptr), v_tail(nullptr), v_size(0) {}

	explicit deque (size_type n, const value_type& val = value_type(),
	 const allocator_type& alloc = allocator_type())
	{
		v_head =
	}

	template <class InputIterator>
	deque (InputIterator first, InputIterator last,
	 const allocator_type& alloc = allocator_type())
	{

	}

	deque (const deque& x)
	{

	}

};
}



#endif