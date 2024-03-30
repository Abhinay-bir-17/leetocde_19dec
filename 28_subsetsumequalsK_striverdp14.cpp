// recusrion : works
#include <bits/stdc++.h>
int code(int ind, int sum, int n, int k, vector<int>&ar) {
	if (sum == k)return 1;
	if (sum > k)return 0;
	if (ind == n)return 0;
	int f1 = code(ind + 1, sum + ar[ind], n, k, ar);
	if (f1 == 1)return 1;
	int f2 = code(ind + 1, sum, n, k, ar);
	if (f2 == 1)return 1;
	return 0;
}
bool subsetSumToK(int n, int k, vector<int> &ar) {
	// Write your code here
	if (code(0, 0, n, k, ar))return true; else return false;
}

// rec + memo: works
#include <bits/stdc++.h>
int code(int ind, int sum, int n, int k, vector<int>&ar, vector<vector<int>>&dp) {
	if (sum == k)return 1;
	if (sum > k)return 0;
	if (ind == n)return 0;

	if (dp[ind + 1][k - sum] != -1)return dp[ind + 1][k - sum];
	int f1 = code(ind + 1, sum + ar[ind], n, k, ar, dp);
	if (f1 == 1) { dp[ind + 1][k - sum] = 1; return 1;}
	int f2 = code(ind + 1, sum, n, k, ar, dp);
	if (f2 == 1) {dp[ind + 1][k - sum] = 1; return 1;}

	return dp[ind + 1][k - sum] = 0;
}
bool subsetSumToK(int n, int k, vector<int> &ar) {
	// Write your code here
	vector < vector < int>>dp(n + 1, vector<int>(k + 1, -1));
	if (code(0, 0, n, k, ar, dp))return true; else return false;
}
// bottom up soln: works

#include <bits/stdc++.h>
bool code(int n, int k, vector<int>&ar, vector<vector<bool>>&dp) {
	for (int i = 1; i <= k; i++)dp[0][i] = false;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (dp[i - 1][j])dp[i][j] = true;
			else {
				if ( (j - ar[i - 1]) >= 0)dp[i][j] = dp[i - 1][j - ar[i - 1]];
				else dp[i][j] = false;
			}
		}
	} return dp[n][k];
}
bool subsetSumToK(int n, int k, vector<int> &ar) {
	// Write your code here.
	vector<vector<bool>>dp(n + 1, vector<bool>(k + 1, true));
	return code(n, k, ar, dp);
}