#include <algorithm>
#include <climits>
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
	int lastStoneWeightII(vector<int> &stones) {
		int n = stones.size();
		int sum = accumulate(stones.begin(), stones.end(), 0, [](int a, int b) {
			return a + abs(b);
		});
		vector<int> dp(sum + 1, INT_MAX);

		for (int i = 0; i <= sum; ++i) {
			dp[i] = i;
		}

		for (int i = n - 1; i >= 0; --i) {
			vector<int> temp(sum + 1, INT_MAX);
			for (int j = 0; j <= sum - abs(stones[i]); ++j) {
				temp[j] = min(dp[j + abs(stones[i])], dp[abs(j - abs(stones[i]))]);
			}
			dp = temp;
		}
		return dp[0];
	}
};