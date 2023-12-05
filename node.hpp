#ifndef NODE_HPP
# define NODE_HPP

# include <cstring>

namespace ft
{

template<typename T>
class Node
{
private:
	T 		data;
	Node<T>	*next;
	Node<T>	*prev;
public:
	Node(void) : next(nullptr), data(), prev(nullptr) {}
	Node(T const &_data) : next(nullptr), data(_data), prev(nullptr) {}
	Node(Node *_prev, T const& _data, Node *_next=nullptr) :
	 prev(_prev), data(_data), next(_next) {}
	virtual ~Node(void);
	Node Node(const Node& obj) {*this = obj;}
	Node &operator=(const Node& obj)
	{
		if (*this == obj)
			return (*this);
		this->prev = obj.prev;
		this->data = obj.data;
		this->next = obj.next;
		return (*this);
	}

};
}



#endif