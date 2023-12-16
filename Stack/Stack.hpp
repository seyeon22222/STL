#ifndef STACK_HPP
# define STACK_HPP


# include "../Deque/Deque.hpp"


namespace ft
{
template <class T, class Container = ft::deque<T> > 
class stack
{
public:
	typedef T				value_type;
	typedef Container		container_type;
	typedef std::size_t		size_type;
protected:
	Container	container;
public:
	explicit stack(const container_type& ctnr = container_type())
	: container(ctnr) {}
	stack(stack const &obj) : container(obj.container) {}

	stack &operator=(const stack& obj)
	{
		if (*this == obj)
			return (*this);
		container = obj.container;
		return (*this);
	}
	
	bool empty() const {return (container.empty());}	
	size_type size() const {return (container.size());}
	value_type& top() {return (container.back());}
	const value_type& top() const {return (container.back());}
	void push (const value_type& val) {return (container.push_back(val));}
	void pop() {return (container.pop_back());}

public:
	template <class C, class cont>
	friend bool operator== (const stack<C,cont>& lhs, const stack<C,cont>& rhs)
	{return (lhs.container == rhs.container);}

	template <class C, class cont>
	friend bool operator!= (const stack<C,cont>& lhs, const stack<C,cont>& rhs)
	{return (lhs.container != rhs.container);}

	template <class C, class cont>
	friend bool operator<  (const stack<C,cont>& lhs, const stack<C,cont>& rhs)
	{return (lhs.container < rhs.container);}

	template <class C, class cont>
	friend bool operator<= (const stack<C,cont>& lhs, const stack<C,cont>& rhs)
	{return (lhs.container <= rhs.container);}

	template <class C, class cont>
	friend bool operator>  (const stack<C,cont>& lhs, const stack<C,cont>& rhs)
	{return (lhs.container > rhs.container);}

	template <class C, class cont>
	friend bool operator>= (const stack<C,cont>& lhs, const stack<C,cont>& rhs)
	{return (lhs.container >= rhs.container);}

};
}

#endif