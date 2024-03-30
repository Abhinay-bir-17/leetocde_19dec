// recursion works for 4/10 cases
#include <bits/stdc++.h>
int code(int r, int c, int m, int n, vector<vector<int>>&ar) {
	if (c < 1 ||   c > n)return INT_MIN;
	if (r == m)return ar[r - 1][c - 1];
	if (r > m)return 0; // for test cases with 1 row: -5 -10 -9 -4
	return ar[r - 1][c - 1] +
	       max(max(
	               code(r + 1, c - 1, m, n, ar), code(r + 1, c, m, n, ar))
	           , code(r + 1, c + 1, m, n, ar));
}
int getMaxPathSum(vector<vector<int>> &ar)
{
	//  Write your code here.
	int m = ar.size();
	int n = ar[0].size();
	if (m == 1 && n == 1)return ar[0][0];
	int ans = INT_MIN;
	for (int i = 1; i <= n; i++) {
		int a = code(2, i - 1, m, n, ar);
		int b = code(2, i, m, n, ar);
		int c = code(2, i + 1, m, n, ar);
		ans = max(ans, ar[0][i - 1] +  max(max(a, b), c));
	} return ans;
}
// now rec+ memo
#include <bits/stdc++.h>
int code(int r, int c, int m, int n, vector<vector<int>>&ar, vector<vector<int>>&dp) {
	if (c < 1 ||   c > n)return INT_MIN;
	if (r == m)return ar[r - 1][c - 1];
	if (r > m)return 0; // for test cases with 1 row: -5 -10 -9 -4
	if (dp[r - 1][c - 1] != -1)return dp[r - 1][c - 1];
	return dp[r - 1][c - 1] = ar[r - 1][c - 1] +
	                          max(max(
	                                  code(r + 1, c - 1, m, n, ar, dp), code(r + 1, c, m, n, ar, dp))
	                              , code(r + 1, c + 1, m, n, ar, dp));
}
int getMaxPathSum(vector<vector<int>> &ar)
{
	//  Write your code here.
	int m = ar.size();
	int n = ar[0].size(); vector<vector<int>>dp(m, vector<int>(n, -1));
	if (m == 1 && n == 1)return ar[0][0];
	int ans = INT_MIN;
	for (int i = 1; i <= n; i++) {
		int a = code(2, i - 1, m, n, ar, dp);
		int b = code(2, i, m, n, ar, dp);
		int c = code(2, i + 1, m, n, ar, dp);
		ans = max(ans, ar[0][i - 1] +  max(max(a, b), c));
	} return ans;
}
// bottom up approach:
