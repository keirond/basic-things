#include <algorithm>
#include <any>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
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
		auto get_subset_sums = [&](int l, int r) -> vector<ll> {
			int n = r - l;
			vector<ll> res;
			for (int i = 0; i < (1 << n); ++i) {
				ll temp = 0;
				for (int j = 0; j < n; ++j) {
					if (i & (1 << j)) temp += stones[j + l];
					else temp -= stones[j + l];
				}
				res.push_back(temp);
			}
			return res;
		};

		vector<ll> l_sum = get_subset_sums(0, n / 2);
		vector<ll> r_sum = get_subset_sums(n / 2, n);
		sort(l_sum.begin(), l_sum.end());
		sort(r_sum.begin(), r_sum.end());

		ll ans = INT_MAX;
		for (ll i : l_sum) {
			auto low = lower_bound(r_sum.begin(), r_sum.end(), -i);
			int ind = low - r_sum.begin();
			if (ind != 0) {
				ans = min(ans, abs(r_sum[ind - 1] + i));
			}
			if (ind != r_sum.size()) {
				ans = min(ans, abs(r_sum[ind] + i));
			}
		}
		return ans;
	}

	int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = 0;
        int minusSum;

        for(int i=0;i<n;i++){
            sum+=stones[i];
        }

        bitset<3001> dp(0);
        dp[0]=1;
        for(int num : stones){
            dp = dp | (dp<<num);
        }

        for(int i=sum/2;i>=0;i--){
            if (dp[i]==1){
                minusSum = i;
                break;
            }
        }
        // cout<<dp<<endl;
        // cout<<minusSum<<endl;

        return sum-2*minusSum;
    }
};

class InputReader {
public:
	auto read() {
		return vector<int>{ 2, 7, 4, 1, 8, 1 };
	}
};

class OutputPrinter {
public:
	void print(any val) {
		if (val.type() == typeid(int)) {
			cout << any_cast<int>(val) << endl;
		}
	}
};

int main() {
	InputReader i = InputReader();
	Solution s = Solution();
	OutputPrinter o = OutputPrinter();

	auto input = i.read();
	o.print(s.lastStoneWeightII(input));
}