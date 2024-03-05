//  recursion works, did on my own
class Solution {
public:
	typedef long long ll;
	ll code(vector<int>&ar, int n, int ind, int re_ind) {
		if (ind == n)return 0;
		int temp = 0;
		if (re_ind & 1)temp = -1 * ar[i]; else temp = ar[i];
		return max( temp + code(ar, n, ind + 1, re_ind + 1), code(ar, n, ind + 1, re_ind));

	}
	long long maxAlternatingSum(vector<int>& ar) {
		int n = ar.size();


		return code(ar, n, 0, 0);
	}
};

// this is rec + memorization, works.
class Solution {
public:
	typedef long long ll;
	ll code(vector<int>&ar, int n, int ind, int re_ind, vector<vector<ll>>&dp) {
		if (ind == n)return 0;
		ll temp = 0;
		ll flag;
		if (re_ind & 1) {temp = -1 * ar[ind]; flag = 1;} else {temp = ar[ind]; flag = 0;}
		if (dp[flag][ind] != -1)return dp[flag][ind];
		return dp[flag][ind] = max( temp + code(ar, n, ind + 1, re_ind + 1, dp), code(ar, n, ind + 1, re_ind, dp));

	}
	long long maxAlternatingSum(vector<int>& ar) {
		int n = ar.size();
		vector<vector<ll>> dp(2, vector<ll>(n, -1));
		return code(ar, n, 0, 0, dp);
	}
};

// bottom  up solution
class Solution {
public:
	typedef long long ll;
	long long maxAlternatingSum(vector<int>& ar) {
		int n = ar.size();
		// below is a 2d vec of 2 rows, n+1 colms.
		vector<vector<ll>> dp(2, vector<ll>(n + 1, 0));
		for (int i = 1; i <= n; i++) {
			dp[0][i] = max(dp[1][i - 1] - ar[i - 1], dp[0][i - 1]);
			dp[1][i] = max(dp[0][i - 1] + ar[i - 1], dp[1][i - 1]);
		}
		return max(dp[0][n], dp[1][n]);
	}
};