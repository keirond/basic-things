#include <iostream>

int main() {

	//======= Swap two numbers
	int _first = 2;
	int _second = 3;
	int _third = -1;

	_first = _first ^ _second; // symmetric difference
	_second = _first ^ _second;
	_first = _first ^ _second;

	std::cout << _first << " " << _second << std::endl;

	_second = _second ^ _third;
	_third = _second ^ _third;
	_second = _second ^ _third;

	std::cout << _second << " " << _third << std::endl;
}