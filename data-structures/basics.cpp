#include <iostream>
#include <list>
#include <string>
#include <vector>

int main() {
	std::string __string = "string";

	int __array[] = { 1, 2, 3, 4, 5 };

	std::list<int> __list = { 1, 2, 3, 4, 5 };

	std::vector<int> __vector = { 1, 2, 3, 4, 5 };

	for (int i = 0; i < 10; i++) {
		std::cout << i << std::endl;
	}
}
