// recursion, works for 3/10 cases
#include <bits/stdc++.h>
int code(int r, int c, int m, int n, vector<vector<int>>&ar) {
	if ( r > m ||  c > n)return INT_MAX;
	if (r == m && c == n)return ar[r - 1][c - 1];
	return  ar[r - 1][c - 1] + min( code(r + 1, c, m, n, ar) , code(r, c + 1, m, n, ar));
}
int minSumPath(vector<vector<int>> &ar) {
	// Write your code here.
	int  m = ar.size(); int n = ar[0].size();
	return code(1, 1, m, n, ar);


}

// now rec + memo: works
#include <bits/stdc++.h>
int code(int r, int c, int m, int n, vector<vector<int>>&ar, vector<vector<int>>&dp) {
	if ( r > m ||  c > n)return INT_MAX;
	if (r == m && c == n)return ar[r - 1][c - 1];
	if (dp[r - 1][c - 1] != -1)return dp[r - 1][c - 1];
	return  dp[r - 1][c - 1] = ar[r - 1][c - 1] + min( code(r + 1, c, m, n, ar, dp) , code(r, c + 1, m, n, ar, dp));
}
int minSumPath(vector<vector<int>> &ar) {
	// Write your code here.
	int  m = ar.size(); int n = ar[0].size();
	vector<vector<int>>dp(m,  vector<int>(n, -1));
	return code(1, 1, m, n, ar, dp);
}

// now bottom up soln: works
#include <bits/stdc++.h>
int minSumPath(vector<vector<int>> &ar) {
	// Write your code here.
	int  m = ar.size(); int n = ar[0].size();
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if ( (i - 1) >= 0 &&  (j - 1) >= 0)ar[i][j] += min(ar[i - 1][j], ar[i][j - 1]);
			else if ( (i - 1) >= 0)ar[i][j] += ar[i - 1][j];
			else ar[i][j] += ar[i][j - 1];
		}
	}	return ar[m - 1][n - 1];
}


