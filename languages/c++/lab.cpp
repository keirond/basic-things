#include <cmath>
#include <cstddef>
#include <deque>
#include <format>
#include <iostream>
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

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	vector<string> binaryTreePaths(TreeNode *root) {
		if (root == nullptr) return {};
		vector<string> ans;
		stack<pair<TreeNode *, string>> s;
		s.push(make_pair(root, to_string(root->val)));

		while (s.size()) {
			auto [top, top_val] = s.top();
			s.pop();
			if (top->left == nullptr && top->right == nullptr) ans.push_back(top_val);
			if (top->left) s.push(make_pair(top->left, top_val + "->" + to_string(top->left->val)));
			if (top->right) s.push(make_pair(top->right, top_val + "->" + to_string(top->right->val)));
		}
		return ans;
	}
};