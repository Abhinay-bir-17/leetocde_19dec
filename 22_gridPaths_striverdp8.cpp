/*only wrote bottom up solution last
time,  hence this time we will code all 3 approaches */

// rec : 9/12 test cases
#include <bits/stdc++.h>
int code(int r, int c, int m, int n) {
	if (r == m && c == n)return 1;
	if (r == (m + 1) || (c == (n + 1)))return 0;

	return code( r + 1, c, m, n) + code(r, c + 1, m, n);
}
int uniquePaths(int m, int n) {
	// Write your code here.
	return code(1, 1, m, n);


}

// rec + memo : works
#include <bits/stdc++.h>
int code(int r, int c, int m, int n, vector<vector<int>>&dp) {
	if (r == m && c == n)return 1;
	if (r == (m + 1) || (c == (n + 1)))return 0;
	if (dp[r][c] != -1)return dp[r][c];
	return dp[r][c] = code( r + 1, c, m, n, dp) + code(r, c + 1, m, n, dp);
}
int uniquePaths(int m, int n) {
	// Write your code here.
	vector<vector<int>>dp(m + 1, vector<int>(n + 1, -1));
	return code(1, 1, m, n, dp);
}

// bottom up: gives correct answer
#include <bits/stdc++.h>
int uniquePaths(int m, int n) {
	// Write your code here abhinay bir okay bottom up
	vector<vector<int>>dp(m + 1, vector<int>(n + 1, 0));
	dp[1][1] = 1 ;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if ( (j - 1) >= 1) dp[i][j] += dp[i][j - 1];
			if ( (i - 1) >= 1)dp[i][j] += dp[i - 1][j];
		}
	} return dp[m][n];
}
