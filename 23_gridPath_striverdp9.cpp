// works for 5/11

int code(int r, int c, int m, int n, vector<vector<int>>&ar) {
	if (r == m && c == n)return 1;
	if (r > m || c > n)return 0;
	if (ar[r - 1][c - 1] == -1)return 0;
	return code(r, c + 1, m, n, ar) + code(r + 1, c, m, n, ar);
}
int mazeObstacles(int n, int m, vector< vector< int> > &ar) {
	// Write your code here
	int temp = m; m = n; n = temp;// now m contains rows , n contains colms
	return code(1, 1, m, n, ar);
}

// now rec + memo : works
const int M = 1e9 + 7;
int code(int r, int c, int m, int n, vector<vector<int>>&ar, vector<vector<int>>&dp) {
	if (r == m && c == n)return 1;
	if (r > m || c > n)return 0;
	if (ar[r - 1][c - 1] == -1)return 0;
	if (dp[r - 1][c - 1] != -1)return dp[r - 1][c - 1];
	return dp[r - 1][c - 1] = (code(r, c + 1, m, n, ar, dp) + code(r + 1, c, m, n, ar, dp)) % M;
}
int mazeObstacles(int n, int m, vector< vector< int> > &ar) {
	// Write your code here
	int temp = m; m = n; n = temp;// now m contains rows , n contains colms
	vector<vector<int>>dp(m, vector<int>(n, -1));
	return code(1, 1, m, n, ar, dp);
}
// bottom up soln: works
const int M = 1e9 + 7;
int mazeObstacles(int n, int m, vector< vector< int> > &ar) {
	// Write your code here
	int temp = m; m = n; n = temp;// now m contains rows , n contains colms

	vector<vector<int>>dp(m, vector<int>(n, 0));
	dp[0][0] = 1;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (ar[i][j] == 0) {
				if ( (i - 1 >= 0))dp[i][j] = (dp[i][j] + dp[i - 1][j]) % M;
				if ( (j - 1) >= 0)dp[i][j] = (dp[i][j] + dp[i][j - 1]) % M;
			} else dp[i][j] = 0;
		}
	} return dp[m - 1][n - 1];
}