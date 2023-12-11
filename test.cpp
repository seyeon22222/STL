#include <iostream>
#include <vector>
#include "../Vector/Vector.hpp"
#include "../Deque/Deque.hpp"
#include <deque>

int main()
{
    std::deque<std::vector<int> > a;

	std::vector<int> pp;
    for (int i = 0; i < 5; i++)
        pp.push_back(i);
	a.push_front(pp);
	pp.clear();
	for (int i = -5; i < 0; i++)
		pp.push_back(i);
	a.push_front(pp);
	pp.clear();
	for (int i = 0; i < 5; i++)
        pp.push_back(i);
	a.push_front(pp);
	pp.clear();
	for (int i = -5; i < 0; i++)
		pp.push_back(i);
	a.push_front(pp);
	std::deque<std::vector<int> > aaaa(a);



	a.insert(a.begin() + 1, aaaa.begin(), aaaa.end());
	for (size_t i = 0; i < a.size(); i++)
	{
		for (size_t j = 0; j < a[i].size(); j++)
			std::cout << a[i][j];
		std::cout << std::endl;
	}
	std::cout << "------------------------\n";
	ft::Deque<ft::Vector<int> > b;

	ft::Vector<int> qq;
    for (int i = 0; i < 5; i++)
        qq.push_back(i);
	b.push_front(qq);
	qq.clear();
	for (int i = -5; i < 0; i++)
		qq.push_back(i);
	b.push_front(qq);
	qq.clear();
	for (int i = 0; i < 5; i++)
        qq.push_back(i);
	b.push_front(qq);
	qq.clear();
	for (int i = -5; i < 0; i++)
		qq.push_back(i);
	b.push_front(qq);
	ft::Deque<ft::Vector<int> > bbbb(b);
	b.insert(b.begin(), bbbb.begin(), bbbb.end());
	for (size_t i = 0; i < b.size(); i++)
	{
		for (size_t j = 0; j < b[i].size(); j++)
			std::cout << b[i][j];
		std::cout << std::endl;
	}
	std::cout << std::endl;

	// system("leaks STL");	
    return 0;
}
