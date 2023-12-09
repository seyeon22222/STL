#ifndef LIST_HPP
# define LIST_HPP

#include <iostream>
#include "../Util/Etc_func.hpp"

namespace ft
{
template <class T>
class ListIterator
{
public:
    typedef T           value_type;
    typedef T&          reference;
    typedef Node<T>*    pointer;
private:
    pointer ptr;
public:
    ListIterator() : ptr(nullptr) {};
    ListIterator(pointer obj) : ptr(obj);
    ListIterator(const ListIterator &obj) : ptr(obj.ptr) {};
    virtual ~ListIterator() {};

    pointer node(void) const {return (ptr);}
    Listiterator &operator=(const Listiterator& obj)
    {
        if (*this == obj)
            return (*this);
        ptr = obj.ptr;
        return (*this);
    }

    Listiterator &operator++()
    {
        ptr = ptr->next;
        return (*this);
    }

    Listiterator operator++(int)
    {
        Listiterator temp(*this);
        operator++();
        return (temp);
    }

    Listiterator &operator--()
    {
        ptr = ptr->prev;
        return (*this);
    }

    Listiterator operator--(int)
    {
        Listiterator temp(*this);
        operator--();
        return (temp);
    }
    bool operator==(const ListIterator &obj) const {return (ptr == obj.ptr);}
    bool operator==(const ListIterator &obj) const {return (ptr != obj.ptr);}
    reference operator*() const {return *ptr->data;}
    pointer operator->() const {return ptr->data;}
    
};

template < class T, class Alloc = std::allocator<T> >
class list
{

};

}




#endif