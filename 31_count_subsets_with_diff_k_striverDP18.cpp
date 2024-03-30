// rec: works for 5/11 test cases
#include <bits/stdc++.h>
int code(int n, int d, vector<int>&ar, int ind, int aux_sum, int k) {
	if (ind == n) {
		if (aux_sum == k)return 1;
		return 0;
	}
	if (aux_sum > k)return 0;
	return (code(n, d, ar, ind + 1, aux_sum + ar[ind], k)
	        + code(n, d, ar, ind + 1, aux_sum, k));
}
int countPartitions(int n, int d, vector<int> &ar) {
	// Write your code here.
	//          n,d,ar,ind,aux_sum, totSum
	int totSum = 0; for (int i = 0; i < n; i++)totSum += ar[i];
	if (totSum & 1) {
		if (d % 2 == 0)return 0;
	} else {
		if (d & 1)return 0;
	}
	int k =  (totSum + d) / 2;

	if (d > totSum)return 0;
	return code(n, d, ar, 0, 0, k);
}
//  rec + memo: works
const int M = 1e9 + 7;
int code(int n, int d, vector<int>ar, int ind, int aux_sum, int k, vector < vector< int>>&dp) {
	if (ind == n) {
		if (aux_sum == k)return 1; return 0;
	}
	if (aux_sum > k)return 0;
	if (dp[ind + 1][k - aux_sum] != -1)return dp[ind + 1][k - aux_sum];
	int pick = code(n, d, ar, ind + 1, aux_sum + ar[ind], k, dp);
	int notpick = code(n, d, ar, ind + 1, aux_sum, k, dp);
	dp[ind + 1][k - aux_sum] = (pick + notpick) % M;
	return dp[ind + 1][k - aux_sum];
}
#include <bits/stdc++.h>
int countPartitions(int n, int d, vector<int> &ar) {
	// Write your code here.

	int totSum = 0; for (int i = 0; i < n; i++)totSum += ar[i];
	if (totSum & 1) {
		if (d % 2 == 0)return 0;
	} else {
		if (d & 1)return 0;
	}
	int k =  (totSum + d) / 2;

	if (d > totSum)return 0; vector<vector<int>>dp(n + 1, vector<int>(k + 1, -1));
	return code(n, d, ar, 0, 0, k, dp);

}
// bottom up : similar to count subsets with sum k