// this recursion works
class Solution {
public:
	int code(int ind, int n, vector<int>&ar, int prev) {
		if (ind == n)return 0;
		if (ar[ind] > prev) {
			return max( 1 + code(ind + 1, n, ar, ar[ind]), code(ind + 1, n, ar, prev));
		} else {
			return code(ind + 1, n, ar, prev);
		}
	}
	int lengthOfLIS(vector<int>& ar) {
		int n = ar.size(); if (n == 1)return 1;
		return code(0, n, ar, INT_MIN);
	}
};

// now rec + memorizatn
class Solution {
public:
	int code(int ind, int n, vector<int>&ar, int prev_ind, vector< vector<int>>&dp) {
		if (ind == n)return 0;
		if (dp[ind][prev_ind] != -1)return dp[ind][prev_ind];
		if (ar[ind] > ar[prev_ind]) {
			return dp[ind][prev_ind] = max( 1 + code(ind + 1, n, ar, ind, dp), code(ind + 1, n, ar, prev_ind, dp));
		} else {
			return dp[ind][prev_ind] = code(ind + 1, n, ar, prev_ind, dp);
		}
	}
	int lengthOfLIS(vector<int>& ar) {
		int n = ar.size(); if (n == 1)return 1;
		vector<int>temp; temp.push_back(INT_MIN);
		for (int i = 0; i < n; i++)temp.push_back(ar[i]);
		vector < vector <int>>dp(n + 1, vector<int>(n + 1, -1));
		return code(1, n, temp, 0, dp);
	}
};


// now rec + memorizatn
class Solution {
public: x
	int code(int ind, int n, vector<int>&ar, int prev_ind, vector< vector<int>>&dp) {
		if (ind == n)return 0;
		if (dp[prev_ind][ind] != -1)return dp[prev_ind][ind];
		if (ar[ind] > ar[prev_ind]) {
			return dp[prev_ind][ind] = max( 1 + code(ind + 1, n, ar, ind, dp), code(ind + 1, n, ar, prev_ind, dp));
		} else {
			return dp[prev_ind][ind] = code(ind + 1, n, ar, prev_ind, dp);
		}
	}
	int lengthOfLIS(vector<int>& ar) {
		int n = ar.size(); if (n == 1)return 1;
		vector<int>temp; temp.push_back(INT_MIN);
		for (int i = 0; i < n; i++)temp.push_back(ar[i]);
		vector < vector <int>>dp(n + 1, vector<int>(n + 1, -1));
		return code(1, n, temp, 0, dp);
	}
};
// recursion trying again
class Solution {
public:
	int code(int ind, int n, vector<int>&ar, int prev_ind, vector< vector<int>>&dp) {
		if (ind == n)return 0;
		if (dp[prev_ind][ind] != -1)return dp[prev_ind][ind];
		if (ar[ind] > ar[prev_ind] || prev_ind == -1) {
			return dp[prev_ind][ind] = max( 1 + code(ind + 1, n, ar, ind, dp), code(ind + 1, n, ar, prev_ind, dp));
		} else {
			return dp[prev_ind][ind] = code(ind + 1, n, ar, prev_ind, dp);
		}
	}
	int lengthOfLIS(vector<int>& ar) {
		int n = ar.size(); if (n == 1)return 1;
		vector < vector <int>>dp(n + 1, vector<int>(n + 1, -1));
		return code(0, n, ar, -1, dp);
	}
};