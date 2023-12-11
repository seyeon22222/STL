#ifndef DEQUE_HPP
# define DEQUE_HPP

# include <iostream>
# include <memory>
# include <stdexcept>
# include "../Iterator/Reverse_iterator.hpp"
# include "../Util/Etc_func.hpp"

namespace ft
{
template <class C>
class DequeIterator
{
public:
	typedef typename Iterator_traits<C*>::value_type		value_type;
	typedef typename Iterator_traits<C*>::difference_type	difference_type;
	typedef typename Iterator_traits<C*>::pointer			pointer;
	typedef typename Iterator_traits<C*>::reference			reference;
	typedef std::random_access_iterator_tag					iterator_category;
	typedef pointer											iterator_type;
private:
	pointer	*ptr;
public:
	DequeIterator(void) : ptr(nullptr) {}
	DequeIterator(pointer *a) : ptr(a) {}
	virtual ~DequeIterator(void) {}
	DequeIterator(const DequeIterator<typename ft::remove_const<value_type>::type>& obj)
	{
		ptr = obj.getPtr();
	}
	pointer* getPtr(void) const {return (ptr);}
	DequeIterator &operator++()
	{
		++this->ptr;
		return (*this);
	}

	DequeIterator operator++(int)
	{
		DequeIterator temp(*this);
		++this->ptr;
		return (temp);
	}

	DequeIterator &operator--()
	{
		--this->ptr;
		return (*this);
	}

	DequeIterator operator--(int)
	{
		DequeIterator temp(*this);
		--this->ptr;
		return (temp);
	}

	DequeIterator operator+(const difference_type& a) const {return (ptr + a);}
	DequeIterator operator-(const difference_type& a) const {return (ptr - a);}
	DequeIterator &operator+=(const difference_type& a)
	{
		this->ptr += a;
		return (*this);
	}

	DequeIterator &operator-=(const difference_type& a) const
	{
		this->ptr -= a;
		return (*this);
	}
	
	reference operator*() const {return **this->ptr;}
	pointer operator->() const {return *this->ptr;}
	reference operator[](difference_type n) const {return **(this->ptr + n);}
	public:
		template<typename A, typename B>
		friend bool operator==(const DequeIterator<A>& lhs, const DequeIterator<B>& rhs)
		{ return (&(*lhs)) == &(*rhs); }

		template<typename A, typename B>
		friend bool operator!=(const DequeIterator<A>& lhs, const DequeIterator<B>& rhs)
		{ return (&(*lhs)) != &(*rhs); }

		template<typename A, typename B>
		friend bool operator<(const DequeIterator<A>& lhs, const DequeIterator<B>& rhs)
		{ return (&(*lhs)) < &(*rhs); }

		template<typename A, typename B>
		friend bool operator<=(const DequeIterator<A>& lhs, const DequeIterator<B>& rhs)
		{ return (&(*lhs)) <= &(*rhs); }

		template<typename A, typename B>
		friend bool operator>(const DequeIterator<A>& lhs, const DequeIterator<B>& rhs)
		{ return (&(*lhs)) > &(*rhs); }

		template<typename A, typename B>
		friend bool operator>=(const DequeIterator<A>& lhs, const DequeIterator<B>& rhs)
		{ return (&(*lhs)) >= &(*rhs); }

		template<typename A, typename B>
		friend difference_type operator+(const DequeIterator<A>& lhs, const DequeIterator<B>& rhs)
		{ return (&(*lhs)) + &(*rhs); }

		template<typename A, typename B>
		friend difference_type operator-(const DequeIterator<A>& lhs, const DequeIterator<B>& rhs)
		{ return (&(*lhs)) - &(*rhs); }

		template<typename A>
		friend DequeIterator<A> operator+(typename DequeIterator<A>::differnce_type &lhs, typename DequeIterator<A>::differnce_type &rhs)
		{ return (lhs + rhs);}

		template<typename A>
		friend DequeIterator<A> operator-(typename DequeIterator<A>::differnce_type &lhs, typename DequeIterator<A>::differnce_type &rhs)
		{ return (lhs - rhs);}
};


template < class T, class Alloc = std::allocator<T> >
class Deque
{
public:
	typedef T									value_type;
	typedef Alloc								allocator_type;
	typedef value_type&							reference;
	typedef const value_type&					const_reference;
	typedef typename Alloc::pointer				pointer;
	typedef typename Alloc::const_pointer		const_pointer;
	typedef DequeIterator<value_type>			iterator;
	typedef DequeIterator<const value_type>		const_iterator;
	typedef Reverse_iterator<iterator>			reverse_iterator;
	typedef Reverse_iterator<const iterator>	const_reverse_iterator;
	typedef std::ptrdiff_t						difference_type;
	typedef std::size_t							size_type;
private:
	pointer			*dq_first;
	size_type		dq_offset;
	size_type		dq_size;
	size_type		dq_capacity;
	allocator_type	dq_allocator;

	void reserve(size_type n)
	{
		size_type	temp = 0;
		if (n > dq_capacity)
		{
			if (dq_capacity > 32)
				temp = dq_capacity * 2;
			else
				temp = 32;
			pointer *arr = static_cast<pointer*>(::operator new(sizeof(pointer*) * temp));
			size_type temp_offset = (temp / 2) - (dq_size / 2);
			for (size_type i = temp_offset, j = dq_offset; j < dq_offset + dq_size; i++, j++)
				arr[i] = dq_first[j];
			::operator delete(dq_first);
			dq_first = arr;
			dq_capacity = temp;
			dq_offset = temp_offset;
		}
	}


public:
	explicit Deque (const allocator_type& alloc = allocator_type())
	: dq_first(nullptr), dq_offset(0), dq_size(0), dq_capacity(0), dq_allocator(alloc) {}

	explicit Deque (size_type n, const value_type& val = value_type(),
	 const allocator_type& alloc = allocator_type())
	: dq_first(nullptr), dq_offset(0), dq_size(0), dq_capacity(0), dq_allocator(alloc)
	{
		this->assign(n, val);
	}

	template <class InputIterator>
	Deque (InputIterator first, InputIterator last,
	 const allocator_type& alloc = allocator_type(),
	typename enable_if<!is_intergral<InputIterator>::value>::type* = 0)
	: dq_first(nullptr), dq_offset(0), dq_size(0), dq_capacity(0), dq_allocator(alloc)
	{
		this->assign(first, last);
	}

	Deque (const Deque& x) : dq_first(nullptr), dq_offset(0), dq_size(0), dq_capacity(0)
	{
		this->assign(x.begin(), x.end());
	}

	Deque &operator=(const Deque &x)
	{
		this->assign(x.begin(), x.end());
	}

	virtual ~Deque() 
	{
		this->clear();
		::operator delete(dq_first);
	}


	size_type getOffset() {return (dq_offset);}
	//Iterators
	iterator begin() {return (iterator(this->dq_first + this->dq_offset));}
	const_iterator begin() const {return (const_iterator(dq_first + dq_offset));}
	iterator end() {return (iterator(dq_first + dq_offset + dq_size));}
	const_iterator end() const {return (const_iterator(dq_first + dq_offset + dq_size));}
	reverse_iterator rbegin() {return (reverse_iterator(end()));}
	const_reverse_iterator rbegin() const {return (const_reverse_iterator(end()));}
	reverse_iterator rend() {return (reverse_iterator(begin()));}
	const_reverse_iterator rend() const {return (const_reverse_iterator(begin()));}

	//Capacity
	size_type size() const {return (dq_size);}
	size_type capacity() const {return (dq_capacity);}
	size_type max_size() const {return (dq_allocator.max_size());}
	bool empty() const {return (dq_size == 0);}

	void resize (size_type n, value_type val = value_type())
	{
		if (n > dq_size)
			insert(end(), n - dq_size, val);
		else if (n < dq_size)
		{
			for (size_type i = n; i < dq_size; i++)
				delete dq_first[dq_offset + i];
			dq_size = n;
		}
	}

	void shrink_to_fit()
	{
		if (dq_capacity > dq_size)
		{
			for (size_type i = dq_size; i < dq_capacity; i++)
				delete dq_first[dq_offset + i];
			dq_capacity = dq_size;
		}
	}

	//Element Access
	reference operator[](size_type n) {return (*this->dq_first[dq_offset + n]);}
	const_reference operator[](size_type n) const {return (*this->dq_first[dq_offset + n]);}

	reference at (size_type n)
	{
		if (dq_size < n)
			throw std::out_of_range("Out of range");
		return (*(dq_first[dq_offset + n]));
	}

	const_reference at (size_type n) const
	{
		if (dq_size < n)
			throw std::out_of_range("Out of range");
		return (*(dq_first[dq_offset + n]));
	}


	reference front() {return (this->operator[](0));}
	const_reference front() const {return (this->operator[](0));}
	reference back() {return (this->operator[](dq_size - 1));}
	const_reference back() const {return (this->operator[](dq_size - 1));}

	//Modifiers
	template <class InputIterator>
	void assign(InputIterator first, InputIterator last,
	typename enable_if<!is_intergral<InputIterator>::value>::type* = 0) 
	{
		if (first > last)
			throw std::length_error("Deque");
		this->clear();
		size_type sub = last - first;
		if (dq_capacity < sub)
			reserve(sub);
		dq_offset = (dq_capacity / 2) - ((dq_capacity - sub) / 2);
		while (first != last) 
		{
			dq_first[dq_offset + dq_size++] = new value_type(*first);
			first++;
		}
	}

    void assign(size_type n, const_reference val)
	{
		this->clear();
		if (dq_capacity < n)
			reserve(n);
		dq_offset = (dq_capacity / 2) - ((dq_capacity - n) / 2);
		for (; dq_size < n; dq_size++)
			dq_first[dq_offset + dq_size] = new value_type(val);
	}

	void push_back (const value_type& val)
	{
		if (dq_offset + dq_size == dq_capacity)
			reserve(dq_capacity * 2);
		dq_first[dq_offset + dq_size] = new value_type(val);
		dq_size++;
	}

	void push_front (const value_type& val)
	{
		if (dq_offset == 0)
			reserve(dq_capacity + 1);
		this->dq_first[dq_offset - 1] = new value_type(val);
		dq_size++;
		dq_offset--;
	}

	void pop_back()
	{
		delete dq_first[dq_offset + dq_size - 1];
		dq_size--;
	}

	void pop_front()
	{
		delete dq_first[dq_offset];
		dq_offset++;
		dq_size--;
	}

	void insert (iterator position, size_type n, const value_type& val)
	{
		if (position < begin() || position > end())
			throw std::length_error("Deque");
		if (n == 0)
			return ;
		if (dq_capacity == dq_size)
			reserve(dq_capacity * 2);
		size_type i = position.getPtr() - dq_first - dq_offset;
		size_type index = dq_offset + i;
		for (size_type j = 0; j < n; j++)
		{
			dq_first[index + j - 1] = new value_type(val);
			dq_size++;
			dq_offset--;
		}
	}

	iterator insert (iterator position, const value_type& val)
	{
		if (position < begin() || position > end())
			throw std::length_error("Deque");
		if (dq_capacity == dq_size)
			reserve(dq_capacity * 2);
		size_type i = position.getPtr() - dq_first - dq_offset;
		insert(position, 1, val);
		return (dq_first + dq_offset + i);
	}

	template <class InputIterator>
	void insert (iterator position, InputIterator first, InputIterator last
	, typename enable_if<!is_intergral<InputIterator>::value>::type* = 0)
	{
		if (position < begin() || position > end() || first > last)
			throw std::length_error("Deque");
		if (dq_capacity == dq_size)
			reserve(dq_capacity * 2);
		size_type index = position.getPtr() - dq_first - dq_offset;
		size_type sub = last - first;
		for (size_type i = 0; i < sub; i++)
		{
			dq_first[index + i] = new value_type(*first);
			first++;
			dq_size++;
		}
	}

	iterator erase (iterator position)
	{
		std::cout << &position << std::endl;
		std::cout << (dq_first + dq_offset) << std::endl;
		if (position < begin() || position > end())
			throw std::length_error("Deque");
		iterator temp(position);
		++temp;
		return (erase(position, temp));
	}

	iterator erase (iterator first, iterator last)
	{
		// if (first > last)
		// 	throw std::length_error("Deque");
		size_type sub = last - first;
		std::cout << sub << std::endl;
		size_type start_index = first.getPtr() - dq_first;
		size_type end_index = last.getPtr() - dq_first;
		for (size_type i = 0; i < 32; i++)
			std::cout << dq_first[i] << std::endl;
		std::cout << "---------------\n";
		for (size_type i = 0; i < sub; i++)
		{
			std::cout << &dq_first[start_index + i] << std::endl;
			delete this->dq_first[start_index + i];
			dq_size--;
		}
		for (size_type i = dq_offset + dq_size, j = 0; i > end_index; i--, j++ )
			dq_first[start_index + j] = dq_first[i - 1];
		return (end());
	}

	void swap (Deque& x)
	{
		size_type temp_size = dq_size;
		size_type temp_capacity = dq_capacity;
		size_type temp_offset = dq_offset;
		pointer *temp = dq_first;

		dq_size = x.dq_size;
		dq_capacity = x.dq_capacity;
		dq_offset = x.dq_offset;
		dq_first = x.dq_first;

		x.dq_size = temp_size;
		x.dq_capacity = temp_capacity;
		x.dq_offset = temp_offset;
		x.dq_first = temp;
	}

	void clear()
	{
		for (size_type i = 0; i < this->dq_size; ++i)
			delete dq_first[this->dq_offset + i];
		this->dq_offset = this->dq_capacity / 2;
		this->dq_size = 0;
	}

	//Allocator
	allocator_type get_allocator() const {return (dq_allocator);}

};

template <class T, class Alloc>
bool operator== (const Deque<T,Alloc>& lhs, const Deque<T,Alloc>& rhs)
{
	if (lhs.size() == rhs.size())
	{
		for (size_t i = 0; i < lhs.size(); i++)
		{
			if (lhs[i] != rhs[i])
				return (false);
		}
	}
	else
		return (false);
	return (true);
}

template <class T, class Alloc>
bool operator!= (const Deque<T,Alloc>& lhs, const Deque<T,Alloc>& rhs)
{return !(lhs == rhs);}

template <class T, class Alloc>
bool operator<  (const Deque<T,Alloc>& lhs, const Deque<T,Alloc>& rhs)
{return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));}

template <class T, class Alloc>
bool operator<= (const Deque<T,Alloc>& lhs, const Deque<T,Alloc>& rhs)
{return (!(rhs < lhs));}

template <class T, class Alloc>
bool operator>  (const Deque<T,Alloc>& lhs, const Deque<T,Alloc>& rhs)
{return (rhs < lhs);}

template <class T, class Alloc>
bool operator>= (const Deque<T,Alloc>& lhs, const Deque<T,Alloc>& rhs)
{return (!(lhs < rhs));}

template <class T, class Alloc>
void swap (Deque<T,Alloc>& x, Deque<T,Alloc>& y) 
{
	x.swap(y);
}

}

#endif