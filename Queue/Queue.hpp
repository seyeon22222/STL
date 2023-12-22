#ifndef QUEUE_HPP
# define QUEUE_HPP

# include "../Deque/Deque.hpp"

namespace ft
{
template <class T, class Container = ft::deque<T> >
class queue
{
public:
    typedef T           value_type;
    typedef Container   container_type;
    typedef std::size_t size_type;
protected:
    container_type   q_container;
public:
    explicit queue (const container_type& ctnr = container_type()) : q_container(ctnr) {}

    queue (const queue& obj)
    {
        *this = obj;
    }

    queue &operator=(const queue& obj)
    {
        if (*this == obj)
            return (*this);
        q_container = obj.q_container;
        return (*this);
    }
    bool empty() const {return (q_container.empty());}
    size_type size() const {return (q_container.size());}
    value_type& front() {return (q_container.front());}
    const value_type& front() const {return (q_container.front());}
    value_type& back() {return (q_container.back());}
    const value_type& back() const {return (q_container.back());}
    void push (const value_type& val) {return (q_container.push_back());}
    void pop() {return (q_container.pop_front());}
public:
template <class T, class Container>
friend bool operator== (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
{return (lhs.q_container == rhs.q_container);}

template <class T, class Container>
friend bool operator!= (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
{return (lhs.q_container != rhs.q_container);}

template <class T, class Container>
friend bool operator<  (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
{return (lhs.q_container < rhs.q_container);}

template <class T, class Container>
friend bool operator<= (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
{return (lhs.q_container <= rhs.q_container);}

template <class T, class Container>
friend bool operator>  (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
{return (lhs.q_container > rhs.q_container);}

template <class T, class Container>
friend bool operator>= (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
{return (lhs.q_container >= rhs.q_container);}
};
}


#endif