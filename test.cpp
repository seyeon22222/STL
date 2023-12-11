#include <iostream>
#include <vector>
#include "../Vector/Vector.hpp"
// #include "../Deque/Deque.hpp"
#include <deque>
int main()
{
	ft::Vector<int> a(1, 5);
	for (size_t i = 0; i < a.size(); i++)
		std::cout << a[i];
	std::cout << std::endl;
}
