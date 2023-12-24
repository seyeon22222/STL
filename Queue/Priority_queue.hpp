#ifndef PRIORITY_QUEUE_HPP
# define PRIORITY_QUEUE_HPP

# include "../Vector/Vector.hpp"
# include "../Util/Algorithm.hpp"

namespace ft
{
template <class T, class Container = ft::vector<T>,  class Compare = ft::less<typename Container::value_type> > 
class priority_queue
{
public:
    typedef Container                                   container_type;
    typedef typename container_type::value_type         value_type;
    typedef typename container_type::reference          reference;
    typedef typename container_type::const_reference    const_reference;
    typedef typename container_type::size_type          size_type;

protected:
    container_type  pq_container;
    Compare         comp;
public:
    explicit priority_queue (const Compare& comp = Compare(), const Container& ctnr = Container())
    : pq_container(), comp() 
    {
        std::make_heap(pq_container.begin(), pq_container.end(), comp);
    }

    template <class InputIterator>
    priority_queue (InputIterator first, InputIterator last, 
    const Compare& comp = Compare(), const Container& ctnr = Container(),
    typename enable_if<!is_intergral<InputIterator>::value>::type* = 0)
    {
        std::make_heap(first, last, comp);
    }

    priority_queue (const priority_queue& obj)
    {
        *this = obj;
    }

    priority_queue &operator=(const priority_queue& obj)
    {
        if (*this == obj)
            return (*this);
        pq_container = obj.pq_container;
        comp = obj.comp;
        return (*this);
    }

    bool empty() const {return (pq_container.empty());}
    size_type size() const {return (pq_container.size());}
    const value_type& top() const {return (pq_container.top());}

    // 얘네는 따로 comp에 따라서 정렬을 해서 넣어줘야함
    void push (const value_type& val)
    {return (std::push_heap(pq_container.begin(), pq_container.end(), comp()));}
    // 얘네는 따로 comp에 따라서 정렬을 해서 넣어줘야함
    void pop()
    {return (std::pop_heap(pq_container.begin(), pq_container.end(), comp());)}

};
}

#endif