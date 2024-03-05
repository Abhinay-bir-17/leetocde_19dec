class Solution {
public:
	int code(vector<int>ar, int n, int ind) {
		if (ind >= n) {
			return 0;
		}

		return max(  ar[ind] + code(ar, n, ind + 2), code(ar, n, ind + 1));

	}
	int rob(vector<int>& ar) {
		int n = ar.size();
		int ans = INT_MIN;
		return code(ar, n, 0);
	}
};

//memo + recursion
class Solution {
public:
	int code(vector<int>ar, int n, int ind, vector<int>&dp) {
		if (ind >= n) {
			return 0;
		}
		if (dp[ind] != -1)return dp[ind];
		return dp[ind] = max(  ar[ind] + code(ar, n, ind + 2, dp), code(ar, n, ind + 1, dp));

	}
	int rob(vector<int>& ar) {
		int n = ar.size();
		int ans = INT_MIN; vector<int>dp(n + 1, -1);
		return code(ar, n, 0, dp);
	}
};

//bottom up
class Solution {
public:
	int rob(vector<int>& ar) {
		int n = ar.size();
		vector<int>dp(n);
		if (n == 1)return ar[0]; if (n == 2)return max(ar[1], ar[0]);
		dp[0] = ar[0]; dp[1] = max(ar[0], ar[1]);
		for (int i = 2; i < n; i++) {
			dp[i] = max(dp[i - 1], ar[i] + dp[i - 2]);
		} return dp[n - 1];
	}
};