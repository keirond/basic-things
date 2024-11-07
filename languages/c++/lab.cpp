#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <deque>
#include <format>
#include <iostream>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

// Aliases
using ll = long long;

// Macros
#define pb push_back
#define mp make_pair

class Solution {
public:
	vector<vector<int>> towerOfHanoi(int n) {
		return towerOfHanoi(n, 1, 3, 2);
	}

	vector<vector<int>> towerOfHanoi(int n, int source, int dest, int intermediate) {
		if (n == 1)
			return {
				{ source, dest }
			};
		vector<vector<int>> ans = towerOfHanoi(n - 1, source, intermediate, dest);
		ans.push_back({ source, dest });
		vector<vector<int>> last = towerOfHanoi(n - 1, intermediate, dest, source);
		ans.insert(ans.end(), last.begin(), last.end());
		return ans;
	}

	long long toh(int n, int from, int to, int aux) {
		if (n == 0) return 0;
		long long ans = toh(n - 1, from, aux, to);
		printf("move disk %d from rod %d to rod %d\n", N, from, to);
		return ans + 1 + toh(n - 1, aux, to, from);
	}
};

int main() {
	Solution s = Solution();
	s.toh(3, 1, 3, 2);
}