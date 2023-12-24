#ifndef ALGORITHM_HPP
# define ALGORITHM_HPP

# include "../Iterator/Iterator_traits.hpp"

namespace ft
{

template <class Arg1, class Arg2, class Result>
struct binary_function 
{
    typedef Arg1 first_argument_type;
    typedef Arg2 second_argument_type;
    typedef Result result_type;
};

template <class T>
struct less : binary_function <T,T,bool> 
{
	bool operator() (const T& x, const T& y) const {return (x < y);}
};

template <class T>
struct greater : binary_function <T,T,bool> 
{
	bool operator() (const T& x, const T& y) const {return (x > y);}
};

template <class RandomAccessIterator>
void make_heap (RandomAccessIterator first, RandomAccessIterator last)
{
	make_heap(first, last, less<typename iterator_traits<RandomAccessIterator>::value_type>());
}

template <class RandomAccessIterator, class Compare>
void make_heap (RandomAccessIterator first, RandomAccessIterator last,Compare comp )
{
	typedef typename iterator_traits<RandomAccessIterator>::difference_type difference_type;
    difference_type n = last - first;
    if (n > 1)
    {
        for (difference_type start = (n - 2) / 2; start >= 0; --start)
        {
            sift_down<Compare>(first, last, comp, n, first + start);
        }
    }
	
}

template <class Compare, class RandomAccessIterator>
void	sift_down(RandomAccessIterator first, RandomAccessIterator last, Compare comp,
typename Iterator_traits<RandomAccessIterator>::difference_type len, RandomAccessIterator start)
{
	typedef typename iterator_traits<_RandomAccessIterator>::difference_type difference_type;
    typedef typename iterator_traits<_RandomAccessIterator>::value_type value_type;
	difference_type child = start - first;
	if (len < 2 || (len - 2) / 2 < child)
        return;
	child = 2 * child + 1;
    RandomAccessIterator child_i = first + child;
	if ((child + 1) < len && comp(*child_i, *(child_i + 1))) 
	{
        ++child_i;
        ++child;
    }
	if (comp(*child_i, *start))
        return;
	value_type top(_VSTD::move(*start));
    do
    {
        *start = _VSTD::move(*child_i);
        start = child_i;

        if ((len - 2) / 2 < child)
            break;

        child = 2 * child + 1;
        child_i = first + child;

        if ((child + 1) < len && comp(*child_i, *(child_i + 1))) {
            ++child_i;
            ++child;
        }

    } while (!comp(*child_i, top));
    *start = _VSTD::move(top);
}

template <class RandomAccessIterator>
void pop_heap (RandomAccessIterator first, RandomAccessIterator last)
{

}

template <class RandomAccessIterator, class Compare>
void pop_heap (RandomAccessIterator first, RandomAccessIterator last, Compare comp)
{

}

template <class RandomAccessIterator>
void push_heap (RandomAccessIterator first, RandomAccessIterator last)
{

}

template <class RandomAccessIterator, class Compare>
void push_heap (RandomAccessIterator first, RandomAccessIterator last, Compare comp)
{
    
}



}

#endif