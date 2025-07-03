#include <iostream>
#include <vector>
#include <array>
#include <map>
template <typename T>
void printContainer(const T& container) {
	for (const auto& i : container)
	{
		std::cout << i << " ";
	}
	std::cout << "\n";
}

template <typename key, typename value>
void printContainer(const std::map<key, value>& container) {
	for (const auto& [k, v] : container) {
		std::cout << k << " => " << v << " ";
	}
	std::cout << "\n";
}

template<typename T>
void printContainerByIt(const T& container) {
	for (auto it = container.begin(); it != container.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << "\n";
}

template <typename key, typename value>
void printContainerByIt(const std::map<key, value>& container) {
	for (auto it = container.begin(); it != container.end(); it++) {
		std::cout << it->first << " => " << it->second << " ";
	}
	std::cout << "\n";
}

int main()
{
	std::vector<int> v{ 1,2,3,4,5,6,7,8,9,10 };
	std::array<float, 10> fa{ 1.4, 2.3, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.10 };
	std::map<std::string, int> m{ {"CPU", 10}, {"GPU", 15}, {"RAM", 20} };
	printContainer(v);
	printContainer(fa);
	printContainer(m);
	printContainerByIt(v);
	printContainerByIt(fa);
	printContainerByIt(m);
	return 0;
}