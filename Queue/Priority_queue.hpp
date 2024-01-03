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
	typedef typename container_type::difference_type	difference_type;

protected:
    container_type  pq_container;
    Compare         pq_comp;
	int				pq_size;
public:
    explicit priority_queue (const Compare& comp = Compare(), const Container& ctnr = Container())
	: pq_size(0)
    {
		this->pq_comp = comp;
		pq_container.push_back(0);
		for (size_t i = 1; i < ctnr.size(); i++)
		{
			push(ctnr[i]);
			pq_size++;
		}
    }

    template <class InputIterator>
    priority_queue (InputIterator first, InputIterator last, 
    const Compare& comp = Compare(), const Container& ctnr = Container(),
    typename enable_if<!is_intergral<InputIterator>::value>::type* = 0)
	: pq_size(0)
    {
        pq_comp = comp;
		difference_type sub = last - first;
		for (difference_type i = 1; i < sub; i++)
		{
			push(*(first + i));
			pq_size++;
		}
    }

    bool empty() const 
	{
		if (pq_size)
			return (false);
		return (true);
	}
    size_type size() const {return (pq_container.size());}
    const value_type& top() const {return (pq_container.front());}

    void push (const value_type& val)
    {
		pq_size++;
		this->pq_container.push_back(val);
		int idx = pq_container.size() - 1;
		int parent = 0, child = 0;
		while (idx > 1)
		{
			child = idx;
			parent = (idx - 1) / 2;
			if (pq_comp(pq_container[parent], pq_container[child]))
			{
				value_type temp = pq_container[parent];
				pq_container[parent] = pq_container[child];
				pq_container[child] = temp;
				idx /= 2;
			}
			else
				break;
		}
	}
	void heapify(const int& idx)
	{
		int now = idx;
		int child_L = 2 * idx;
		int child_R = 2 * idx + 1;
		if (child_L <= pq_container.size() - 1 && pq_comp(pq_container[now], pq_container[child_L]))
			now = child_L;
		if (child_R <= pq_container.size() - 1 && pq_comp(pq_container[now], pq_container[child_R]))
			now = child_R;
		if (now != idx)
		{
			value_type temp = pq_container[now];
			pq_container[now] = pq_container[idx];
			pq_container[idx] = temp;
			heapify(now);
		}
	}	

    void pop()
    {
		if (empty())
			return ;
		pq_container[0] = pq_container[pq_container.size() - 1];
		pq_container.pop_back();
		heapify(0);
		pq_size--;
	}

};
}

#endif