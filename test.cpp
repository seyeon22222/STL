#include <iostream>
#include <vector>
#include "Vector.hpp"
int main()
{
	std::vector<int> a(1, 5);
	ft::Vector<int> b(1, 5);
	for (size_t i = 0; i < a.size(); i++)
		std::cout << a[i];
	std::cout << std::endl;
	a.resize(10, 0);
	for (size_t i = 0; i < a.size(); i++)
		std::cout << a[i];
	std::cout << std::endl;
	a.resize(1, 0);
	for (size_t i = 0; i < a.size(); i++)
		std::cout << a[i];
	std::cout << std::endl;
	for (size_t i = 0; i < b.size(); i++)
		std::cout << b[i];
	std::cout << std::endl;
	b.resize(10, 0);
	for (size_t i = 0; i < b.size(); i++)
		std::cout << b[i];
	std::cout << std::endl;
	b.resize(1, 0);
	for (size_t i = 0; i < b.size(); i++)
		std::cout << b[i];
	std::cout << std::endl;
	system("leaks STL");
}