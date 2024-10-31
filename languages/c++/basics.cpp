
#include <algorithm>
#include <cfloat>
#include <climits>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>

int main() {

	// A comment line

	/*
		Multiple commment lines
	*/

	//======= Block
	{
		int x = 1;
		std::cout << "x in block: " << x << std::endl;
		{
			int y = 2;
			std::cout << "y in sub-block: " << y << std::endl;
		}
	}

	//======= Integer data types
	short _short_min = SHRT_MIN; // 2 bytes
	short _short_max = SHRT_MAX;

	int _int_min = INT_MIN; // 4 bytes
	int _int_max = INT_MAX;

	long _long_min = LONG_MIN; // 4 or 8 bytes
	long _long_max = LONG_MAX;
	int long _int_long = LONG_MIN; // it's long type
	long int _long_int = LONG_MIN; // long type as well

	long long _long_long_min = LLONG_MIN; // 8 bytes
	long long _long_long_max = LLONG_MAX;

	short _short = 10;
	unsigned short _unsigned_short = -_short;
	std::cout << (~(_short - 1) & ((1 << 16) - 1)) << " " << _unsigned_short << std::endl;

	//======= Floating-point data types
	float _float_min = FLT_MIN; // 4 bytes
	float _float_max = FLT_MAX;

	// TODO

	//======= Set operations
	std::set<int> _A = { 1, 2, 3, 4 };
	std::set<int> _B = { 2, 4 };
	std::vector<int> _C;

	_C = {}; // Union A | B
	std::set_union(_A.begin(), _A.end(), _B.begin(), _B.end(), std::back_inserter(_C));
	// _C.insert(_A.begin(), _A.end());
	// _C.insert(_B.begin(), _B.end());

	_C = {}; // Intersection A & B
	std::set_intersection(_A.begin(), _A.end(), _B.begin(), _B.end(), std::back_inserter(_C));
	// for (int element : _A) {
	// 	if (_B.count(element)) {
	// 		_C.insert(element);
	// 	}
	// }

	_C = {}; // Difference A - B
	std::set_difference(_A.begin(), _A.end(), _B.begin(), _B.end(), std::back_inserter(_C));
	// for (int element : _A) {
	// 	if (!_B.count(element)) {
	// 		_C.insert(element);
	// 	}
	// }

	_C = {}; // Symmetric Difference A ^ B
	std::set_symmetric_difference(_A.begin(), _A.end(), _B.begin(), _B.end(), std::back_inserter(_C));
	// for (int element : _A) {
	// 	if (!_B.count(element)) {
	// 		_C.insert(element);
	// 	}
	// }
	// for (int element : _B) {
	// 	if (!_A.count(element)) {
	// 		_C.insert(element);
	// 	}
	// }

	// Subset Check whether A is subset of B
	bool _ret_set_1 = std::includes(_B.begin(), _B.end(), _A.begin(), _A.end());

	// Superset Check whether A is superset of B
	bool _ret_set_2 = std::includes(_A.begin(), _A.end(), _B.begin(), _B.end());
}