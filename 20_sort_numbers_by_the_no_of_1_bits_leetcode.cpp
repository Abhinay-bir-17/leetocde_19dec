// https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/
class Solution {
public:
	int code(int n) {
		int ans = 0;
		while (n) {
			if (n & 1)ans += 1;
			n = n >> 1;
		} return ans;
	}
	vector<int> sortByBits(vector<int>& ar) {
		auto lambda = [&](int &a, int &b) {
			int ba = code(a);
			int bb = code(b);
			if (ba == bb)return a < b;
			else return ba < bb;
		};
		sort(ar.begin(), ar.end(), lambda);
		return ar;
	}
};