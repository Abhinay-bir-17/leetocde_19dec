// recursion: works
#include <bits/stdc++.h>
int code(int r, int c, int n, vector<vector<int>>&ar) {
	if (r == n)return ar[r - 1][c - 1];
	return ar[r - 1][c - 1] + min( code(r + 1, c, n, ar) , code(r + 1, c + 1, n, ar));
}
int minimumPathSum(vector<vector<int>>& ar, int n) {
	// Write your code here.
	return code(1, 1, n, ar);
}

// rec  +  memo
#include <bits/stdc++.h>
int code(int r, int c, int n, vector<vector<int>>&ar, vector<vector<int>>&dp) {

	if (r == n)return ar[r - 1][c - 1];
	if (dp[r - 1][c - 1] != -1)return dp[r - 1][c - 1];
	return dp[r - 1][c - 1] = ar[r - 1][c - 1] + min( code(r + 1, c, n, ar, dp) , code(r + 1, c + 1, n, ar, dp));
}
int minimumPathSum(vector<vector<int>>& ar, int n) {
	// Write your code here.
	vector<vector<int>>dp(n, vector<int>(n, -1));
	return code(1, 1, n, ar, dp);
}
// bottom up
