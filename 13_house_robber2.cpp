// recusrion method
class Solution {
public:
	int code(int ind, int n, vector<int>&ar) {
		if (ind > n)return 0;
		return max(ar[ind] + code(ind + 2, n, ar), code(ind + 1, n, ar));
	}
	int rob(vector<int>& ar) {
		int n = ar.size(); if (n == 1)return ar[0]; //if (n == 2)return 0;
		return max(
		           code(0, n - 2, ar),
		           code(1, n - 1, ar)
		       );
	}
};

// rec + memo method
class Solution {
public:
	int code(int ind, int n, vector<int>&ar, vector<int>&dp) {
		if (ind > n)return 0; if (dp[ind] != -1)return dp[ind];
		return dp[ind] = max(ar[ind] + code(ind + 2, n, ar, dp), code(ind + 1, n, ar, dp));
	}
	int rob(vector<int>& ar) {
		int n = ar.size(); if (n == 1)return ar[0]; //if (n == 2)return 0;
		vector<int>dp(n, -1);
		vector<int>dp1(n, -1);
		return max(
		           code(0, n - 2, ar, dp),
		           code(1, n - 1, ar, dp1)
		       );
	}
};
