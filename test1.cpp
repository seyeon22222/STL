#include <iostream>
#include <vector>
#include "Vector/Vector.hpp"
#include "Deque/Deque.hpp"
#include <deque>

int main()
{
	// ft::deque<int> a;
	// a.insert(a.begin(), 5);
	// a.insert(a.begin(), 2, 42);
	
	// for (size_t i = 0; i < a.size(); i++)
	// 	std::cout << a[i] << " ";
	// std::cout << std::endl;

	// ft::deque<int> b;
	// b.insert(b.begin(), a.begin(), a.end());
	// for (size_t i = 0; i < b.size(); i++)
	// 	std::cout << b[i] << " ";
	// std::cout << std::endl;
	// b.insert(b.end(), a.begin(), a.end());
	// for (size_t i = 0; i < b.size(); i++)
	// 	std::cout << b[i] << " ";
	// std::cout << std::endl;

	ft::deque<int> c;
	c.insert(c.begin(), 66,66);
	// for (size_t i = 0; i < c.size(); i++)
	// 	std::cout << c[i] << " ";
	// std::cout << std::endl;
	c.insert(c.begin() + 20, 66, 66);
	// for (size_t i = 0; i < c.size(); i++)
	// 	std::cout << c[i] << " ";
	// std::cout << std::endl;
	std::cout << c.size();

	// std::deque<int>	a;
	// a.push_back(1);
	// std::cout << *a.end() << std::endl;
	// ft::deque<int> a;

	// a.push_back(1);
	// a.push_back(5);
	// a.push_back(42);
	// for (size_t i = 0; i < a.size(); i++)
	// 	std::cout << a[i] << " ";
	// std::cout << std::endl;
	// a.erase(++a.begin());
	// for (size_t i = 0; i < a.size(); i++)
	// 	std::cout << a[i] << " ";
	// std::cout << std::endl;
	// assert(a.front() == 1);
	// assert(a.back() == 42);
	// assert(a.size() == 2);
	// for (size_t i = 0; i < a.size(); i++)
	// 	std::cout << &a[i] << std::endl;
	// ft::deque<int>::iterator ita = a.end();
	// std::cout << "before " << &ita << std::endl;
	// ft::deque<int>::iterator it = a.erase(--a.end());
	// for (size_t i = 0; i < a.size(); i++)
	// 	std::cout << a[i] << " ";
	// std::cout << std::endl;
	// std::cout << "after " << &it << std::endl;
	// std::cout << *a.end() << std::endl;
	// std::cout << "deleted [end]\n";
	// assert(it == a.end());
	// assert(a.front() == 1);
	// assert(a.back() == 1);
	// assert(a.size() == 1);
	// std::deque<int> a(10, 5);
	// ft::deque<int> b(10, 5);

	// a.push_front(2);
	// b.push_front(2);
	// a.push_back(1);
	// b.push_back(1);
	// for (size_t i = 0; i < a.size(); i++)
	// 	std::cout << a[i] << " ";
	// std::cout << std::endl;
	// std::cout << &*(a.erase(a.begin(), a.end() - 1)) << std::endl;
	
	// for (size_t i = 0; i < a.size(); i++)
	// 	std::cout << a[i] << " ";
	// std::cout << std::endl;
	// std::cout << "----------------------\n";
	// for (size_t i = 0; i < b.size(); i++)
	// 	std::cout << b[i] << " ";
	// std::cout << std::endl;
	
	// std::cout << &*(b.erase(b.begin(), b.end()- 1)) << std::endl;
	// for (size_t i = 0; i < b.size(); i++)
	// 	std::cout << b[i] << " ";
	// std::cout << std::endl;
	// std::cout << "b " << &(*b.end());

    // std::deque<std::vector<int> > a;
	// std::vector<int> pp;
    // for (int i = 0; i < 5; i++)
    //     pp.push_back(i);
	// a.push_front(pp);
	// pp.clear();
	// for (int i = -5; i < 0; i++)
	// 	pp.push_back(i);
	// a.push_front(pp);
	// pp.clear();
	// for (int i = 0; i < 5; i++)
    //     pp.push_back(i);
	// a.push_front(pp);
	// pp.clear();
	// for (int i = -5; i < 0; i++)
	// 	pp.push_back(i);
	// a.push_front(pp);
	// std::deque<std::vector<int> > aaaa(a);
	// a.erase(a.begin());
	// for (size_t i = 0; i < a.size(); i++)
	// {
	// 	for (size_t j = 0; j < a[i].size(); j++)
	// 		std::cout << a[i][j];
	// 	std::cout << std::endl;
	// }
	// std::cout << "------------------------\n";
	// ft::deque<ft::vector<int> > b;

	// ft::vector<int> qq;
    // for (int i = 0; i < 5; i++)
    //     qq.push_back(i);
	// b.push_front(qq);
	// qq.clear();
	// for (int i = -5; i < 0; i++)
	// 	qq.push_back(i);
	// b.push_front(qq);
	// qq.clear();
	// for (int i = 0; i < 5; i++)
    //     qq.push_back(i);
	// b.push_front(qq);
	// qq.clear();
	// for (int i = -5; i < 0; i++)
	// 	qq.push_back(i);
	// b.push_front(qq);
	// ft::deque<ft::vector<int> > bbbb(b);
	// b.erase(b.begin());
	// for (size_t i = 0; i < b.size(); i++)
	// {
	// 	for (size_t j = 0; j < b[i].size(); j++)
	// 		std::cout << b[i][j];
	// 	std::cout << std::endl;
	// }
	// std::cout << std::endl;
	// std::cout << "Ssdasdasd\n";
	// system("leaks STL");	

    return 0;
}
