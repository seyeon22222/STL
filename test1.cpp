#include <iostream>
#include <vector>
#include "Vector/Vector.hpp"
#include "Deque/Deque.hpp"
#include <deque>
#include <queue>
#include <algorithm>
// #include "Util/Algorithm.hpp"
#include "Queue/Priority_queue.hpp"
#include <iostream>

int main()
{
	ft::deque<int> a;
	a.push_front(1);
	a.push_front(3);
	a.push_front(2);
	a.push_front(4);
	a.push_front(5);

	std::deque<int> d;
	d.push_front(1);
	d.push_front(3);
	d.push_front(2);
	d.push_front(4);
	d.push_front(5);

	ft::priority_queue<int>	b;
	std::priority_queue<int> c;
	for (int i = 4; i > -1; i--)
		b.push(a[i]);
	for (int i = 4; i > -1; i--)
		c.push(d[i]);
	while (!b.empty())
	{
		std::cout << (b.top());
		b.pop();
	}
	std::cout << std::endl;
	while (!c.empty())
	{
		std::cout << (c.top());
		c.pop();
	}
	// (a.begin(), a.end());
	// std::cout << (a.end() == itt) << std::endl;

    return 0;
}
