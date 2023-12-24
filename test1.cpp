#include <iostream>
#include <vector>
#include "Vector/Vector.hpp"
#include "Deque/Deque.hpp"
#include <deque>
#include <queue>
#include <algorithm>
#include "Util/Algorithm.hpp"
int main()
{
	ft::vector<int> a;

	a.push_back(10);
	a.push_back(1);
	a.push_back(7);
	a.push_back(5);
	a.push_back(0);
	a.push_back(2);
	a.push_back(8);

	assert(std::make_heap(a.begin(), a.end()) == ft::make_heap(a.begin(), a.end()));

    return 0;
}
