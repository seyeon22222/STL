#include <iostream>
#include <vector>
#include "Vector.hpp"
int main()
{
	std::vector<int>	temp;

	for (int i = 5; i > 0; i--)
		temp.push_back(i);

	std::vector<int> a(1, 5);
	ft::Vector<int> b(1, 5);
	ft::Vector<int> c(1, 5);
	std::vector<int> d(1, 5);
	for (size_t i = 0; i < a.size(); i++)
		std::cout << a[i];
	std::cout << std::endl;
	a.assign(temp.begin(), temp.end());
	for (size_t i = 0; i < a.size(); i++)
		std::cout << a[i];
	std::cout << std::endl;
	a.insert(a.begin(), temp.begin(), temp.end());
	for (size_t i = 0; i < a.size(); i++)
		std::cout << a[i];
	std::cout << std::endl;
	std::cout << *(a.erase(a.begin() + 1, a.begin() + 1 )) << std::endl;;
	for (size_t i = 0; i < a.size(); i++)
		std::cout << a[i];
	std::cout << std::endl;
	std::cout << "------------------\n";
	for (size_t i = 0; i < b.size(); i++)
		std::cout << b[i];
	std::cout << std::endl;
	b.assign(temp.begin(), temp.end());
	for (size_t i = 0; i < b.size(); i++)
		std::cout << b[i];
	std::cout << std::endl;
	b.insert(b.begin(), temp.begin(), temp.end());
	for (size_t i = 0; i < b.size(); i++)
		std::cout << b[i];
	std::cout << std::endl;
	std::cout << *(b.erase(b.begin() + 1, b.begin() + 1)) << std::endl;;
	for (size_t i = 0; i < b.size(); i++)
		std::cout << b[i];
	std::cout << std::endl;
	a.clear();
	b.clear();
	for (size_t i = 0; i < a.size(); i++)
		std::cout << a[i];
	std::cout << "a clear" << std::endl;
	for (size_t i = 0; i < b.size(); i++)
		std::cout << b[i];
	std::cout << "b clear" << std::endl;
	// system("leaks STL");
}