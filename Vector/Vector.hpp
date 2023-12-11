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
		template<class A>
		friend VectorIterator operator+(A a, const VectorIterator& lhs)
		{return (lhs.ptr + a);}

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
	Vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()
	, typename enable_if<!is_intergral<InputIterator>::value>::type* = 0)
	: v_allocator(alloc)
	{
		std::cout << "iterator constructor" << std::endl;
		if (first > last)
			throw std::length_error("vector");
		v_size = last - first;
		v_capacity = v_size;
		v_first = v_allocator.allocate(v_capacity);
		for (difference_type i = 0; i < static_cast<difference_type>(v_size); i++)
			v_allocator.construct(v_first + i, *(v_first + i));
	}
	
	//copy constructor(overloading operator=)
	Vector (const Vector& x) : v_size(0), v_capacity(0)
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
			v_allocator.construct(v_first + i, obj[i]);
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
	reference at (size_type n)
	{
		if (v_capacity < n)
			throw std::out_of_range("Out of range");
		return (*(v_first + n));
	}
	const_reference at (size_type n) const
	{
		if (v_capacity < n)
			throw std::out_of_range("Out of range");
		return (*(v_first + n));
	}
	reference front() {return (*(v_first));}
	const_reference front() const {return (*(v_first));}
	reference back() {return (*(v_first + v_size - 1));}
	const_reference back() const {return (*(v_first + v_size - 1));}
	T* data()
	{
		if (v_size == 0)
			return (nullptr);
		return (&at(0));
	}
	const T* data() const
	{
		if (v_size == 0)
			return (nullptr);
		return (&at(0));
	}

	//Modifiers
	template <class InputIterator>
	void assign(InputIterator first, InputIterator last,
	 typename enable_if<!is_intergral<InputIterator>::value>::type* = 0)
	{
		if (first > last)
			throw std::length_error("Vector");
		difference_type sub = last - first;
		for (size_type i = 0; i < v_size; i++)
			v_allocator.destroy(v_first + i);
		if (static_cast<difference_type>(v_capacity) < sub)
		{
			v_allocator.deallocate(v_first, v_capacity);
			v_first = v_allocator.allocate(sub);
			v_capacity = sub;
		}
		for (difference_type i = 0; i < sub; i++)
		{
			v_allocator.construct(v_first + i, *first);
			first++;
		}
		v_size = sub;
	}

	void assign(size_type n, const value_type& val)
	{
		for (size_type i = 0; i < v_size; i++)
			v_allocator.destroy(v_first + i);
		if (v_capacity < n)
		{
			v_allocator.deallocate(v_first, v_capacity);
			v_first = v_allocator.allocate(n);
			v_capacity = n;
		}
		for (size_type i = 0; i < n; i++)
			v_allocator.construct(v_first + i, val);
		v_size = n;
	}
	void push_back (const value_type& val)
	{
		if (v_capacity == v_size)
		{
			if (v_capacity == 0)
				reserve(1);
			else
				reserve(v_capacity * 2);
		}
		v_allocator.construct(v_first + v_size, val);
		v_size++;
	}

	void pop_back()
	{
		if (v_size > 0)
		{
			v_allocator.destroy(v_first + v_size - 1);
			v_size--;
		}
	}

	iterator insert(iterator position, const value_type& val)
	{
		if (position < begin() || position > end())
			throw std::length_error("Vector");
		difference_type temp = position - begin();
		if (v_capacity == v_size)
		{
			pointer new_first;
			if (v_capacity == 0)
				new_first = v_allocator.allocate(1);
			else
			{
				new_first = v_allocator.allocate(v_capacity * 2);
				for (size_type i = 0; i < v_size; i++)
				{
					v_allocator.construct(new_first + i, *(v_first + i));
					v_allocator.destroy(v_first + i);
				}
				if (v_capacity)
					v_allocator.deallocate(v_first, v_capacity);
				v_first = new_first;
				v_capacity = v_capacity * 2;
			}
		}
		for (size_type i = v_size; i > static_cast<size_type>(temp); i--)
		{
			v_allocator.destroy(v_first + i);
			v_allocator.construct(v_first + i, *(v_first + i - 1));
		}
		v_allocator.destroy(v_first + temp);
		v_allocator.construct(v_first + temp, val);
		v_size++;
		return (begin() + temp);
	}

    void insert(iterator position, size_type n, const value_type& val)
	{
		if (position < begin() || position > end())
			throw std::length_error("Vector");
		difference_type temp = position - begin();
		if (v_capacity == v_size)
		{
			pointer new_first;
			if (v_capacity == 0)
				new_first = v_allocator.allocate(n);
			else
			{
				if (v_capacity * 2 > n)
					v_capacity = v_capacity * 2;
				new_first = v_allocator.allocate(v_capacity * 2);
				for (size_type i = 0; i < v_size; i++)
				{
					v_allocator.construct(new_first + i, *(v_first + i));
					v_allocator.destroy(v_first + i);
				}
				if (v_capacity)
					v_allocator.deallocate(v_first, v_capacity);
				v_first = new_first;
			}
		}
		for (size_type i = v_size; i > static_cast<size_type>(temp); i--)
		{
			v_allocator.destroy(v_first + i);
			v_allocator.construct(v_first + i + n - 1, *(v_first + i - 1));
		}
		for (size_type i = 0; i < n; i++)
		{
			v_first[i + temp] = val;
			v_size++;
		}
	}

	template <class InputIterator>
	void insert(iterator position, InputIterator first, InputIterator last,
	typename enable_if<!is_intergral<InputIterator>::value>::type* = 0)
	{
		if (position < begin() || position > end() || first > last)
			throw std::length_error("Vector");
		difference_type sub = last - first;
		difference_type temp = position - begin();
		if (v_capacity == v_size)
		{
			pointer new_first;
			if (v_capacity == 0)
				new_first = v_allocator.allocate(static_cast<size_type>(sub));
			else
			{
				if (v_capacity * 2 > static_cast<size_type>(sub))
					v_capacity = v_capacity * 2;
				new_first = v_allocator.allocate(v_capacity * 2);
				for (size_type i = 0; i < v_size; i++)
				{
					v_allocator.construct(new_first + i, *(v_first + i));
					v_allocator.destroy(v_first + i);
				}
				if (v_capacity)
					v_allocator.deallocate(v_first, v_capacity);
				v_first = new_first;
			}
		}
		for (size_type i = v_size; i > static_cast<size_type>(temp); i--)
		{
			v_allocator.destroy(v_first + i);
			v_allocator.construct(v_first + i + static_cast<size_type>(sub) - 1, *(v_first + i - 1));
		}
		for (size_type i = 0; i < static_cast<size_type>(sub); i++)
		{
			v_first[i + temp] = *(first + i);
			v_size++;
		}
	}

	iterator erase(iterator position)
	{
		if (position < begin() || position > end())
			throw std::length_error("Vector");
		// distance -> ptrdiff_t 를 반환( 인자의 거리를 반환해줌)
		size_type sub = static_cast<size_type>(std::distance(begin(), position));
		for (size_type i = sub; i < v_size - 1; i++)
		{
			v_allocator.destroy(v_first + i);
			v_allocator.construct(v_first + i, *(v_first + i + 1));
		}
		v_size--;
		v_allocator.destroy(v_first + v_size - 1);
		return (iterator(v_first + sub));
	}

	iterator erase(iterator first, iterator last)
	{
		if (first > last)
			throw std::length_error("Vector");
		difference_type start = std::distance(begin(), first);
		difference_type sub = std::distance(last, end());
		while(first < last)
		{
			v_allocator.destroy(&(*first));
			first++;
		}
		size_type i = start;
		while (last < end())
		{
			if (v_first + start)
				v_allocator.destroy(v_first + i);
			v_allocator.construct(v_first + i, *last);
			i++;
			last++;
		}
		for (size_type i = start + sub; i < v_size; i++)
			v_allocator.destroy(v_first + i);
		v_size = start + sub;
		if (last == end())
			return (end());
		else
			return (iterator(v_first + start));
	}

	void swap(Vector& x)
	{
		size_type	temp_size = this->v_size;
		size_type	temp_capacity = this->v_capacity;
		pointer		temp_first = this->v_first;

		this->v_size = x.v_size;
		this->v_first = x.v_first;
		this->v_capacity = x.v_capacity;

		x.v_size = temp_size;
		x.v_first = temp_first;
		x.v_capacity = temp_capacity;
	}

	void clear(void)
	{
		for (size_type i = 0; i < v_size; i++)
			v_allocator.destroy(v_first + i);
		v_size = 0;
	}

	//Allocator
	allocator_type get_allocator() const
	{
		return (v_allocator);
	}
};

template <class T, class Alloc>
bool operator==(const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
{
	if (lhs.size() == rhs.size())
	{
		for (size_t i = 0; i < lhs.size(); i++)
		{
			if ((*(lhs.v_first + i)) != (*(lhs.v_first + i)))
				return (false);
		}
	}
	else
		return (false);
	return (true);
}

template <class T, class Alloc>
bool operator!=(const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
{
	return (lhs != rhs);
}

template <class T, class Alloc>
bool operator<(const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
{
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template <class T, class Alloc>
bool operator<= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
{
	return !(lhs > rhs);
}

template <class T, class Alloc>
bool operator>(const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
{
	return (rhs < lhs);
}

template <class T, class Alloc>
bool operator>= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
{
	return !(lhs < rhs);
}

template <class T, class Alloc>
void swap (Vector<T,Alloc>& x, Vector<T,Alloc>& y)
{
	x.swap(y);
}

}
#endif