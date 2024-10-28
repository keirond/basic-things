
#include <climits>
#include <iostream>

int main() {

	// A comment line

	/*
		Multiple commment lines
	*/

	// Block
	{
		int x = 1;
		std::cout << "x in block: " << x << std::endl;
		{
			int y = 2;
			std::cout << "y in sub-block: " << y << std::endl;
		}
	}

	// Data types
	short _short = SHRT_MAX; // 2 bytes
	unsigned short _unsigned_short = -1;

	int _int = INT_MAX;
	unsigned int _unsigned_int = -1;

	long _long = LLONG_MAX;
	int long _int_long = LLONG_MAX;
	long int _long_int = LLONG_MAX;

	long long _long_long = LLONG_MAX;
}